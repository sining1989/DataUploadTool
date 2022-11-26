#include "settings.h"

#include <QtWidgets>


#include "setting.h"

namespace DataUploadTool
{
	QPointer<DUSettings> DUSettings::sSingleton = 0;

	QPointer<QSettings> DUSettings::sAppSettings = 0;

	QString DUSettings::appPingMessage = "__data_upload_tool_ping";

	DUSettings* DUSettings::settings()
	{
		if (!sSingleton) {
			sSingleton = new DUSettings(qApp);
		}
		return sSingleton;
	}

	void DUSettings::destroy()
	{
		if (sSingleton)
			delete sSingleton;
		sSingleton = NULL;
	}


	QSettings* DUSettings::getAppSettings()
	{
		if (!DUSettings::sAppSettings)
		{
			QString tmpSettings = QDir::tempPath() + "/" + qApp->applicationName() + ".config";
			QString appSettings = QApplication::applicationDirPath() + "/etc/" + qApp->applicationName() + ".config";

			// tmpSettings exists when upgrading Uniboard on Mac (see UBPlatformUtils_mac.mm updater:willInstallUpdate:)
			if (QFile::exists(tmpSettings))
			{
				QFile::rename(tmpSettings, appSettings);
			}

			DUSettings::sAppSettings = new QSettings(appSettings, QSettings::IniFormat, 0);
			DUSettings::sAppSettings->setIniCodec("utf-8");

			qDebug() << "sAppSettings location: " << appSettings;
		}

		return DUSettings::sAppSettings;
	}


	DUSettings::DUSettings(QObject *parent)
		: QObject(parent)
	{

		mAppSettings = DUSettings::getAppSettings();

		QString userSettingsFile = DUSettings::userDataDirectory() + "/" + qApp->applicationName() + "User.config";

		mUserSettings = new QSettings(userSettingsFile, QSettings::IniFormat, parent);

		init();
	}


	DUSettings::~DUSettings()
	{
		delete mAppSettings;

	}

	void DUSettings::init()
	{
		productWebUrl = new DUSetting(this, "App", "ProductWebAddress", "http://www.baidu.com");

		lastImportFolderPath = new DUSetting(this, "Import", "LastImportFolderPath", QVariant(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)));
	}
	
	QVariant DUSettings::value(const QString & key, const QVariant & defaultValue)
	{
		// Check first the settings queue, then the app settings, then the user settings.
		// If the key exists in neither of these, then defaultValue is returned.

		if (mSettingsQueue.contains(key))
			return mSettingsQueue.value(key);

		// If the setting doesn't exist in the App settings, add it there
		if (!sAppSettings->contains(key) && !(defaultValue == QVariant()))
			sAppSettings->setValue(key, defaultValue);

		// Get the value from the user settings (or if it doesn't exist there, from the app settings)
		QVariant val = mUserSettings->value(key, sAppSettings->value(key, defaultValue));

		// Add the value to the settings queue for faster access next time it is requested
		mSettingsQueue[key] = val;

		return val;
	}


	void DUSettings::setValue(const QString & key, const QVariant & value)
	{
		// Save the setting to the queue only; a call to save() is necessary to persist the settings
		mSettingsQueue[key] = value;
	}

	/**
	 * @brief Save all the queued settings to disk
	 */
	void DUSettings::save()
	{
		QHash<QString, QVariant>::const_iterator it = mSettingsQueue.constBegin();

		while (it != mSettingsQueue.constEnd()) {
			/*
			 * We save the setting to the user settings if
			 * a) it is different from the (non-null) value stored in the user settings, or
			 * b) it doesn't currently exist in the user settings AND has changed from the app settings
			*/
			if (mUserSettings->contains(it.key())
				&& it.value() != mUserSettings->value(it.key()))
			{
				mUserSettings->setValue(it.key(), it.value());
			}

			else if (!mUserSettings->contains(it.key())
				&& it.value() != mAppSettings->value(it.key()))
			{
				mUserSettings->setValue(it.key(), it.value());
			}

			++it;
		}

		// Force save to file
		mUserSettings->sync();

		qDebug() << "User settings saved";
	}


	QString DUSettings::userDataDirectory()
	{
		static QString dataDirPath = "";
		if (dataDirPath.isEmpty()) {
			if (getAppSettings() && getAppSettings()->contains("App/DataDirectory")) {
				qDebug() << "getAppSettings()->contains(App/DataDirectory):" << getAppSettings()->contains("App/DataDirectory");
				dataDirPath = getAppSettings()->value("App/DataDirectory").toString();
				dataDirPath = replaceWildcard(dataDirPath);

				if (checkDirectory(dataDirPath))
					return dataDirPath;
				else
					qCritical() << "Impossible to create datadirpath " << dataDirPath;

			}

			dataDirPath = QStandardPaths::writableLocation(QStandardPaths::DataLocation);
			dataDirPath.replace("\\", "/");

			if (qApp->organizationName().size() > 0)
				dataDirPath.replace(qApp->organizationName() + "/", "");
		}
		return dataDirPath;
	}


	QString DUSettings::userImageDirectory()
	{
		static QString imageDirectory = "";
		if (imageDirectory.isEmpty()) {
			if (sAppSettings && getAppSettings()->contains("App/UserImageDirectory")) {
				imageDirectory = getAppSettings()->value("App/UserImageDirectory").toString();

				imageDirectory = replaceWildcard(imageDirectory);
				if (checkDirectory(imageDirectory))
					return imageDirectory;
				else
					qCritical() << "failed to create image directory " << imageDirectory;
			}

			imageDirectory = QStandardPaths::writableLocation(QStandardPaths::PicturesLocation) + "/" + qApp->applicationName();
			checkDirectory(imageDirectory);
		}
		return imageDirectory;
	}


	QString DUSettings::userVideoDirectory()
	{
		static QString videoDirectory = "";
		if (videoDirectory.isEmpty()) {
			if (sAppSettings && getAppSettings()->contains("App/UserVideoDirectory")) {
				videoDirectory = getAppSettings()->value("App/UserVideoDirectory").toString();
				videoDirectory = replaceWildcard(videoDirectory);
				if (checkDirectory(videoDirectory))
					return videoDirectory;
				else
					qCritical() << "failed to create video directory " << videoDirectory;
			}


			videoDirectory = QStandardPaths::writableLocation(QStandardPaths::MoviesLocation);

			if (videoDirectory.isEmpty())
				videoDirectory = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/" + tr("My Movies");
			else
				videoDirectory = videoDirectory + "/" + qApp->applicationName();

			checkDirectory(videoDirectory);
		}
		return videoDirectory;
	}

	QString DUSettings::userAudioDirectory()
	{
		static QString audioDirectory = "";
		if (audioDirectory.isEmpty()) {
			if (sAppSettings && getAppSettings()->contains("App/UserAudioDirectory")) {
				audioDirectory = getAppSettings()->value("App/UserAudioDirectory").toString();

				audioDirectory = replaceWildcard(audioDirectory);
				if (checkDirectory(audioDirectory))
					return audioDirectory;
				else
					qCritical() << "failed to create image directory " << audioDirectory;
			}

			audioDirectory = QStandardPaths::writableLocation(QStandardPaths::MusicLocation) + "/" + qApp->applicationName();
			checkDirectory(audioDirectory);
		}
		return audioDirectory;
	}

	QString DUSettings::userFavoriteListFilePath()
	{
		static QString filePath = "";
		if (filePath.isEmpty()) {
			QString dirPath = userDataDirectory() + "/libraryPalette";
			checkDirectory(dirPath);
			filePath = dirPath + "/favorite.dat";
		}
		return filePath;
	}


	bool DUSettings::checkDirectory(QString& dirPath)
	{
		bool result = true;
		QDir dir(dirPath);
		if (!dir.exists())
			result = dir.mkpath(dirPath);
		return result;
	}

	QString DUSettings::replaceWildcard(QString& path)
	{
		QString result(path);

		if (result.startsWith("{Documents}")) {
			result = result.replace("{Documents}", QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation));
		}
		else if (result.startsWith("{Home}")) {
			result = result.replace("{Home}", QStandardPaths::writableLocation(QStandardPaths::HomeLocation));
		}
		else if (result.startsWith("{Desktop}")) {
			result = result.replace("{Desktop}", QStandardPaths::writableLocation(QStandardPaths::DesktopLocation));
		}

		return result;
	}

	void DUSettings::closing()
	{
		save();

	}


	/**
	 * @brief Permanently remove a setting, from local memory and config files
	 * @param setting The setting to remove
	 */
	void DUSettings::removeSetting(const QString &setting)
	{
		if (sAppSettings->contains(setting))
			sAppSettings->remove(setting);

		if (mUserSettings->contains(setting))
			mUserSettings->remove(setting);

		if (mSettingsQueue.contains(setting))
			mSettingsQueue.remove(setting);
	}
}
