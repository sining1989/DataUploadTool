#ifndef DATA_UPLOAD_COMMON_CONFIG_H
#define DATA_UPLOAD_COMMON_CONFIG_H

#include <QDateTime>

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#define VERSION "V1.0.0"
#define APP_NAME tr("Issue上傳工具")
#define STATUS_NAME tr("狀態：")
#define SCREENSHOT_SAVEIMAGE tr("保存圖片")
#define SCREENSHOT_ERROR tr("錯誤")
#define SCREENSHOT_SAVEERROR tr("將圖像寫入檔失敗")
#define SCREENSHOT_SUPPORTEDFORMATS tr("支援的圖像格式有：")
#define SCREENSHOT_ALLWINDOW tr("保存整個demo視窗")
#define SCREENSHOT_ORIGINAL_RESOLUTION tr("圖像將以原始解析度保存。")
#define GET_SERVER_TASK tr("從後臺獲取任務失敗，錯誤碼：")
#define PARAM_PARSER_JSON_OK tr("上傳參數")
#define PARAM_PARSER_JSON_ERROR tr("上傳參數失敗:")
#define DATA_PARSER_JSON_OK tr("文件上傳")
#define DATA_PARSER_JSON_ERROR tr("檔上傳失敗：")

#define ISSUE_ID_IS_NULL tr("Issue ID不能為空")

#define GET_ALL_ISSUEID_OK tr("獲取Issue ID列表成功")
#define DELETE_ALL_DATA_ISSUEID_OK tr("刪除Issue ID有關資料成功")
#define DELETE_ALL_DATA_ISSUEID_FAIL tr("刪除Issue ID有關資料失敗")
#define DELETE_FILE_OK tr("刪除成功")
#define DELETE_FILE_FAIL tr("刪除失敗")

#define ADD_ISSUE_BTN tr("新增問題")
#define ISSUE_RECORD_LABEL tr("問題記錄")
#define REFRESH_BTN tr("刷新")
#define ISSUE_PARAM tr("問題詳情")
#define ADD_PICTURE tr("添加圖片")
#define ADD_VIDEO tr("添加視頻")
#define ADD_8DFILE tr("添加8D報告")

#define DOCK_WIDGET_ISSUEDESCRIBE tr("問題描述")
#define DOCK_WIDGET_PICTURE tr("圖片")
#define DOCK_WIDGET_VIDEO tr("視頻")
#define DOCK_WIDGET_8DREPORT tr("8D報告")
#define COMMIT_BTN tr("提交")

#define SAFE_DELETE(p) {if (p != 0) {delete p; p = NULL;}}

enum ERROR_CODE
{
	HTTP_SUCCESS = 1000,
	HTTP_ERROR_COMMON = 1001
};

typedef struct _ISSUE_DESCRIBE
{
	QString strProgramName;
	QString strSupplier;
	QString strVehicleModel;
	QString strIssueType;	
	QString strIssueID;
	QString strIssueDescribe;
	QString strRecordDate;
	QString strVehicleSoftWareVersion;
	QString strAppVersion;
	QString strLevel;
	QString strFourRing;
	QString strFourRingType;
	QString strRealReasonType;
	QString strSafeLevel;
	QString strRecordPerson	;
	QString strPersonInCharge;
	QString strStatus;
	QString strIssueReason;
	QString strSolution;
	QString strReslut;
	QString strEstimateDate;
	QString strActualDate;

	_ISSUE_DESCRIBE()
	{
		strProgramName = "";
		strSupplier = "";
		strVehicleModel = "";
		strIssueType = "";
		strIssueID = "";
		strIssueDescribe = "";
		strRecordDate = "";
		strVehicleSoftWareVersion = "";
		strAppVersion = "";
		strLevel = "";
		strFourRing = "";
		strFourRingType = "";
		strRealReasonType = "";
		strSafeLevel = "";
		strRecordPerson = "";
		strPersonInCharge = "";
		strStatus = "";
		strIssueReason = "";
		strSolution = "";
		strReslut = "";
		strEstimateDate = "";
		strActualDate = "";
	}

} ISSUE_DESCRIBE, *PISSUE_DESCRIBE;

#endif // DATA_UPLOAD_COMMON_CONFIG_H
