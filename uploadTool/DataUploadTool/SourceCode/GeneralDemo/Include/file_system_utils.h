#ifndef DATA_UPLOAD_FILESYSTEM_UTILS_H_
#define DATA_UPLOAD_FILESYSTEM_UTILS_H_

#include <QtCore>
#include <QThread>

namespace DataUploadTool
{
	class DUFileSystemUtils : public QObject
	{
		Q_OBJECT

	public:

		DUFileSystemUtils();
		virtual ~DUFileSystemUtils();

		static QString readTextFile(QString path);

	};
} // namespace DataUploadTool
#endif /* DATA_UPLOAD_FILESYSTEM_UTILS_H_ */
