#include "file_system_utils.h"
namespace DataUploadTool
{
	DUFileSystemUtils::DUFileSystemUtils()
	{
		// NOOP
	}


	DUFileSystemUtils::~DUFileSystemUtils()
	{
		// NOOP
	}

	QString DUFileSystemUtils::readTextFile(QString path)
	{
		QFile file(path);

		if (file.open(QIODevice::ReadOnly | QIODevice::Text))
		{
			QTextStream in(&file);
			return in.readAll();
		}

		return "";
	}
} 