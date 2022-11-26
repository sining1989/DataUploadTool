#ifndef DATA_UPLOAD_CONFIGINFO_H
#define DATA_UPLOAD_CONFIGINFO_H

#include <QString>
#include <QSettings>

namespace DataUploadTool
{
	class CConfigInfo
	{
	private:
		CConfigInfo();
		static CConfigInfo* instance;
	public:
		static CConfigInfo* getInstace();
		static void init(QSettings *pCfg);
	public:
		QString m_strXmppUrl;
		QString m_strXmppUserName;
		QString m_strXmppPassword;
		QString m_strTaskUrl;
		QString m_strTaskPort;
		QString m_strCreateTaskUrl;

	public:
		CConfigInfo& operator =(CConfigInfo&);
	};

	class CResult
	{
	public:
		CResult();
		CResult(int status, QString message);
	public:
		int iStatus;
		QString strMessage;
	};
} // namespace DataUploadTool

#endif // DATA_UPLOAD_CONFIGINFO_H
