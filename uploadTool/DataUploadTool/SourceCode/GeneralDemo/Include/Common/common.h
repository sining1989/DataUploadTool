#ifndef DATA_UPLOAD_COMMON_H
#define DATA_UPLOAD_COMMON_H

#include <QString>
#include <QDir>
#include <QCoreApplication>

#pragma once
#pragma warning ( disable : 4099 )

namespace DataUploadTool
{
	#define DELETEPTR(ptr) if(NULL != ptr){ \
		delete ptr; \
		ptr = NULL; \
		}

	const QString CLOUD_IP = "http://103.252.196.12:8080";
	//const QString CLOUD_IP = "http://10.139.26.56:8080";

	typedef enum {
		UI_EN,
		UI_ZH
	}LANGUAGE;

	extern bool isDirExist(QString fullPath);
	extern QString GetModulePath();
	extern bool isFileOrFolder(const std::string fileName);
	extern int g_iThemeId; // 0: Windows theme, 1: Darcula theme

} // end namespace DataUploadTool

#endif // DATA_UPLOAD_COMMON_H
