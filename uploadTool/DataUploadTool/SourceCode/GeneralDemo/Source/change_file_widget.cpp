#include "change_file_widget.h"
#include <QDesktopServices>
#include "windows.h"
#include "mmsystem.h"

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif


namespace DataUploadTool
{	
	ChangeFileWidget::ChangeFileWidget(QWidget *parent)
		: QWidget(parent)
		, m_widgetItem()
	{
		this->setFixedSize(200, 150);
		m_mousePress = false;
		m_mouseEnter = false;

		m_fileLabel = new QLabel();
		m_fileNameLabel = new QLabel();
		m_uploadStatusLabel = new QLabel();

		m_fileLabel->setScaledContents(true);
		m_fileLabel->setFixedSize(180, 110);

		QVBoxLayout *layout = new QVBoxLayout();
		layout->addWidget(m_fileLabel, 0, Qt::AlignCenter);
		layout->addWidget(m_uploadStatusLabel, 0, Qt::AlignVCenter);
		layout->addWidget(m_fileNameLabel, 0, Qt::AlignCenter);
		layout->setSpacing(0);
		layout->setContentsMargins(10, 10, 10, 10);

		this->setLayout(layout);

		m_deleteBtn = new PushButton(this);
		this->setCursor(Qt::PointingHandCursor);
		m_deleteBtn->setPicName(":/image/close");
		m_deleteBtn->setGeometry(160, 10, 20, 20);
		connect(m_deleteBtn, SIGNAL(clicked()), this, SLOT(deleteFileSlot()));

		//GetHighResolutionIcon("");
	}

	ChangeFileWidget::~ChangeFileWidget()
	{

	}

	void ChangeFileWidget::setUploadFileName(const QString &strName)
	{
		this->m_strUploadFileName = strName;
	}

	void ChangeFileWidget::showChangeFile(const QString &file_name, const QString & strFileName, QListWidgetItem *item)
	{
		this->m_strUploadFileName = file_name;
		QString strDefaultIcon = file_name;
		QFileInfo info(file_name);
		if (!info.exists()) //给后台获取的文件添加默认图标
		{			
			if ("jpg" == info.suffix() || "jpeg" == info.suffix() || "png" == info.suffix())
				strDefaultIcon = ":/image/picture.png";
			if ("mp4" == info.suffix())
				strDefaultIcon = ":/image/video.png";
			if ("pdf" == info.suffix())
				strDefaultIcon = ":/image/pdf.png";
			showUploadStatus(":/image/cloud.png");
		}
		else
		{
			//获取video与pdf的缩略图
			if ("mp4" == info.suffix())
			{
				m_ffmpeg.videoToBitmap(file_name);
				
				QString strPath = file_name;
				strPath = strPath.replace(".mp4", ".jpg");
				strDefaultIcon = ":/image/video.png";
				while (true)
				{
					if (m_ffmpeg.m_videoStatueMap[strPath])
					{
						QFileInfo info(strPath);
						if (info.exists())
						{
							strDefaultIcon = strPath;
							break;
						}							
					}
				}				
			}
				
			if ("pdf" == info.suffix())
				strDefaultIcon = ":/image/pdf.png";
		}

		QPixmap pixmap(strDefaultIcon);
		this->m_fileLabel->setPixmap(pixmap);

		//更改名称
		this->m_fileNameLabel->setText(strFileName);
		this->m_widgetItem = item;
	}

	void ChangeFileWidget::showUploadStatus(const QString &strStatusIcon)
	{
		QPixmap pixmap(strStatusIcon);
		this->m_uploadStatusLabel->setPixmap(pixmap);
	}

	void ChangeFileWidget::deleteFileSlot()
	{
		emit deleteFileSignal();
	}

	void ChangeFileWidget::paintEvent(QPaintEvent *)
	{
		if (m_mouseEnter)
		{
			//绘制边框 
			QPainter painter(this);
			QPen pen(QColor(210, 225, 230));
			painter.setPen(pen);
			painter.drawRoundRect(0, 0, this->width() - 1, this->height() - 1, 5, 5);
		}
	}

	void ChangeFileWidget::mousePressEvent(QMouseEvent * event)
	{
		//只能是鼠标左键
		if (event->button() == Qt::LeftButton)
		{
			m_mousePress = true;
		}
	}

	void ChangeFileWidget::mouseDoubleClickEvent(QMouseEvent *event)
	{
		if ((this->rect()).contains(event->pos()))
		{
			QDesktopServices::openUrl(QUrl::fromLocalFile(m_strUploadFileName));
		}
	}
	
	void ChangeFileWidget::mouseReleaseEvent(QMouseEvent *event)
	{
		m_mousePress = false;
	}

	void ChangeFileWidget::enterEvent(QEvent *)
	{
		m_mouseEnter = true;
		update();
	}

	void ChangeFileWidget::leaveEvent(QEvent *)
	{
		m_mouseEnter = false;
		update();
	}
}