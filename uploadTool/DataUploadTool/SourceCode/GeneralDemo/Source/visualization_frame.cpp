/*****************************************************************************
** Includes
*****************************************************************************/

#include "visualization_frame.h"


/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace DataUploadTool {

	using namespace Qt;

	/*****************************************************************************
	** Implementation [MainWindow]
	*****************************************************************************/
	VisualizationFrame::VisualizationFrame(QWidget *parent, Qt::WindowFlags flags)
		: QMainWindow(parent, flags)
		, m_statusbar(NULL)
		, m_pPostIssueParamManager(NULL)
	    , m_pPostIssueDataManager(NULL)
		, m_pGetAllIssueIDManager(NULL)
		, m_pGetParamManager(NULL)
		, m_pGetPictureManager(NULL)
		, m_pGetVideoManager(NULL)
		, m_pGet8DFileManager(NULL)
		, m_pDeleteAllDataManager(NULL)
		, m_pDeleteFileManager(NULL)
		, m_replyGetAllIssueId(NULL)
		, m_replyFile(NULL)
		, m_strCurrentIssueId("")
		, m_selectDelFileName("")		
		, geom_change_detector_(new WidgetGeometryChangeDetector(this))

	{
		installEventFilter(geom_change_detector_);
		connect(geom_change_detector_, SIGNAL(changed()), this, SLOT(setDisplayConfigModified()));
				
		setWindowIcon(QIcon(":/image/icon.png"));

		createStatusBar();
		initWindow();
		initConnect();
		translateLanguage();		

		readSettings();
		getAllIssueId();

		initUI();


		qDebug(u8"主程序啟動完成");
	}

	VisualizationFrame::~VisualizationFrame()
	{					
		if (NULL != m_pPostIssueParamManager)
		{
			delete m_pPostIssueParamManager;
			m_pPostIssueParamManager = NULL;
		}
		if (NULL != m_pPostIssueDataManager)
		{
			delete m_pPostIssueDataManager;
			m_pPostIssueDataManager = NULL;
		}
		if (NULL != m_pGetAllIssueIDManager)
		{
			delete m_pGetAllIssueIDManager;
			m_pGetAllIssueIDManager = NULL;
		}
		if (NULL != m_pGetParamManager)
		{
			delete m_pGetParamManager;
			m_pGetParamManager = NULL;
		}
		if (NULL != m_pGetPictureManager)
		{
			delete m_pGetPictureManager;
			m_pGetPictureManager = NULL;
		}
		if (NULL != m_pGetVideoManager)
		{
			delete m_pGetVideoManager;
			m_pGetVideoManager = NULL;
		}
		if (NULL != m_pGet8DFileManager)
		{
			delete m_pGet8DFileManager;
			m_pGet8DFileManager = NULL;
		}
		if (NULL != m_pDeleteAllDataManager)
		{
			delete m_pDeleteAllDataManager;
			m_pDeleteAllDataManager = NULL;
		}
		if (NULL != m_pDeleteFileManager)
		{
			delete m_pDeleteFileManager;
			m_pDeleteFileManager = NULL;
		}
		if (NULL != m_statusbar)
		{
			delete m_statusbar;
			m_statusbar = NULL;
		}

		writeSettings();
	}

	void VisualizationFrame::createStatusBar()
	{
		m_textStatus = new QLabel();
		m_strTextStatus = new QLabel();

		statusBar()->addPermanentWidget(m_textStatus, 0);
		statusBar()->addPermanentWidget(m_strTextStatus, 1);
		m_statusbar = statusBar();

	}

	void VisualizationFrame::initWindow()
	{
		//QPixmapCache::setCacheLimit(1024 * 100);

		m_centralWidget = new QWidget(this);
		m_leftWidget = new QWidget(this);
		m_leftWidget->setFixedWidth(200);
		m_rightWidget = new QWidget(this);

		//左边窗口
		m_addIssueBtn = new QPushButton();
		m_addIssueBtn->setFixedSize(120, 25);
		m_addIssueBtn->setObjectName("greenButton");
		connect(m_addIssueBtn, SIGNAL(clicked()), this, SLOT(showIssueWidget()));

		m_issueRecordLabel = new QLabel();
		m_issueList = new QListView();
		m_issueList->setEditTriggers(QAbstractItemView::NoEditTriggers);
		connect(m_issueList, SIGNAL(clicked(QModelIndex)), this, SLOT(itemClicked(QModelIndex)));

		m_refreshBtn = new QPushButton();
		m_refreshBtn->setFixedSize(80, 25);
		m_refreshBtn->setObjectName("blueButton");
		connect(m_refreshBtn, SIGNAL(clicked()), this, SLOT(refreshIssueList()));

		QHBoxLayout *hLayout = new QHBoxLayout();
		hLayout->addStretch();
		hLayout->addWidget(m_addIssueBtn);
		hLayout->addStretch();

		QVBoxLayout *vLayout = new QVBoxLayout();
		vLayout->addWidget(m_issueRecordLabel);
		vLayout->addWidget(m_issueList);
		
		QHBoxLayout *hRefreshLayout = new QHBoxLayout();
		hRefreshLayout->addStretch();
		hRefreshLayout->addWidget(m_refreshBtn);
		hRefreshLayout->addStretch();

		QVBoxLayout* left_layout = new QVBoxLayout();
		left_layout->setSpacing(10);
		left_layout->setMargin(10);
		left_layout->addLayout(hLayout);
		left_layout->addLayout(vLayout);
		left_layout->addLayout(hRefreshLayout);
		m_leftWidget->setLayout(left_layout);			   	

		//右边窗口
		m_selectParamPanel = new SelectedParamPanel(m_rightWidget, ISSUE_PARAM);

		m_selectPicturePanel = new SelectedFilePanel(m_rightWidget, "Image files (*.png *.jpeg *.jpg)", ADD_PICTURE);
		connect(m_selectPicturePanel, SIGNAL(deleteFileNameSignal(QString)), this, SLOT(deleteFileByNameSlot(QString)));

		m_selectVideoPanel = new SelectedFilePanel(m_rightWidget, "Video files (*.mp4)", ADD_VIDEO);
		connect(m_selectVideoPanel, SIGNAL(deleteFileNameSignal(QString)), this, SLOT(deleteFileByNameSlot(QString)));

		m_select8DFilePanel = new SelectedFilePanel(m_rightWidget, "Pdf files (*.pdf)", ADD_8DFILE);
		connect(m_select8DFilePanel, SIGNAL(deleteFileNameSignal(QString)), this, SLOT(deleteFileByNameSlot(QString)));

		m_commitBtn = new QPushButton();
		m_commitBtn->setFixedSize(100, 25);
		m_commitBtn->setObjectName("okButton");
		connect(m_commitBtn, SIGNAL(clicked()), this, SLOT(commitSlot()));

		QGridLayout *gridLayout = new QGridLayout();
		gridLayout->addWidget(m_selectParamPanel, 0, 0, 1, 1);
		gridLayout->addWidget(m_selectPicturePanel, 0, 1, 1, 1);
		gridLayout->addWidget(m_selectVideoPanel, 1, 0, 1, 1);
		gridLayout->addWidget(m_select8DFilePanel, 1, 1, 1, 1);

		QHBoxLayout *hCommitLayout = new QHBoxLayout();
		hCommitLayout->addStretch();
		hCommitLayout->addWidget(m_commitBtn);
		hCommitLayout->addStretch();

		QVBoxLayout* right_layout = new QVBoxLayout();
		right_layout->setSpacing(10);
		right_layout->setMargin(0);
		right_layout->addLayout(gridLayout);
		right_layout->addLayout(hCommitLayout);
		m_rightWidget->setLayout(right_layout);

		QHBoxLayout* central_layout = new QHBoxLayout();
		central_layout->setSpacing(0);
		central_layout->setMargin(0);

		central_layout->addWidget(m_leftWidget);
		central_layout->addWidget(m_rightWidget);
		m_centralWidget->setLayout(central_layout);
		setCentralWidget(m_centralWidget);

		this->installEventFilter(geom_change_detector_);

	}

	void VisualizationFrame::initConnect()
	{
		m_pPostIssueParamManager = new QNetworkAccessManager(this);
		m_pPostIssueDataManager = new QNetworkAccessManager(this);
		m_pGetAllIssueIDManager = new QNetworkAccessManager(this);
		m_pGetParamManager = new QNetworkAccessManager(this);
		m_pGetPictureManager = new QNetworkAccessManager(this);
		m_pGetVideoManager = new QNetworkAccessManager(this);
		m_pGet8DFileManager = new QNetworkAccessManager(this); 
		m_pDeleteAllDataManager = new QNetworkAccessManager(this);
		m_pDeleteFileManager = new QNetworkAccessManager(this);
		connect(m_pPostIssueParamManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getPostIssueParamResposeSlot(QNetworkReply*)));
		connect(m_pPostIssueDataManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getPostIssueDataResposeSlot(QNetworkReply*))); 
		connect(m_pGetAllIssueIDManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getGetAllIssueIdResposeSlot(QNetworkReply*)));
		connect(m_pGetParamManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getGetParamResposeSlot(QNetworkReply*)));
		connect(m_pGetPictureManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getGetPictureResposeSlot(QNetworkReply*)));
		connect(m_pGetVideoManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getGetVideoResposeSlot(QNetworkReply*)));
		connect(m_pGet8DFileManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getGet8DFileResposeSlot(QNetworkReply*)));
		connect(m_pDeleteAllDataManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(deleteAllDataResposeSlot(QNetworkReply*)));
		connect(m_pDeleteFileManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(deleteFileResposeSlot(QNetworkReply*)));
	}

	void VisualizationFrame::initUI()
	{
		if (m_selectParamPanel)
			m_selectParamPanel->initUI();
		if (m_selectPicturePanel)
			m_selectPicturePanel->cleanPanel();
		if (m_selectVideoPanel)
			m_selectVideoPanel->cleanPanel();
		if (m_select8DFilePanel)
			m_select8DFilePanel->cleanPanel();
	
		update();
	}

	void VisualizationFrame::translateLanguage()
	{
		setWindowTitle(APP_NAME);
		
		m_addIssueBtn->setText(ADD_ISSUE_BTN);
		m_issueRecordLabel->setText(ISSUE_RECORD_LABEL);
		m_refreshBtn->setText(REFRESH_BTN);
		m_commitBtn->setText(COMMIT_BTN);

		m_textStatus->setText(STATUS_NAME);
	}

	void VisualizationFrame::writeSettings()
	{
		// saves window positions and states
		QSettings settings("DataUploadTool", "visualizationFrame");

		settings.beginGroup("mainWindow");
		settings.setValue("geometry", saveGeometry());
		settings.setValue("state", saveState());
		settings.endGroup();
	}
	
	void VisualizationFrame::readSettings()
	{
		// reads window positions and states
		QSettings settings("DataUploadTool", "visualizationFrame");

		settings.beginGroup("mainWindow");
		restoreGeometry(settings.value("geometry").toByteArray());
		restoreState(settings.value("state").toByteArray());
		settings.endGroup();
	}


	/*****************************************************************************
	** Implementation [Configuration]
	*****************************************************************************/
	void VisualizationFrame::keyPressEvent(QKeyEvent *event)
	{
		QMainWindow::keyPressEvent(event);
	}

	void VisualizationFrame::closeEvent(QCloseEvent *event)
	{
		event->ignore();
		emit closeEvent_Signal(event);
	}

	bool VisualizationFrame::yesNoQuestion(QString windowTitle, QString text)
	{
		QMessageBox messageBox;
		messageBox.setParent(this);
		messageBox.setWindowTitle(windowTitle);
		messageBox.setText(text);
		QPushButton* yesButton = messageBox.addButton(tr("Yes"), QMessageBox::YesRole);
		messageBox.addButton(tr("No"), QMessageBox::NoRole);
		messageBox.setIcon(QMessageBox::Question);

#ifdef Q_OS_LINUX
		// to avoid to be handled by x11. This allows us to keep to the back all the windows manager stuff like palette, toolbar ...
		messageBox.setWindowFlags(Qt::Dialog | Qt::X11BypassWindowManagerHint);
#else
		messageBox.setWindowFlags(Qt::Dialog);
#endif

		messageBox.exec();
		return messageBox.clickedButton() == yesButton;
	}

	void VisualizationFrame::oneButtonMessageBox(QString windowTitle, QString text, QMessageBox::Icon type)
	{
		QMessageBox messageBox;
		messageBox.setParent(this);
		messageBox.setWindowFlags(Qt::Dialog);
		messageBox.setWindowTitle(windowTitle);
		messageBox.setText(text);
		messageBox.addButton(tr("Ok"), QMessageBox::YesRole);
		messageBox.setIcon(type);
		messageBox.exec();
	}

	void VisualizationFrame::warning(QString windowTitle, QString text)
	{
		oneButtonMessageBox(windowTitle, text, QMessageBox::Warning);
	}

	void VisualizationFrame::information(QString windowTitle, QString text)
	{
		oneButtonMessageBox(windowTitle, text, QMessageBox::Information);
	}


	/*****************************************************************************
	** Implementation [Slots]
	*****************************************************************************/
	void VisualizationFrame::refreshIssueList()
	{
		getAllIssueId();
	}

	void VisualizationFrame::itemClicked(QModelIndex index)
	{
		QString strIssueId = index.data().toString();
		if (!strIssueId.isEmpty())
		{
			m_fileUploadStatusMap.clear();
			getParamByIssueID(strIssueId);
			getPictureFileByIssueID(strIssueId);
			getVideoFileByIssueID(strIssueId);
			get8DFileByIssueID(strIssueId);
		}
		
	}
	
	void VisualizationFrame::setDisplayConfigModified()
	{
		if (!isWindowModified())
		{
			setWindowModified(true);
		}
	}

	void VisualizationFrame::onDockPanelChange()
	{
		QList<QTabBar *> tab_bars = findChildren<QTabBar *>(QString());
		for (QList<QTabBar *>::iterator it = tab_bars.begin(); it != tab_bars.end(); it++)
		{
			(*it)->setElideMode(Qt::ElideNone);
		}
	}

	void VisualizationFrame::showIssueWidget()
	{
		m_fileUploadStatusMap.clear();
		initUI();
	}

	void VisualizationFrame::commitSlot()
	{
		//根据MD5判断，后台与新添加的文件是否有重复的
		//QMap<QByteArray, QString> fileMd5Map;
		//fileMd5Map.clear();
		//const int iMapCount = m_fileUploadStatusMap.count();
		//for (QMap<QString, SelectedFilePanel *>::const_iterator itor = m_fileUploadStatusMap.begin(); itor != m_fileUploadStatusMap.end(); itor++)
		//{
		//	QByteArray md5 = getFileMd5(itor.key());
		//	qDebug() << "fileName: " << itor.key() << " Md5:" << md5.toHex();
		//	fileMd5Map[md5].append(itor.key());
		//}
		qDebug("commit data");
		//m_strTextStatus->setText("commit data");
		m_fileHandleMap.clear();

		m_fileNameMap.clear();
		const int iMapCount = m_fileUploadStatusMap.count();
		for (QMap<QString, SelectedFilePanel *>::const_iterator itor = m_fileUploadStatusMap.begin(); itor != m_fileUploadStatusMap.end(); itor++)
		{
			QString strPath = itor.key();
			QFileInfo info(strPath);
			m_fileNameMap.insert(info.fileName(), true);
		}	
		

		//上传参数
		ISSUE_DESCRIBE data = m_selectParamPanel->getIssueDescribePanelData();
		m_strCurrentIssueId = data.strIssueID;
		if (m_strCurrentIssueId.isEmpty())
		{
			m_strTextStatus->setText(ISSUE_ID_IS_NULL);			
		}
		else
		{
			uploadParam(data);
		}

		//上传图片、视频、8D报告
		uploadFileByPanel(m_selectPicturePanel);
		uploadFileByPanel(m_selectVideoPanel);
		uploadFileByPanel(m_select8DFilePanel);
		
	}

	void VisualizationFrame::uploadFileByPanel(SelectedFilePanel *panel)
	{
		const int iCountFile = panel->m_fileList.size();
		QVector<QString> fileList = panel->m_fileList;
		for (int i = 0; i < iCountFile; ++i)
		{
			//后台文件不上传
			QString strFilePath = fileList[i];
			QFileInfo info(strFilePath);
			if (info.exists())
			{
				//m_fileUploadStatusMap.insert(strFilePath, m_selectPicturePanel);
				//uploadFile(data.strIssueID, strFilePath);
				QString strName = info.fileName();
				if (!m_fileNameMap[strName])
				{
					m_fileUploadStatusMap.insert(strFilePath, m_selectPicturePanel);
					uploadFile(m_strCurrentIssueId, strFilePath);
				}
				else
				{
					//有重复文件					
					m_strTextStatus->setText(QString("%1已存在").arg(strFilePath));
					information("提示", QString("%1已存在").arg(strFilePath));
					panel->deleteLocalFileWidgetByFileName(strFilePath);

				}
				//QByteArray localFile = getFileMd5(strFilePath);
				//if (fileMd5Map[localFile].isEmpty())
				//{
				//	m_fileUploadStatusMap.insert(strFilePath, panel);
				//	uploadFile(data.strIssueID, strFilePath);
				//}
				//else
				//{
				//	//有重复文件
				//	m_strTextStatus->setText(QString("%1已存在").arg(strFilePath));
				//}
			}
		}
	}

	void VisualizationFrame::updateUIParam(ISSUE_DESCRIBE data)
	{
		m_selectParamPanel->updateUI(data);
	}

	void VisualizationFrame::uploadParam(const ISSUE_DESCRIBE &data)
	{
		QByteArray rqByte;
		rqByte.clear();

		//序列化
		StructToJSon(data, rqByte);

		//编辑HTTP头部
		QNetworkRequest request = QNetworkRequest(QUrl(CLOUD_IP+"/TaaS/totalissue/add"));//issue

		request.setRawHeader(QString("Content-Type").toLatin1(), QString("application/json; charset=utf-8").toLatin1());
		request.setRawHeader(QString("Content-Length").toLatin1(), QString::number(rqByte.length()).toLatin1());

		//执行post请求		
		if (m_pPostIssueParamManager)
		{
			QNetworkReply *reply = m_pPostIssueParamManager->post(request, rqByte);
			connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(getParamErrorSlot(QNetworkReply::NetworkError)));
		}
	}


	void VisualizationFrame::uploadFile(const QString &strIssueId, const QString &strFilePath)
	{
		//上传文件内容				
		QFile *uploadFile = new QFile(strFilePath);
		m_fileHandleMap.insert(strFilePath, uploadFile);
		QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);

		QHttpPart md5Part;
		md5Part.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant(QString("form-data; name=\"%1\"").arg("issueId")));
		md5Part.setBody(strIssueId.toLatin1());
		multiPart->append(md5Part);

		QHttpPart fileNamePart;
		fileNamePart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant(QString("form-data; name=\"%1\"").arg("fileName")));
		fileNamePart.setBody(QString(uploadFile->fileName()).toLatin1());
		multiPart->append(fileNamePart);


		QHttpPart filePart;
		filePart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant(QString("form-data; name=\"%1\"; filename=\"%2\"").arg("apifiles1").arg(uploadFile->fileName())));
		if (!uploadFile->open(QIODevice::ReadOnly))
		{
			qDebug("QIODevice::ReadOnly failed");
			m_strTextStatus->setText("QIODevice::ReadOnly failed");
			return;
		}
		filePart.setBodyDevice(uploadFile);
		uploadFile->setParent(multiPart);

		multiPart->append(filePart);

		QNetworkRequest request(QUrl(CLOUD_IP + "/TaaS/totalissue/addFile"));//addPicture
		if (m_pPostIssueDataManager)
		{
			m_replyFile = m_pPostIssueDataManager->post(request, multiPart);
			multiPart->setParent(m_replyFile);
			m_replyFile->setProperty("filePath", QVariant::fromValue(strFilePath));
			connect(m_replyFile, SIGNAL(finished()), this, SLOT(requestFinishedSlot()));
			connect(m_replyFile, SIGNAL(uploadProgress(qint64, qint64)), this, SLOT(uploadProgressSlot(qint64, qint64)));
			connect(m_replyFile, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(getParamErrorSlot(QNetworkReply::NetworkError)));
		}

	}

	void VisualizationFrame::updateIssueListUI(const std::vector<QString> &vecIssueId)
	{		
		//更新list
		m_issueList->setUpdatesEnabled(false);
		
		QStandardItemModel *model = new QStandardItemModel(this);
				
		for (int i = 0; i < vecIssueId.size(); ++i)
		{
			QStandardItem *item = new QStandardItem(vecIssueId[i]);
			QLinearGradient linearGrad(QPointF(0, 0), QPointF(200, 200));
			linearGrad.setColorAt(0, Qt::darkGreen);
			//linearGrad.setColorAt(1, Qt::yellow);
			QBrush brush(linearGrad);
			item->setBackground(brush);
			model->appendRow(item);
		}
		
		m_issueList->setModel(model);
		m_issueList->setContextMenuPolicy(Qt::CustomContextMenu);
		connect(m_issueList, SIGNAL(customContextMenuRequested(const QPoint&)),	this, SLOT(showContextMenuSlot(const QPoint&)));
		m_issueList->setUpdatesEnabled(true);

		//更新右边窗口
		//m_selectParamPanel->initUI();
		
	}

	void VisualizationFrame::getAllIssueId()
	{	
		//m_strTextStatus->setText("getAllIssueId");
		//执行post请求		
		if (m_pGetAllIssueIDManager)
		{
			m_strTextStatus->setText("正在請求資料請等待...");
			qDebug() << "正在請求資料請等待...";
			m_replyGetAllIssueId = m_pGetAllIssueIDManager->get(QNetworkRequest(QUrl(CLOUD_IP + "/TaaS/totalissue/list")));//totalissue
			connect(m_replyGetAllIssueId, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(getParamErrorSlot(QNetworkReply::NetworkError)));
			QReplyTimeout *pTimeout = new QReplyTimeout(m_replyGetAllIssueId, 3000);
			// 超时进一步处理
			connect(pTimeout, &QReplyTimeout::timeout, [=]() 
			{
				qDebug() << "getAllIssueId request timeout";
				m_strTextStatus->setText("getAllIssueId request timeout");
			});
		}		
	}

	void VisualizationFrame::getParamByIssueID(const QString &strIssueId)
	{	
		QByteArray objId = getJsonObjectFromString(strIssueId, "");

		QNetworkRequest request = QNetworkRequest(QUrl(CLOUD_IP + "/TaaS/totalissue/get"));
		request.setRawHeader(QString("Content-Type").toLatin1(), QString("application/json; charset=utf-8").toLatin1());
		request.setRawHeader(QString("Content-Length").toLatin1(), QString::number(objId.length()).toLatin1());

		//执行post请求		
		if (m_pGetParamManager)
		{
			QNetworkReply *reply = m_pGetParamManager->post(request, objId);
			connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(getParamErrorSlot(QNetworkReply::NetworkError)));
		}
	}

	void VisualizationFrame::getPictureFileByIssueID(const QString &strIssueId)
	{
		QByteArray objId = getJsonObjectFromString(strIssueId, "jpg,jpeg,png");
		QNetworkRequest request = QNetworkRequest(QUrl(CLOUD_IP + "/TaaS/totalissue/getFile"));//getPicture
		request.setRawHeader(QString("Content-Type").toLatin1(), QString("application/json; charset=utf-8").toLatin1());
		request.setRawHeader(QString("Content-Length").toLatin1(), QString::number(objId.length()).toLatin1());

		//执行post请求		
		if (m_pGetPictureManager)
		{
			QNetworkReply *reply = m_pGetPictureManager->post(request, objId);
			connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(getParamErrorSlot(QNetworkReply::NetworkError)));
		}
	}

	void VisualizationFrame::getVideoFileByIssueID(const QString &strIssueId)
	{
		QByteArray objId = getJsonObjectFromString(strIssueId, "mp4");
		QNetworkRequest request = QNetworkRequest(QUrl(CLOUD_IP + "/TaaS/totalissue/getFile"));//getPicture
		request.setRawHeader(QString("Content-Type").toLatin1(), QString("application/json; charset=utf-8").toLatin1());
		request.setRawHeader(QString("Content-Length").toLatin1(), QString::number(objId.length()).toLatin1());

		//执行post请求		
		if (m_pGetVideoManager)
		{
			QNetworkReply *reply = m_pGetVideoManager->post(request, objId);
			connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(getParamErrorSlot(QNetworkReply::NetworkError)));
		}
	}

	void VisualizationFrame::get8DFileByIssueID(const QString &strIssueId)
	{
		QByteArray objId = getJsonObjectFromString(strIssueId, "pdf");
		QNetworkRequest request = QNetworkRequest(QUrl(CLOUD_IP + "/TaaS/totalissue/getFile"));//getPicture
		request.setRawHeader(QString("Content-Type").toLatin1(), QString("application/json; charset=utf-8").toLatin1());
		request.setRawHeader(QString("Content-Length").toLatin1(), QString::number(objId.length()).toLatin1());

		//执行post请求		
		if (m_pGet8DFileManager)
		{
			QNetworkReply *reply = m_pGet8DFileManager->post(request, objId);
			connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(getParamErrorSlot(QNetworkReply::NetworkError)));
		}
	}

	void VisualizationFrame::deleteAllDataByIssueID(const QString &strIssueId)
	{
		QByteArray objId = getJsonObjectFromString(strIssueId, "");

		QNetworkRequest request = QNetworkRequest(QUrl(CLOUD_IP + "/TaaS/totalissue/deleteAll"));
		request.setRawHeader(QString("Content-Type").toLatin1(), QString("application/json; charset=utf-8").toLatin1());
		request.setRawHeader(QString("Content-Length").toLatin1(), QString::number(objId.length()).toLatin1());

		//执行post请求		
		if (m_pDeleteAllDataManager)
		{
			QNetworkReply *reply = m_pDeleteAllDataManager->post(request, objId);
			connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(getParamErrorSlot(QNetworkReply::NetworkError)));
		}
	}

	void VisualizationFrame::deleteFileByIssueID(const QString &strIssueId, const QString &strFileName)
	{
		if (!strIssueId.isEmpty())
		{
			QByteArray obj = getJsonObjectFromFileName(strIssueId, strFileName);
			m_selectDelFileName = strFileName;
			QNetworkRequest request = QNetworkRequest(QUrl(CLOUD_IP + "/TaaS/totalissue/deleteFile"));
			request.setRawHeader(QString("Content-Type").toLatin1(), QString("application/json; charset=utf-8").toLatin1());
			request.setRawHeader(QString("Content-Length").toLatin1(), QString::number(obj.length()).toLatin1());

			//执行post请求		
			if (m_pDeleteFileManager)
			{
				QNetworkReply *reply = m_pDeleteFileManager->post(request, obj);
				connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(getParamErrorSlot(QNetworkReply::NetworkError)));
			}
		}
		
	}

	QByteArray VisualizationFrame::getJsonObjectFromFileName(const QString &strJson, const QString &strFileName)
	{
		QJsonObject rootObj;

		rootObj.insert("issueId", strJson);
		rootObj.insert("name", strFileName);

		QJsonDocument document;
		document.setObject(rootObj);

		return document.toJson(QJsonDocument::Compact);
	}

	QByteArray VisualizationFrame::getJsonObjectFromString(const QString &strJson, const QString &strType) 
	{
		QJsonObject rootObj;

		rootObj.insert("issueId", strJson);
		if (!strType.isEmpty())
			rootObj.insert("type", strType);
		if ("name" == strType)
			rootObj.insert("name", strType);

		QJsonDocument document;
		document.setObject(rootObj);

		return document.toJson(QJsonDocument::Compact);
	}

	void VisualizationFrame::StructToJSon(const ISSUE_DESCRIBE &data, QByteArray &jsonArray)
	{
		QJsonObject rootObj;

		rootObj.insert("projectName", data.strProgramName);
		rootObj.insert("supplier", data.strSupplier);
		rootObj.insert("vehicleModel", data.strVehicleModel);
		rootObj.insert("issueType", data.strIssueType);
		rootObj.insert("issueId", data.strIssueID);
		rootObj.insert("question", data.strIssueDescribe);
		rootObj.insert("recordDate", data.strRecordDate);
		rootObj.insert("vehicleSoftwareVersion", data.strVehicleSoftWareVersion);
		rootObj.insert("appVersion", data.strAppVersion);
		rootObj.insert("grade", data.strLevel);
		rootObj.insert("fourRing", data.strFourRing);
		rootObj.insert("fourRingType", data.strFourRingType);
		rootObj.insert("realReasonCat", data.strRealReasonType);
		rootObj.insert("securityLevel", data.strSafeLevel);
		rootObj.insert("recordPerson", data.strRecordPerson);
		rootObj.insert("personInCharge", data.strPersonInCharge);
		rootObj.insert("status", data.strStatus);
		rootObj.insert("reason", data.strIssueReason);
		rootObj.insert("programme", data.strSolution);
		rootObj.insert("result", data.strReslut);
		rootObj.insert("estimateDate", data.strEstimateDate);
		rootObj.insert("actualDate", data.strActualDate);

		QJsonDocument document;
		document.setObject(rootObj);
		jsonArray = document.toJson(QJsonDocument::Compact);

	}

	void VisualizationFrame::deleteFileByNameSlot(QString strFileName)
	{
		m_strCurrentIssueId = m_selectParamPanel->getIssueId();
		deleteFileByIssueID(m_strCurrentIssueId, strFileName);
	}

	void VisualizationFrame::showContextMenuSlot(const QPoint& pos)
	{
		if (!((m_issueList->selectionModel()->selectedIndexes()).empty()))
		{			
			QString strID = "";
			QModelIndexList modelIndexList = m_issueList->selectionModel()->selectedIndexes();
			foreach(QModelIndex modelIndex, modelIndexList) {
				strID = m_issueList->model()->data(modelIndex).toString();
			}
			QMenu *cmenu = new QMenu(m_issueList);
			QAction *delAction = cmenu->addAction("删除");
			delAction->setProperty("IssueID", QVariant::fromValue(strID));
			QObject::connect(delAction, SIGNAL(triggered(bool)), this, SLOT(deleteAllDataByIssueIDSlot()));
			cmenu->exec(QPoint(pos.x(), pos.y()+50));//在当前鼠标位置显示
		}
		
	}

	void VisualizationFrame::deleteAllDataByIssueIDSlot()
	{
		QObject *object = QObject::sender();
		m_strCurrentIssueId = object->property("IssueID").toString();
		if (!m_strCurrentIssueId.isEmpty())
			deleteAllDataByIssueID(m_strCurrentIssueId);
	}

	void VisualizationFrame::getPostIssueParamResposeSlot(QNetworkReply* reply)
	{
		if (reply->error() == QNetworkReply::NoError)
		{
			qDebug("getPostIssueParamResposeSlot...");
			QByteArray bytes = reply->readAll();
			QString response = QString::fromUtf8(bytes);
			//response.replace("\\", "");

			//parser json
			CResult result;
			qDebug("getPostIssueParamResposeSlot response: %s ", qPrintable(response));
			parseHttpRespose(response, result);
			if (result.iStatus)
			{
				m_strTextStatus->setText(PARAM_PARSER_JSON_OK + result.strMessage);
				std::vector<QString>::iterator ret;
				ret = std::find(m_vecIssueId.begin(), m_vecIssueId.end(), m_strCurrentIssueId);
				if (ret == m_vecIssueId.end())
					m_vecIssueId.push_back(m_strCurrentIssueId);
	
				updateIssueListUI(m_vecIssueId);
			}
			else
			{
				m_strTextStatus->setText(PARAM_PARSER_JSON_ERROR + result.strMessage);
			}
		}

		reply->deleteLater();
	}

	void VisualizationFrame::getPostIssueDataResposeSlot(QNetworkReply* reply)
	{
		if (reply->error() == QNetworkReply::NoError)
		{
			QByteArray bytes = reply->readAll();
			QString response = QString::fromUtf8(bytes);
			//response.replace("\\", "");

			//parser json
			CResult result;
			QString strFileName = "";
			qDebug("getPostIssueDataResposeSlot response: %s ", response);
			parseHttpResposeData(response, strFileName, result);
			if (result.iStatus)
			{
				m_strTextStatus->setText(strFileName + DATA_PARSER_JSON_OK + result.strMessage);
				//刷新状态
				for (QMap<QString, SelectedFilePanel *>::iterator itor = m_fileUploadStatusMap.begin(); itor != m_fileUploadStatusMap.end(); itor++)
				{
					QFileInfo info(itor.key());
					if (info.fileName() == strFileName)
					{
						itor.value()->refreshPanelStatus(itor.key(), ":/image/ok.png");
						QString strCloudName = QString("%1/totalissue/%2/%3").arg(CLOUD_IP).arg(m_strCurrentIssueId).arg(strFileName);
						itor.value()->setUploadFileName(strCloudName, strFileName);

						break;
					}
				}
			}
			else
			{
				m_strTextStatus->setText(strFileName + DATA_PARSER_JSON_ERROR + result.strMessage);
				//刷新状态
				for (QMap<QString, SelectedFilePanel *>::iterator itor = m_fileUploadStatusMap.begin(); itor != m_fileUploadStatusMap.end(); itor++)
				{
					QFileInfo info(itor.key());
					if (info.fileName() == strFileName)
					{
						itor.value()->refreshPanelStatus(itor.key(), ":/image/failed.png");
						break;
					}
				}
			}
		}

		reply->deleteLater();
	}

	void VisualizationFrame::getGetAllIssueIdResposeSlot(QNetworkReply*reply)
	{
		if (reply->error() == QNetworkReply::NoError)
		{
			QByteArray bytes = reply->readAll();
			QString response = QString::fromUtf8(bytes);
			//response.replace("\\", "");

			//parser json
			m_vecIssueId.clear();
			if (parserJsonToIssueList(response, m_vecIssueId))
			{
				sort(m_vecIssueId.begin(), m_vecIssueId.end());
				m_strTextStatus->setText(GET_ALL_ISSUEID_OK);
				updateIssueListUI(m_vecIssueId);
			}				
		}

		reply->deleteLater();
	}

	void VisualizationFrame::getGetParamResposeSlot(QNetworkReply*reply)
	{
		if (reply->error() == QNetworkReply::NoError)
		{
			QByteArray bytes = reply->readAll();
			QString response = QString::fromUtf8(bytes);
			//response.replace("\\", "");

			//parser json
			ISSUE_DESCRIBE data;
			if (parserJsonToStruct(response, data))
				updateUIParam(data);
		}

		reply->deleteLater();
	}

	void VisualizationFrame::getGetPictureResposeSlot(QNetworkReply*reply)
	{
		refreshPanel(reply, m_selectPicturePanel);
	}

	void VisualizationFrame::getGetVideoResposeSlot(QNetworkReply*reply)
	{
		refreshPanel(reply, m_selectVideoPanel);
	}

	void VisualizationFrame::getGet8DFileResposeSlot(QNetworkReply*reply)
	{		
		refreshPanel(reply, m_select8DFilePanel);
	}

	void VisualizationFrame::refreshPanel(QNetworkReply*reply, SelectedFilePanel *panel)
	{
		QStringList list = parseResposeToFile(reply);
		panel->addToFilePanel(list);
		const int ICount = list.size();
		for (int i = 0; i < ICount; ++i)
		{
			m_fileUploadStatusMap.insert(CLOUD_IP + list[i], panel);
		}
	}

	void VisualizationFrame::deleteAllDataResposeSlot(QNetworkReply*reply)
	{
		if (reply->error() == QNetworkReply::NoError)
		{
			QByteArray bytes = reply->readAll();
			QString response = QString::fromUtf8(bytes);
			//response.replace("\\", "");

			//parser json
			bool bFlag = false;
			if (parserJsonToBool(response, bFlag))
			{
				if (bFlag)
				{
					m_strTextStatus->setText(DELETE_ALL_DATA_ISSUEID_OK);
					
					for (std::vector<QString>::iterator itor = m_vecIssueId.begin(); itor != m_vecIssueId.end(); itor++)
					{
						if (*itor == m_strCurrentIssueId)
						{
							itor = m_vecIssueId.erase(itor);
							break;
						}
					}
					updateIssueListUI(m_vecIssueId);
				}					
				else
				{
					m_strTextStatus->setText(DELETE_ALL_DATA_ISSUEID_FAIL);
				}
					
			}
		}

		reply->deleteLater();
	}

	void VisualizationFrame::deleteFileResposeSlot(QNetworkReply*reply)
	{
		if (reply->error() == QNetworkReply::NoError)
		{
			QByteArray bytes = reply->readAll();
			QString response = QString::fromUtf8(bytes);
			//response.replace("\\", "");

			//parser json
			bool bFlag = false;
			if (parserJsonToBool(response, bFlag))
			{
				if (bFlag)
				{
					m_strTextStatus->setText(m_selectDelFileName + DELETE_FILE_OK);
					//刷新界面
					for (QMap<QString, SelectedFilePanel *>::iterator itor = m_fileUploadStatusMap.begin(); itor != m_fileUploadStatusMap.end(); itor++)
					{
						QFileInfo info(itor.key());
						if (info.fileName() == m_selectDelFileName)
						{
							itor.value()->deleteFileWidgetByFileName(m_selectDelFileName);
							itor = m_fileUploadStatusMap.erase(itor);//删除
							break;
						}
					}
					
				}
				else
				{
					m_strTextStatus->setText(m_selectDelFileName + DELETE_FILE_FAIL);
				}

			}
		}

		reply->deleteLater();
	}
	
	void VisualizationFrame::getAllIssueIdErrorSlot(QNetworkReply::NetworkError errorCode)
	{
		QString strError = QString("%1%2").arg(GET_SERVER_TASK).arg(QString::number(errorCode, 10));
		m_strTextStatus->setText(strError);
		qErrnoWarning("%s",strError);

		if (m_replyGetAllIssueId != NULL)
		{
			disconnect(m_pGetAllIssueIDManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getGetAllIssueIdResposeSlot(QNetworkReply*)));
			m_replyGetAllIssueId->abort();
			m_replyGetAllIssueId->deleteLater();
		}
	}

	void VisualizationFrame::getParamErrorSlot(QNetworkReply::NetworkError errorCode)
	{
		QString strError = QString("%1%2").arg(GET_SERVER_TASK).arg(QString::number(errorCode, 10));
		m_strTextStatus->setText(strError);
		qErrnoWarning("%s", strError);
	}

	void VisualizationFrame::uploadProgressSlot(qint64 bytesSent, qint64 bytesTotal)
	{
		if (bytesTotal > 0) {
			qint64 persent = (bytesSent * 100 / bytesTotal);
			qDebug() << "upload progress bytesSent:" << bytesSent << ",bytesTotal:" << bytesTotal << ",persent:" << persent << "%";
		}
	}

	void VisualizationFrame::requestFinishedSlot()
	{
		if (m_replyFile)
		{
			QNetworkReply *reply = (QNetworkReply*)sender();
			QString filePath = reply->property("filePath").toString();
			QFile *file = m_fileHandleMap[filePath];
			if (NULL != file)
			{
				file->flush();
				file->close();
				file = NULL;
			}
				
		//	if (m_replyFile->error() == QNetworkReply::NoError) {
		//		qDebug() << "upload file finished";
		//		m_uploadFile->flush();
		//		m_uploadFile->close();
		//		//m_replyFile->deleteLater();
		//		//m_replyFile = NULL;

		//		/*delete m_uploadFile;
		//		m_uploadFile = NULL;*/
		//	}
		//	else {
		//		qDebug() << "error string:" << m_replyFile->errorString();
		//		//m_replyFile->deleteLater();
		//	}
		}
		
	}

	QStringList VisualizationFrame::parseResposeToFile(QNetworkReply*reply)
	{
		QStringList list;
		list.clear();

		if (reply->error() == QNetworkReply::NoError)
		{
			QByteArray bytes = reply->readAll();
			QString response = QString::fromUtf8(bytes);
			//response.replace("\\", "");

			//parser json
			parserJsonToFileData(response, list);
		}

		reply->deleteLater();
		return list;
	}

	bool VisualizationFrame::parserJsonToStruct(const QString &strRespose, ISSUE_DESCRIBE &data)
	{
		QJsonParseError jsonError;
		QJsonDocument doc = QJsonDocument::fromJson(strRespose.toUtf8(), &jsonError);
		if (jsonError.error == QJsonParseError::NoError)
		{
			if (doc.isObject())
			{
				QJsonObject object = doc.object();
				if (object.contains("status"))
				{
					QJsonValue statusText = object.take("status");
					if (1 == statusText.toInt())//成功
					{
						if (object.contains("data"))
						{
							QJsonValue value = object.value("data");
							if (value.isObject())
							{
								QJsonObject obj = value.toObject();

								data.strProgramName = jsonValueToString(obj, "projectName");
								data.strSupplier = jsonValueToString(obj, "supplier");
								data.strVehicleModel = jsonValueToString(obj, "vehicleModel");
								data.strIssueType = jsonValueToString(obj, "issueType");
								data.strIssueID = jsonValueToString(obj, "issueId");
								data.strIssueDescribe = jsonValueToString(obj, "question");
								data.strRecordDate = jsonValueToString(obj, "recordDate");
								data.strVehicleSoftWareVersion = jsonValueToString(obj, "vehicleSoftwareVersion");
								data.strAppVersion = jsonValueToString(obj, "appVersion");
								data.strLevel = jsonValueToString(obj, "grade");
								data.strFourRing = jsonValueToString(obj, "fourRing");
								data.strFourRingType = jsonValueToString(obj, "fourRingType");
								data.strRealReasonType = jsonValueToString(obj, "realReasonCat");
								data.strSafeLevel = jsonValueToString(obj, "securityLevel");
								data.strRecordPerson = jsonValueToString(obj, "recordPerson");
								data.strPersonInCharge = jsonValueToString(obj, "personInCharge");
								data.strStatus = jsonValueToString(obj, "status");
								data.strIssueReason = jsonValueToString(obj, "reason");
								data.strSolution = jsonValueToString(obj, "programme");
								data.strReslut = jsonValueToString(obj, "result");
								data.strEstimateDate = jsonValueToString(obj, "estimateDate");
								data.strActualDate = jsonValueToString(obj, "actualDate");
							}
						}
						return true;
					}					
				}		
			}
			return false;
		}
		else
		{
			qDebug("parserJsonToStruct parse json error: %s", strRespose);
			return false;
		}
	}

	bool VisualizationFrame::parserJsonToIssueList(const QString &strRespose, std::vector<QString> &list)
	{
		QJsonParseError jsonError;
		QJsonDocument doc = QJsonDocument::fromJson(strRespose.toUtf8(), &jsonError);
		if (jsonError.error == QJsonParseError::NoError)
		{
			if (doc.isObject())
			{
				QJsonObject obj = doc.object();
				if (obj.contains("status"))
				{
					QJsonValue statusText = obj.take("status");
					if (1 == statusText.toInt())//成功
					{
						QJsonValue value = obj.value("data");
						if (value.isArray())
						{
							QJsonArray array = value.toArray();

							int nSize = array.size();
							for (int i = 0; i < nSize; ++i)
							{
								QJsonObject objLine = array.at(i).toObject();
								QVariantMap ddd = objLine.toVariantMap();
								if (objLine.contains("issueId"))
								{
									QJsonValue valueId = objLine["issueId"];
									if (valueId.type() == QJsonValue::String )
									{
										list.push_back(valueId.toString());
									}									
								}						
							}
						}
						return true;
					}
				}
			}
			return false;
		}
		else
		{
			qDebug("parserJsonToIssueList parse json error:%s", strRespose);
			return false;
		}
	}

	bool VisualizationFrame::parserJsonToFileData(const QString &strRespose, QStringList &data)
	{
		QJsonParseError jsonError;
		QJsonDocument doc = QJsonDocument::fromJson(strRespose.toUtf8(), &jsonError);
		if (jsonError.error == QJsonParseError::NoError)
		{
			if (doc.isObject())
			{
				QJsonObject obj = doc.object();
				if (obj.contains("status"))
				{
					QJsonValue statusText = obj.take("status");
					if (1 == statusText.toInt())//成功
					{
						QJsonValue value = obj.value("data");
						if (value.isArray())
						{
							QJsonArray array = value.toArray();

							int nSize = array.size();
							for (int i = 0; i < nSize; ++i)
							{								
								QJsonValue value = array.at(i);
								if (value.type() == QJsonValue::String)
								{
									data << value.toString();
								}
							}
						}
						return true;
					}
				}
			}
			return false;
		}
		else
		{
			qDebug("parserJsonToFileData parse json error: %s", strRespose);
			return false;
		}
	}

	QString VisualizationFrame::jsonValueToString(QJsonObject obj, const QString &strName)
	{
		QString strReturn = "";
		if (obj.contains(strName))
		{
			
			QJsonValue recordDateText = obj.take(strName);
			if (recordDateText.isString())
			{
				strReturn = recordDateText.toString();
			}
		}
		return strReturn;
	}

	bool VisualizationFrame::parserJsonToBool(const QString &strRespose, bool &bFlag)
	{
		QJsonParseError jsonError;
		QJsonDocument doc = QJsonDocument::fromJson(strRespose.toUtf8(), &jsonError);
		if (jsonError.error == QJsonParseError::NoError)
		{
			if (doc.isObject())
			{
				QJsonObject obj = doc.object();
				if (obj.contains("status"))
				{
					QJsonValue statusText = obj.take("status");
					if (1 == statusText.toInt())//成功
					{
						bFlag = true;
					}
					else
					{
						bFlag = false;
					}
				}
			}
			return true;
		}
		else
		{
			qDebug("parserJsonToBool parse json error: %s", strRespose);
			return false;
		}
	}

	bool VisualizationFrame::parseHttpRespose(QString text, CResult& result)
	{
		QJsonParseError jsonError;
		QJsonDocument doc = QJsonDocument::fromJson(text.toUtf8(), &jsonError);
		if (jsonError.error == QJsonParseError::NoError)
		{
			if (doc.isObject())
			{
				QJsonObject obj = doc.object();
				if (obj.contains("status"))
				{
					QJsonValue resultCode = obj.take("status");
					result.iStatus = resultCode.toInt();
				}
				if (obj.contains("message"))
				{
					QJsonValue resultText = obj.take("message");
					if (resultText.isString())
					{
						result.strMessage = resultText.toString();
					}
				}
			}
			return true;
		}
		else
		{
			qDebug("parseHttpRespose parse json error: %s", text);
			return false;
		}
	}

	bool VisualizationFrame::parseHttpResposeData(QString text, QString &strFileName, CResult& result)
	{
		QJsonParseError jsonError;
		QJsonDocument doc = QJsonDocument::fromJson(text.toUtf8(), &jsonError);
		if (jsonError.error == QJsonParseError::NoError)
		{
			if (doc.isObject())
			{
				QJsonObject obj = doc.object();
				if (obj.contains("status"))
				{
					QJsonValue resultCode = obj.take("status");
					result.iStatus = resultCode.toInt();
				}
				if (obj.contains("fileName"))
				{
					QJsonValue fileName = obj.take("fileName");
					if (fileName.isString())
					{
						strFileName = fileName.toString();
					}
				}
				if (obj.contains("message"))
				{
					QJsonValue resultText = obj.take("message");
					if (resultText.isString())
					{
						result.strMessage = resultText.toString();
					}
				}
			}
			return true;
		}
		else
		{
			qDebug("parseHttpRespose parse json error: %s", text);
			return false;
		}
	}
	
	QByteArray VisualizationFrame::getFileMd5(const QString &filePath)
	{
		QFile theFile(filePath);
		theFile.open(QIODevice::ReadOnly);
		QByteArray md5 = QCryptographicHash::hash(theFile.readAll(), QCryptographicHash::Md5);
		theFile.close();

		return md5;

		//QCryptographicHash hash(QCryptographicHash::Md5);
		//QFile file(filePath);
		//if (!file.open(QIODevice::ReadOnly)) {
		//	QMessageBox::information(this, "infomation", "打开文件失败");
		//	return QByteArray();
		//}
		//while (!file.atEnd()) {
		//	QByteArray text = file.read(1024 * 10);
		//	hash.addData(text);
		//	qApp->processEvents();
		//}

		//QByteArray fileMd5 = hash.result();
		//QString sss = fileMd5.toHex().constData();
		//return fileMd5;
		
	}

}  // namespace DataUploadTool


