#ifndef DATA_UPLOAD_VISUALIZER_APP_H
#define DATA_UPLOAD_VISUALIZER_APP_H

#include <QApplication>
#include <QtWidgets>
#include "qtsingleapplication.h"



namespace DataUploadTool
{
	class VisualizationFrame;

	class VisualizerApp : public QtSingleApplication
	{
	Q_OBJECT
	public:
	  
		VisualizerApp(const QString &id, int &argc, char **argv);
		  virtual ~VisualizerApp();

		  int exec(const QString& pFileToImport);

		  void cleanup();
		  
		  static VisualizerApp* app()
		  {
			  return static_cast<VisualizerApp*>qApp;
		  }

	public slots:
		void closeEvent(QCloseEvent *event);

	private slots:
		void closing();

	private:
		VisualizationFrame* frame_;

	};

} // end namespace DataUploadTool

#endif // DATA_UPLOAD_VISUALIZER_APP_H
