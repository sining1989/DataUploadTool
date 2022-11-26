#ifndef DATA_UPLOAD_CHANGE_SKIN_WIDGET_H
#define DATA_UPLOAD_CHANGE_SKIN_WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QMouseEvent>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPainter>
#include <QPen>
#include <QListWidgetItem>
#include <QFileDialog>
#include "push_button.h"
#include "ffmpegcmd.h"

namespace DataUploadTool
{
	class ChangeFileWidget : public QWidget
	{
		Q_OBJECT

	public:
		explicit ChangeFileWidget(QWidget *parent = 0);
		~ChangeFileWidget();

		void setUploadFileName(const QString &strName);
		void showUploadStatus(const QString &strStatusIcon);

	protected:
		void mousePressEvent(QMouseEvent *event);
		void mouseDoubleClickEvent(QMouseEvent *event);
		void mouseReleaseEvent(QMouseEvent *event);
		void enterEvent(QEvent *event);
		void leaveEvent(QEvent *event);
		void paintEvent(QPaintEvent *event);

	signals:
		void deleteFileSignal();

	public slots:
		void showChangeFile(const QString &file_name, const QString & strFileName, QListWidgetItem *item);

	private slots:
		void deleteFileSlot();

	public:
		QListWidgetItem *m_widgetItem;
		QString m_strUploadFileName;


	private:
		QLabel *m_fileLabel;
		QLabel *m_fileNameLabel; //显示名称
		QLabel *m_uploadStatusLabel;

		PushButton *m_deleteBtn; //删除
		
		bool m_mousePress;
		bool m_mouseEnter;
		FfmpegCmd m_ffmpeg;
	};
} // namespace DataUploadTool
#endif  //DATA_UPLOAD_CHANGE_SKIN_WIDGET_H