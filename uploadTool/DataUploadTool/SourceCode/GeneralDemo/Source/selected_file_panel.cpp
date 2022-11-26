#include "selected_file_panel.h"


#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif


namespace DataUploadTool {
	SelectedFilePanel::SelectedFilePanel(QWidget *parent, QString strFilter, QString strTitleBtn)
		: Panel(parent)
		, m_strNameFilter(strFilter)
		, m_strTitleName(strTitleBtn)
	{
		this->resize(840, 420);

		m_splitterH = new QSplitter();
		m_splitterH->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
		m_splitterH->setOrientation(Qt::Horizontal);
		m_splitterH->setHandleWidth(1);
		m_splitterH->setStyleSheet("QSplitter::handle { background-color: red }"); //设置分界线的样式

		this->initTitleWidget();
		this->initCenterWidget();
	
		m_splitterH->addWidget(m_topWidget);
	

		QVBoxLayout *main_layout = new QVBoxLayout();
		main_layout->addWidget(m_splitterH);
		//main_layout->addStretch();
		main_layout->addWidget(m_centerWidget);
		main_layout->setSpacing(5);
		main_layout->setContentsMargins(5, 5, 5, 5);

		this->setLayout(main_layout);
		
	}

	void SelectedFilePanel::initTitleWidget()
	{
		m_topWidget = new QWidget(this);
		m_topWidget->setFixedHeight(30);
		m_topWidget->setStyleSheet("background-color:rgb(150,147,88);");

		m_addButton = new QPushButton();
		m_addButton->setFixedSize(80, 25);
		m_addButton->setObjectName("blueButton");
		m_addButton->setCursor(Qt::PointingHandCursor);

		m_addButton->setText(m_strTitleName);

		title_layout = new QHBoxLayout();
		title_layout->addWidget(m_addButton, 0, Qt::AlignHCenter);
		title_layout->setSpacing(5);
		title_layout->setContentsMargins(0, 0, 0, 0);
		m_topWidget->setLayout(title_layout);

		connect(m_addButton, SIGNAL(clicked()), this, SLOT(addFileSlot()));
	}

	void SelectedFilePanel::initCenterWidget()
	{
		m_centerWidget = new QListWidget(this);
		m_centerWidget->setGridSize(QSize(200, 160));
		m_centerWidget->setWrapping(true);//自动换行
		m_centerWidget->setFlow(QListView::LeftToRight);
		m_centerWidget->setSpacing(10);
		m_centerWidget->setStyleSheet("QListWidget{border:1px solid gray; color:black; }"
			"QListWidget::Item{padding-top:0px; padding-bottom:0px; }"
			"QListWidget::Item:hover{background:skyblue; }"
			"QListWidget::item:selected{background:lightgray; color:red; }"
			"QListWidget::item:selected:!active{border-width:0px; background:lightgreen; }"
		);
		
	}

	void SelectedFilePanel::showCenter()
	{
		//删除之前的窗口
		const int iEnd = m_centerWidget->count();
		for (int i = 0; i < iEnd; i++)
		{
			QListWidgetItem *item = m_centerWidget->takeItem(0); //这里是0，不是i，因为每移除一个item都会导致每个item的row发生变化
			delete item;
			
		}
		m_changeFileList.clear();

		FfmpegCmd ffmpeg;
		ffmpeg.m_videoStatueMap.clear();

		const int iCount = m_fileList.size();		
		for (int i = 0; i < iCount; i++)
		{
			ChangeFileWidget *changeFileWidget = new ChangeFileWidget();
			m_changeFileList.append(changeFileWidget);
			
			connect(changeFileWidget, SIGNAL(deleteFileSignal()), this, SLOT(deleteFileSlot()));
			QListWidgetItem *item = new QListWidgetItem();
			item->setSizeHint(QSize(200, 150));
			m_changeFileList.at(i)->showChangeFile(m_fileList[i], tip_list[i], item);	
			m_centerWidget->addItem(item);
			m_centerWidget->setItemWidget(item, changeFileWidget);

		}

	}
	   
	void SelectedFilePanel::deleteFileSlot()
	{
		QObject *object = QObject::sender();
		ChangeFileWidget *change_file_widget = qobject_cast<ChangeFileWidget *>(object);
		QString strFileName = change_file_widget->m_strUploadFileName;
		//删除本地文件不发信号
		QFileInfo info(strFileName);
		if (!info.exists())
		{			
			emit deleteFileNameSignal(info.fileName());
		}
		else
		{
			////本地文件立马删除，更新界面
			tip_list.removeOne(info.fileName());
			m_fileList.removeOne(strFileName);
			m_changeFileList.removeOne(change_file_widget);
			m_centerWidget->takeItem(m_centerWidget->row(change_file_widget->m_widgetItem));
			m_changeFileList.removeOne(change_file_widget);
			delete change_file_widget;

			update();
		}		
	}

	void SelectedFilePanel::deleteFileWidgetByFileName(const QString &strName)
	{
		////删除后台文件，更新界面
		const int iCount = m_changeFileList.size();
		for (int i = 0; i < iCount; ++i)
		{
			QFileInfo info(m_changeFileList[i]->m_strUploadFileName);
			QString strDeleteName = info.fileName();
			if (strName == strDeleteName)
			{				
				tip_list.removeOne(strDeleteName);
				m_fileList.removeOne(m_changeFileList[i]->m_strUploadFileName);
							
				m_centerWidget->takeItem(m_centerWidget->row(m_changeFileList[i]->m_widgetItem));
				ChangeFileWidget *wgt = m_changeFileList[i];
				m_changeFileList.removeOne(wgt);
				delete wgt;

				update();

				break;
			}
		}
		
	}

	void SelectedFilePanel::deleteLocalFileWidgetByFileName(const QString &strName)
	{
		////删除本地文件，更新界面
		const int iCount = m_changeFileList.size();
		for (int i = 0; i < iCount; ++i)
		{			
			QString strDeleteName = m_changeFileList[i]->m_strUploadFileName;
			if (strName == strDeleteName)
			{
				QFileInfo info(strName);
				tip_list.removeOne(info.fileName());
				m_fileList.removeOne(strName);

				m_centerWidget->takeItem(m_centerWidget->row(m_changeFileList[i]->m_widgetItem));
				ChangeFileWidget *wgt = m_changeFileList[i];
				m_changeFileList.removeOne(wgt);
				delete wgt;

				//update();

				break;
			}
		}

	}

	void SelectedFilePanel::addFileSlot()
	{
		QString defaultPath = DUSettings::settings()->lastImportFolderPath->get().toString();
		if (defaultPath.isDetached())
			defaultPath = DUSettings::settings()->userImageDirectory();

		QStringList filePathLists;
		filePathLists.clear();
		QStringList filePaths = QFileDialog::getOpenFileNames(this, tr("選擇檔"),
			defaultPath, m_strNameFilter);

		QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
		QApplication::processEvents();

		for (int i = 0; i < filePaths.size(); i++) {
			QString strPath = filePaths[i];
			//单个文件路径
			if (strPath.length() > 0)
			{
				QFileInfo file = QFileInfo(strPath);
				DUSettings::settings()->lastImportFolderPath->set(QVariant(file.absolutePath()));
				filePathLists.append(strPath);
			}
		}
		
		addToFilePanel(filePathLists, true);

		QApplication::restoreOverrideCursor();
	}

	void SelectedFilePanel::addToFilePanel(const QStringList &urls, bool bLocal)
	{
		//添加本地文件不清空
		if (!bLocal)
		{
			m_fileList.clear();
			tip_list.clear();
		}


		if (0 != urls.size())
		{
			for (int i = 0; i < urls.size(); ++i)
			{
				if (!bLocal)
				{
					m_fileList.push_back(CLOUD_IP + urls[i]);
				}
				else
				{
					m_fileList.push_back(urls[i]);
				}
				QFileInfo fileinfo(urls[i]);
				//文件名
				tip_list.push_back(fileinfo.fileName());
			}			
		}		

		showCenter();
		update();
	}

	void SelectedFilePanel::cleanPanel()
	{
		m_fileList.clear();
		tip_list.clear();

		showCenter();
	}

	void SelectedFilePanel::refreshPanelStatus(const QString &strFileName, const QString &strStatusIcon)
	{
		const int iCount = m_changeFileList.size();
		for (int i = 0; i < iCount; ++i)
		{
			if (strFileName == m_changeFileList[i]->m_strUploadFileName)
			{
				m_changeFileList[i]->showUploadStatus(strStatusIcon);
				break;
			}
		}
	}

	void SelectedFilePanel::setUploadFileName(const QString &strCloudName, const QString &strName)
	{
		const int iCount = m_changeFileList.size();
		for (int i = 0; i < iCount; ++i)
		{
			QFileInfo info(m_changeFileList[i]->m_strUploadFileName);
			QString strUploadName = info.fileName();
			if (strName == strUploadName)
			{				
				QString strLocalPath = m_changeFileList[i]->m_strUploadFileName;
				m_fileList.removeOne(strLocalPath);
				m_fileList.push_back(strCloudName);
				m_changeFileList[i]->m_strUploadFileName = strCloudName;

				break;
			}
			
		}

	}

	void SelectedFilePanel::paintEvent(QPaintEvent *event)
	{		
		Q_UNUSED(event);

		QPainter p(this);
		p.setPen(Qt::NoPen);
		p.setBrush(Qt::white);
		p.drawRect(rect());
	}
	

}