#include "push_button.h"

PushButton::PushButton(QWidget *parent)
	:QPushButton(parent)
{	
	status = NORMALSTU;
	m_mousePress = false;
}

PushButton::~PushButton()
{

}

void PushButton::setPicName(QString pic_name)
{
	this->pic_name = pic_name;
	setFixedSize(QPixmap(pic_name).size());
}

void PushButton::enterEvent(QEvent *)
{
	status = ENTER;
	update();
}

void PushButton::mousePressEvent(QMouseEvent *event)
{
	//Èôµã»÷Êó±ê×ó¼ü
	if(event->button() == Qt::LeftButton)
	{
		m_mousePress = true;
		status = PRESS;
		update();
	}
}

void PushButton::mouseReleaseEvent(QMouseEvent *event)
{
	//Èôµã»÷Êó±ê×ó¼ü
	if(m_mousePress  && this->rect().contains(event->pos()))
	{
		m_mousePress = false;
		status = ENTER;
		update();
		emit clicked();
	}
}

void PushButton::leaveEvent(QEvent *)
{
	status = NORMALSTU;
	update();
}

void PushButton::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	QPixmap pixmap;
	switch(status)
	{
	case NORMALSTU:
		{
			pixmap.load(pic_name);
			break;
		}    
	case ENTER:
		{
			pixmap.load(pic_name + QString("_hover"));
			break;
		} 
	case PRESS:
		{
			pixmap.load(pic_name + QString("_pressed"));	
			break;
		}   
	case NOSTATUS:
		{
			pixmap.load(pic_name);	
			break;
		}   
	default:
		pixmap.load(pic_name);
	}
	
	painter.drawPixmap(rect(), pixmap);
}
