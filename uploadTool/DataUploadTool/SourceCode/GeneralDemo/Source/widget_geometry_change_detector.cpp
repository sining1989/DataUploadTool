#include <QEvent>

#include "widget_geometry_change_detector.h"

namespace DataUploadTool
{
	WidgetGeometryChangeDetector::WidgetGeometryChangeDetector(QObject* parent)
		: QObject(parent)
	{}

	bool WidgetGeometryChangeDetector::eventFilter(QObject* watched, QEvent* event)
	{
		if (event->type() == QEvent::Move ||
			event->type() == QEvent::Resize)
		{
			Q_EMIT changed();
		}
		return QObject::eventFilter(watched, event);
	}

} // end namespace DataUploadTool
