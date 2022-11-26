#ifndef DATA_UPLOAD_SELECTED_FILE_PANEL_H
#define DATA_UPLOAD_SELECTED_FILE_PANEL_H

#include <QWidget>
#include <QSignalMapper>
#include <QSplitter>
#include <QStandardPaths>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QListWidget>
#include "common.h"
#include "change_file_widget.h"
#include "panel.h"
#include "settings.h"

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

namespace DataUploadTool
{
	class SelectedFilePanel : public Panel
	{
		Q_OBJECT

	public:
		explicit SelectedFilePanel(QWidget *parent = 0, QString strFilter = "", QString strTitleBtn = "");

		void addToFilePanel(const QStringList &urls, bool bLocal = false);
		void cleanPanel();
		void refreshPanelStatus(const QString &strFileName, const QString &strStatusIcon);
		void deleteFileWidgetByFileName(const QString &strName);
		void setUploadFileName(const QString &strCloudName, const QString &strName);
		void deleteLocalFileWidgetByFileName(const QString &strName);
	protected:
		void paintEvent(QPaintEvent *event);

	signals:
		void deleteFileNameSignal(QString strFileName);

	private slots:	
		void deleteFileSlot();
		void addFileSlot();

	private:
		void initTitleWidget();
		void initCenterWidget();
		
		void showCenter();

	public:
		QVector<QString> m_fileList;

	private:
		QWidget *m_topWidget;
		QListWidget *m_centerWidget;
		QWidget *m_bottomWidget;

		QVector<QString> tip_list;
		QSplitter *m_splitterH;
		QHBoxLayout *title_layout;
		QHBoxLayout *bottom_layout;

		QPushButton *m_addButton;
		QString m_strNameFilter;
		QString m_strTitleName;
		
		QList<ChangeFileWidget *> m_changeFileList;

	};
		
} // namespace DataUploadTool
#endif // DATA_UPLOAD_SELECTED_FILE_PANEL_H
