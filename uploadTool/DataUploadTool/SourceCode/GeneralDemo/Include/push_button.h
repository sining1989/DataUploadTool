#ifndef DATA_UPLOAD_SYSTEM_BUTTON_H
#define DATA_UPLOAD_SYSTEM_BUTTON_H

#include <QPushButton>
#include <QPainter>
#include <QMouseEvent>


//枚举按钮的几种状态
typedef enum {
	NORMALSTU,
	ENTER,
	PRESS,
	NOSTATUS
}ButtonStatus;


class PushButton : public QPushButton
{
	Q_OBJECT

public:

	explicit PushButton(QWidget *parent = 0);
	~PushButton();
	void setPicName(QString pic_name);

protected:

	void enterEvent(QEvent *);
	void leaveEvent(QEvent *);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void paintEvent(QPaintEvent *);

private:
	ButtonStatus status;
	QString pic_name;

	int btn_width; //按钮宽度
	int btn_height; //按钮高度
	bool m_mousePress; //按钮左键是否按下
};

#endif //DATA_UPLOAD_SYSTEM_BUTTON_H

