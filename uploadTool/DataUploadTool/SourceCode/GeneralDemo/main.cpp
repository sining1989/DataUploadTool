#include <QtWidgets>
#include <QTextCodec>

#include "visualizer_app.h"
#include "settings.h"

void ub_message_output(QtMsgType type, const QMessageLogContext& context, const QString& msg) {
	// We must temporarily remove the handler to avoid the infinite recursion of
	// ub_message_output -> qt_message_output -> ub_message_output -> qt_message_output ...
	QtMessageHandler previousHandler = qInstallMessageHandler(0);

#if defined(QT_NO_DEBUG)
	// Suppress qDebug output in release builds
	if (type != QtDebugMsg)
	{
		qt_message_output(type, context, msg);
	}

#else
	// Default output in debug builds
	qt_message_output(type, context, msg);
#endif

	if (DataUploadTool::VisualizerApp::app()) {
		QString logFileNamePath = QApplication::applicationDirPath() + "/log/" + qApp->applicationName() + ".log";
		QFile logFile(logFileNamePath);

		if (!logFile.exists())
		{
			QDir path(QApplication::applicationDirPath() + "/log");
			if (!path.exists())
			{
				path.mkdir(QApplication::applicationDirPath() + "/log");
			}
		}
			
		if (logFile.exists() && logFile.size() > 10000000)
			logFile.remove();

		if (logFile.open(QIODevice::Append | QIODevice::Text)) {
			QTextStream out(&logFile);
			out << QDateTime::currentDateTime().toString(Qt::ISODate)
				<< "      " << msg << "\n";
			logFile.close();
		}
	}

	qInstallMessageHandler(previousHandler);
}

int main(int argc, char *argv[])
{
	Q_INIT_RESOURCE(DataUploadTool);

	qInstallMessageHandler(ub_message_output);

	DataUploadTool::VisualizerApp app("DataUploadTool", argc, argv);

	QStringList args = app.arguments();

	QString dumpPath = QApplication::applicationDirPath()/*DataUploadTool::DUSettings::userDataDirectory()*/ + "/log";
	QDir logDir(dumpPath);
	if (!logDir.exists())
		logDir.mkdir(dumpPath);

	QString fileToOpen = "";

	if (args.size() > 1) {
		// On Windows/Linux first argument is the file that has been double clicked.
		// On Mac OSX we use FileOpen QEvent to manage opening file in current instance. So we will never
		// have file to open as a parameter on OSX.

		QFile f(args[1]);

		if (f.exists()) {
			fileToOpen += args[1];

			if (app.sendMessage(DataUploadTool::DUSettings::appPingMessage, 20000)) {
				app.sendMessage(fileToOpen, 1000000);
				return 0;
			}
		}
	}

	qDebug() << "file name argument" << fileToOpen;
	int result = app.exec(fileToOpen);

	app.cleanup();

	qDebug() << "application is quitting";



	return result;

}



