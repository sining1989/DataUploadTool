#ifndef DATA_UPLOAD_TOOLBUTTON_H
#define DATA_UPLOAD_TOOLBUTTON_H

#include <QToolButton>
#include <QMouseEvent>
#include <QPainter>

namespace DataUploadTool
{
	class ToolButton : public QToolButton
	{

	public:
		explicit ToolButton(QString pic_name, QWidget *parent = 0);
		~ToolButton();
		void setMousePress(bool mouse_press);

	protected:
		void enterEvent(QEvent *);
		void leaveEvent(QEvent *);
		void mousePressEvent(QMouseEvent *event);
		void paintEvent(QPaintEvent *event);
		void painterInfo(int top_color, int middle_color, int bottom_color);

	public:
		bool mouse_over; //鼠标是否移过
		bool mouse_press; //鼠标是否按下
	};
} // namespace DataUploadTool

#endif //DATA_UPLOAD_TOOLBUTTON_H
