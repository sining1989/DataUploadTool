#include "selected_param_panel.h"

namespace DataUploadTool {
	SelectedParamPanel::SelectedParamPanel(QWidget *parent, QString strTitle)
		: Panel(parent)
		, m_strTitleName(strTitle)
	{
		this->resize(840, 420);

		this->initTitleWidget();
		this->initCenterWidget();

	
		QVBoxLayout *main_layout = new QVBoxLayout();
		main_layout->addWidget(m_topWidget);
		//main_layout->addStretch();
		main_layout->addWidget(m_centerWidget);
		main_layout->setSpacing(5);
		main_layout->setContentsMargins(5, 5, 5, 5);

		this->setLayout(main_layout);
		
	}

	void SelectedParamPanel::initTitleWidget()
	{
		m_topWidget = new QWidget(this);
		m_topWidget->setFixedHeight(30);
		m_topWidget->setStyleSheet("background-color:rgb(150,147,88);");

		m_titleLabel = new QLabel();
		m_titleLabel->setFixedHeight(25);
		m_titleLabel->setCursor(Qt::PointingHandCursor);

		m_titleLabel->setText(m_strTitleName);

		title_layout = new QHBoxLayout();
		title_layout->addWidget(m_titleLabel, 0, Qt::AlignLeft);
		title_layout->setSpacing(5);
		title_layout->setContentsMargins(10, 0, 0, 0);
		m_topWidget->setLayout(title_layout);

	}

	void SelectedParamPanel::initCenterWidget()
	{
		m_centerWidget = new QWidget(this);
		ui.setupUi(m_centerWidget);
		initWidgetData();
	}

	void SelectedParamPanel::paintEvent(QPaintEvent *event)
	{
		Q_UNUSED(event);

		QPainter p(this);
		p.setPen(Qt::NoPen);
		p.setBrush(Qt::white);
		p.drawRect(rect());
	}

	void SelectedParamPanel::resizeEvent(QResizeEvent *event)
	{
		ui.scrollArea->resize(this->size().width() - 10, this->size().height() - 120);
	}

	void SelectedParamPanel::initWidgetData()
	{
		ui.Level_comboBox->clear();
		QStringList strLevelList;
		strLevelList << "Minor" << "Major" << "Critical";
		ui.Level_comboBox->addItems(strLevelList);

		ui.FourRing_comboBox->clear();
		QStringList strFourRingList;
		strFourRingList << "一環" << "二環" << "三環" << "四環";
		ui.FourRing_comboBox->addItems(strFourRingList);

		ui.FourRingType_comboBox->clear();
		QStringList strFourRingTypeList;
		strFourRingTypeList << "Autonomous" << "Connectivity" << "Criticial Driving" << "Electrification" << "Function" << "Industrial Design"
							<< "NVH" << "Performance" << "Safety" << "Security" << "Sharing";
		ui.FourRingType_comboBox->addItems(strFourRingTypeList);

		ui.Program_comboBox->clear();
		QStringList strProjectList;
		strProjectList << "iPEBG - 觀瀾" << "e叉車" << "RFID設備" << "行深智能樣車" << "一清創新樣車" << "準時達 - 補充運力";
		ui.Program_comboBox->addItems(strProjectList);

		ui.Supplier_comboBox->clear();
		QStringList strSupplierList;
		strSupplierList << "行深智能" << "一清創新" << "BITO";
		ui.Supplier_comboBox->addItems(strSupplierList);

		ui.VehicleModel_comboBox->clear();
		QStringList strVehicleModelList;
		strVehicleModelList << "B1B(白色)" << "B2D" << "超影1000C" << "誇父-I" << "誇父-I-F" << "誇父-I-Plus";
		ui.VehicleModel_comboBox->addItems(strVehicleModelList);

		ui.IssueType_comboBox->clear();
		QStringList strIssueTypeList;
		strIssueTypeList << "Issue" << "Requirement";
		ui.IssueType_comboBox->addItems(strIssueTypeList);

		ui.State_comboBox->clear();
		QStringList strStateList;
		strStateList << "Open" << "Closed";
		ui.State_comboBox->addItems(strStateList);

		ui.Reason_comboBox->clear();
		QStringList strReasonList;
		strReasonList << "設計" << "來料(供應鏈)" << "製造/組裝";
		ui.Reason_comboBox->addItems(strReasonList);

		ui.SafeLevel_comboBox->clear();
		QStringList strSafeLevelList;
		strSafeLevelList << "Eng. Rating-1" << "Eng. Rating-2" << "Eng. Rating-3";
		ui.SafeLevel_comboBox->addItems(strSafeLevelList);

		ui.CleanEstimateDateBtn->setFixedSize(80, 25);
		ui.CleanEstimateDateBtn->setStyleSheet("background:white;border:transparent;color:green;"); 
		ui.CleanEstimateDateBtn->setCursor(Qt::PointingHandCursor);

		ui.CleanActualDateBtn->setFixedSize(80, 25);
		ui.CleanActualDateBtn->setStyleSheet("background:transparent;border:transparent;color:green;");
		ui.CleanActualDateBtn->setCursor(Qt::PointingHandCursor);

		connect(ui.CleanEstimateDateBtn, SIGNAL(clicked()), this, SLOT(cleanEstimateDateSlot())); 
		connect(ui.CleanActualDateBtn, SIGNAL(clicked()), this, SLOT(cleanActualDateSlot()));
	}

	ISSUE_DESCRIBE SelectedParamPanel::getIssueDescribePanelData()
	{
		ISSUE_DESCRIBE issue;
		issue.strProgramName = ui.Program_comboBox->currentText();
		issue.strSupplier = ui.Supplier_comboBox->currentText();
		issue.strVehicleModel = ui.VehicleModel_comboBox->currentText();
		issue.strIssueType = ui.IssueType_comboBox->currentText();
		issue.strIssueID = ui.ID_lineEdit->text();
		issue.strIssueDescribe = ui.IssueDescribe_textEdit->toPlainText();
		QDate dt = ui.Record_dateEdit->date();
		issue.strRecordDate = dt.toString("yyyy-MM-dd 00:00:00");
		issue.strVehicleSoftWareVersion = ui.VehicleVersion_lineEdit->text();
		issue.strAppVersion = ui.APPVersion_lineEdit->text();
		issue.strLevel = ui.Level_comboBox->currentText();
		issue.strFourRing = ui.FourRing_comboBox->currentText();
		issue.strFourRingType = ui.FourRingType_comboBox->currentText();
		issue.strRealReasonType = ui.Reason_comboBox->currentText();
		issue.strSafeLevel = ui.SafeLevel_comboBox->currentText();
		issue.strRecordPerson = ui.RecordPerson_lineEdit->text();
		issue.strPersonInCharge = ui.PersonInCharge_lineEdit->text();
		issue.strStatus = ui.State_comboBox->currentText();
		issue.strIssueReason = ui.IssueResson_textEdit->toPlainText();
		issue.strSolution = ui.Solution_textEdit->toPlainText();
		issue.strReslut = ui.Result_textEdit->toPlainText();
		dt = ui.Estimate_dateEdit->date();
		issue.strEstimateDate = dt.toString("yyyy-MM-dd 00:00:00");
		dt = ui.Actual_dateEdit->date();
		issue.strActualDate = dt.toString("yyyy-MM-dd 00:00:00");

		return issue;

	}

	QString SelectedParamPanel::getIssueId()
	{
		return ui.ID_lineEdit->text();
	}

	void SelectedParamPanel::initUI()
	{
		ui.Program_comboBox->setCurrentText("");
		ui.Supplier_comboBox->setCurrentText("");
		ui.VehicleModel_comboBox->setCurrentText("");
		ui.IssueType_comboBox->setCurrentText("");
		ui.ID_lineEdit->setText("");
		ui.IssueDescribe_textEdit->setText("");
		ui.Record_dateEdit->setDate(QDate::currentDate());
		ui.VehicleVersion_lineEdit->setText("");
		ui.APPVersion_lineEdit->setText("");
		ui.Level_comboBox->setCurrentText("");
		ui.FourRing_comboBox->setCurrentText("");
		ui.FourRingType_comboBox->setCurrentText("");
		ui.Reason_comboBox->setCurrentText("");
		ui.SafeLevel_comboBox->setCurrentText("");
		ui.RecordPerson_lineEdit->setText("");
		ui.PersonInCharge_lineEdit->setText("");
		ui.State_comboBox->setCurrentText("");
		ui.IssueResson_textEdit->setText("");
		ui.Solution_textEdit->setText("");
		ui.Result_textEdit->setText("");
		//ui.Estimate_dateEdit->setDate(QDate::currentDate());
		//ui.Actual_dateEdit->setDate(QDate::currentDate());
		ui.Estimate_dateEdit->setNullable(true);
		ui.Estimate_dateEdit->setCalendarPopup(true);
		ui.Estimate_dateEdit->clear();

		ui.Actual_dateEdit->setNullable(true);
		ui.Actual_dateEdit->setCalendarPopup(true);
		ui.Actual_dateEdit->clear();
	}

	void SelectedParamPanel::updateUI(ISSUE_DESCRIBE data)
	{
		ui.Program_comboBox->setCurrentText(data.strProgramName);
		ui.Supplier_comboBox->setCurrentText(data.strSupplier);
		ui.VehicleModel_comboBox->setCurrentText(data.strVehicleModel);
		ui.IssueType_comboBox->setCurrentText(data.strIssueType);
		ui.ID_lineEdit->setText(data.strIssueID);
		ui.IssueDescribe_textEdit->setText(data.strIssueDescribe);
		ui.Record_dateEdit->setDate(QDate::fromString(data.strRecordDate, "yyyy-MM-dd 00:00:00"));
		ui.VehicleVersion_lineEdit->setText(data.strVehicleSoftWareVersion);
		ui.APPVersion_lineEdit->setText(data.strAppVersion);
		ui.Level_comboBox->setCurrentText(data.strLevel);
		ui.FourRing_comboBox->setCurrentText(data.strFourRing);
		ui.FourRingType_comboBox->setCurrentText(data.strFourRingType);
		ui.Reason_comboBox->setCurrentText(data.strRealReasonType);
		ui.SafeLevel_comboBox->setCurrentText(data.strSafeLevel);
		ui.RecordPerson_lineEdit->setText(data.strRecordPerson);
		ui.PersonInCharge_lineEdit->setText(data.strPersonInCharge);
		ui.State_comboBox->setCurrentText(data.strStatus);
		ui.IssueResson_textEdit->setText(data.strIssueReason);
		ui.Solution_textEdit->setText(data.strSolution);
		ui.Result_textEdit->setText(data.strReslut);
		ui.Estimate_dateEdit->setDate(QDate::fromString(data.strEstimateDate, "yyyy-MM-dd 00:00:00"));
		ui.Actual_dateEdit->setDate(QDate::fromString(data.strActualDate, "yyyy-MM-dd 00:00:00"));
	}

	void SelectedParamPanel::cleanEstimateDateSlot()
	{
		ui.Estimate_dateEdit->setNullable(true);
		ui.Estimate_dateEdit->setCalendarPopup(true);
		ui.Estimate_dateEdit->clear();
	}

	void SelectedParamPanel::cleanActualDateSlot()
	{
		ui.Actual_dateEdit->setNullable(true);
		ui.Actual_dateEdit->setCalendarPopup(true);
		ui.Actual_dateEdit->clear();
	}
}