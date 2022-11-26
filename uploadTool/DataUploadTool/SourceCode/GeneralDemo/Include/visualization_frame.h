#ifndef DATA_UPLOAD_VISUALOZATION_FRAME_H
#define DATA_UPLOAD_VISUALIZATION_FRAME_H

/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QListView>
#include <QProgressBar>
#include <QPushButton>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QToolButton>
#include <deque>
#include <QListWidget>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QHttpMultiPart>
#include <QStandardItem>
#include <iostream>
#include <QtDebug>
#include <QSettings>
#include <wchar.h>
#include <QAction>
#include <QShortcut>
#include <QApplication>
#include <QCloseEvent>
#include <QDesktopServices>
#include <QDockWidget>
#include <QDir>
#include <QFileDialog>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QUrl>
#include <QStatusBar>
#include <QTabBar>
#include <QObject>
#include <QTimer>
#include <QNetworkReply>

#include "widget_geometry_change_detector.h"
#include "common_config.h"
#include "configinfo.h"

#include "selected_file_panel.h"
#include "selected_param_panel.h"
/*****************************************************************************
** Namespace
*****************************************************************************/

namespace DataUploadTool 
{

	class QReplyTimeout : public QObject {

		Q_OBJECT

	public:
		QReplyTimeout(QNetworkReply *reply, const int timeout) : QObject(reply) {
			Q_ASSERT(reply);
			if (reply && reply->isRunning()) {  // 启动单次定时器
				QTimer::singleShot(timeout, this, SLOT(onTimeout()));
			}
		}

	signals:
		void timeout();  // 超时信号 - 供进一步处理

	private slots:
		void onTimeout() {  // 处理超时
			QNetworkReply *reply = static_cast<QNetworkReply*>(parent());
			if (reply->isRunning()) {
				reply->abort();
				reply->deleteLater();
				emit timeout();
			}
		}
	};
	/*****************************************************************************
	** Interface [MainWindow]
	*****************************************************************************/
	/**
	 * @brief Qt central, all operations relating to the view part here.
	 */
	class VisualizationFrame : public QMainWindow
	{
	Q_OBJECT

	public:
		VisualizationFrame(QWidget *parent = 0, Qt::WindowFlags flags = 0);
		~VisualizationFrame();

		void initWindow();
		void initConnect();


	private:
		void createStatusBar();
		void translateLanguage();
		/*!
		 * \brief Saves the position and window states
		 */
		void writeSettings();
		/*!
		 * \brief Reeads the position and window states
		 */
		void readSettings();
		

	protected:
		void oneButtonMessageBox(QString windowTitle, QString text, QMessageBox::Icon type);

		virtual void keyPressEvent(QKeyEvent *event);
		virtual void closeEvent(QCloseEvent *event);
		bool yesNoQuestion(QString windowTitle, QString text);
		void warning(QString windowTitle, QString text);
		void information(QString windowTitle, QString text);

	private:
		void initUI();
		void uploadFileByPanel(SelectedFilePanel *panel);
		void updateUIParam(ISSUE_DESCRIBE data);
		void uploadParam(const ISSUE_DESCRIBE &data);
		void uploadFile(const QString &strIssueId, const QString &strFilePath);
		void updateIssueListUI(const std::vector<QString> &vecIssueId);
		void getAllIssueId();
		void getParamByIssueID(const QString &strIssueId);
		void getPictureFileByIssueID(const QString &strIssueId);
		void getVideoFileByIssueID(const QString &strIssueId);
		void get8DFileByIssueID(const QString &strIssueId);
		void deleteAllDataByIssueID(const QString &strIssueId);
		void deleteFileByIssueID(const QString &strIssueId, const QString &strFileName);
		QStringList parseResposeToFile(QNetworkReply*reply);
		QByteArray getJsonObjectFromString(const QString &strJson, const QString &strType);
		QByteArray getJsonObjectFromFileName(const QString &strJson, const QString &strFileName);
		void StructToJSon(const ISSUE_DESCRIBE &data, QByteArray &jsonArray);
		bool parserJsonToStruct(const QString &strRespose, ISSUE_DESCRIBE &data);		
		bool parserJsonToIssueList(const QString &strRespose, std::vector<QString> &list);
		bool parserJsonToFileData(const QString &strRespose, QStringList &data);
		QString jsonValueToString(QJsonObject obj, const QString &strName);
		bool parserJsonToBool(const QString &strRespose, bool &bFlag);
		bool parseHttpRespose(QString text, CResult& result);
		bool parseHttpResposeData(QString text, QString &strFileName, CResult& result);
		void refreshPanel(QNetworkReply*reply, SelectedFilePanel *panel);
		QByteArray getFileMd5(const QString &filePath);

	signals:
		void closeEvent_Signal(QCloseEvent *event);

	public Q_SLOTS:
		void commitSlot();

	protected Q_SLOTS:
		void onDockPanelChange();
			   
	private Q_SLOTS:	
		void refreshIssueList();
		void itemClicked(QModelIndex index);
		void deleteFileByNameSlot(QString strFileName);
		void showContextMenuSlot(const QPoint& pos);
		void setDisplayConfigModified();
		void showIssueWidget();
		void getPostIssueParamResposeSlot(QNetworkReply*reply);
		void getPostIssueDataResposeSlot(QNetworkReply*reply);
		void getGetAllIssueIdResposeSlot(QNetworkReply*reply);
		void getGetParamResposeSlot(QNetworkReply*reply);
		void getGetPictureResposeSlot(QNetworkReply*reply);
		void getGetVideoResposeSlot(QNetworkReply*reply);
		void getGet8DFileResposeSlot(QNetworkReply*reply);
		void deleteAllDataResposeSlot(QNetworkReply*reply);
		void deleteFileResposeSlot(QNetworkReply*reply);
		void requestFinishedSlot();
		void uploadProgressSlot(qint64 bytesSent, qint64 bytesTotal);
		void getParamErrorSlot(QNetworkReply::NetworkError errorCode); 
		void getAllIssueIdErrorSlot(QNetworkReply::NetworkError errorCode);
		void deleteAllDataByIssueIDSlot();

	protected:
		WidgetGeometryChangeDetector* geom_change_detector_;
			

	private:
		QWidget *m_centralWidget;
		QWidget *m_leftWidget;
		QWidget *m_rightWidget;
		QPushButton *m_addIssueBtn;
		QLabel *m_issueRecordLabel;
		QListView *m_issueList;
		QPushButton *m_refreshBtn;
		QPushButton *m_commitBtn;

		SelectedParamPanel *m_selectParamPanel;
		SelectedFilePanel *m_selectPicturePanel;
		SelectedFilePanel *m_selectVideoPanel;
		SelectedFilePanel *m_select8DFilePanel;

		QLabel *m_textStatus;
		QLabel *m_strTextStatus;
		QStatusBar* m_statusbar;

		QNetworkAccessManager *m_pPostIssueParamManager;
		QNetworkAccessManager *m_pPostIssueDataManager;
		QNetworkAccessManager *m_pGetAllIssueIDManager;
		QNetworkAccessManager *m_pGetParamManager;
		QNetworkAccessManager *m_pGetPictureManager;
		QNetworkAccessManager *m_pGetVideoManager;
		QNetworkAccessManager *m_pGet8DFileManager;
		QNetworkAccessManager *m_pDeleteAllDataManager;
		QNetworkAccessManager *m_pDeleteFileManager;
		QNetworkReply *m_replyFile;
		QNetworkReply *m_replyGetAllIssueId;
		std::vector<QString> m_vecIssueId;
		QString m_strCurrentIssueId;
		QString m_selectDelFileName;

		QTextEdit *textEdit;
		QListWidget *customerList;
		QListWidget *paragraphsList;
		QMap<QString, SelectedFilePanel *> m_fileUploadStatusMap;
		QMap<QString, QFile *> m_fileHandleMap;
		QMap<QString, bool> m_fileNameMap;
	};

}  // namespace DataUploadTool

#endif // DATA_UPLOAD_VISUALIZATION_FRAME_H
