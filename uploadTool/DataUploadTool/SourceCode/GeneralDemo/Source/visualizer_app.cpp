#include <QApplication>
#include <QTimer>

#include "visualizer_app.h"
#include "visualization_frame.h"
#include "settings.h"
#include "setting.h"
#include "file_system_utils.h"

namespace DataUploadTool
{
	static QObject* staticMemoryCleaner;
	VisualizerApp::VisualizerApp(const QString &id, int &argc, char **argv) : QtSingleApplication(id, argc, argv)
	{
		staticMemoryCleaner = new QObject(0); // deleted in UBApplication destructor

		setOrganizationName("Open Education Foundation");
		setOrganizationDomain("oe-f.org");
		setApplicationName("DataUploadTool");

		QString version = "V1.1.0";//UBVERSION;
		if (version.endsWith("."))
			version = version.left(version.length() - 1);
		setApplicationVersion(version);

		setStyle("fusion");

		QString css = DUFileSystemUtils::readTextFile(":/qss/DataUploadTool.qss"/*QApplication::applicationDirPath() + "/etc/" + qApp->applicationName() + ".css"*/);
		if (css.length() > 0)
			setStyleSheet(css); 

		QApplication::setStartDragDistance(8); // default is 4, and is a bit small for tablets

		installEventFilter(this);
	}

	int VisualizerApp::exec(const QString& pFileToImport)
	{
		frame_ = new VisualizationFrame();
		frame_->showMaximized();

		connect(frame_, SIGNAL(closeEvent_Signal(QCloseEvent*)), this, SLOT(closeEvent(QCloseEvent*)));

		return QApplication::exec();
	}

	VisualizerApp::~VisualizerApp()
	{

		//DUSettings::destroy();

	}

	void VisualizerApp::cleanup()
	{
		if (frame_) delete frame_;

		frame_ = NULL;
	}
	
	void VisualizerApp::closeEvent(QCloseEvent *event)
	{
		Q_UNUSED(event);

		closing();
	}

	void VisualizerApp::closing()
	{
		//DUSettings::settings()->closing();


		quit();
	}

} // namespace DataUploadTool
