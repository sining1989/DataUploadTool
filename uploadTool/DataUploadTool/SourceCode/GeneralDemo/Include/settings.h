#ifndef DATA_UPLOAD_SETTINGS_H_
#define DATA_UPLOAD_SETTINGS_H_

#include <QtCore>
#include <QtWidgets>
#include <QtNetwork>

#include "setting.h"

namespace DataUploadTool
{
	class DUSettings : public QObject
	{

		Q_OBJECT

		public:

			static DUSettings* settings();
			static void destroy();

		private:

			DUSettings(QObject *parent = 0);
			virtual ~DUSettings();

		public:

			void closing();
			void save();

			void init();

			//user directories
			static QString userDataDirectory();
			static QString userFavoriteListFilePath();
			static QString userImageDirectory();
			static QString userVideoDirectory();
			static QString userAudioDirectory();
  
			static QString appPingMessage;

			DUSetting* productWebUrl;
			DUSetting* webHomePage;
			DUSetting* lastImportFolderPath;

		public slots:
		        
			QVariant value ( const QString & key, const QVariant & defaultValue = QVariant() );
			void setValue (const QString & key,const QVariant & value);

		private:

			QSettings* mAppSettings;
			QSettings* mUserSettings;

			QHash<QString, QVariant> mSettingsQueue;
        
			static QSettings* getAppSettings();

			static QPointer<QSettings> sAppSettings;
			static QPointer<DUSettings> sSingleton;

			static bool checkDirectory(QString& dirPath);
			static QString replaceWildcard(QString& path);

			void removeSetting(const QString& setting);

			

	};
}

#endif /* DATA_UPLOAD_SETTINGS_H_ */
