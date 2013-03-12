#include "GoalApp.h"
#include "GoalFactory.h"
#include <QPainter>

GoalApp::GoalApp(QWidget *parent)
	: QWidget(parent)
{	
	GoalElement* ele = GoalFactory::get();
	m_pContainer.add(ele);
	frameNo = 0;
}

// TODO, http://qt-project.org/doc/qt-4.8/qpainterpath.html
void GoalApp::paintEvent(QPaintEvent *event)
{
     QPainter painter(this);
     painter.setRenderHint(QPainter::Antialiasing, true);
     painter.translate((width() / 2)-width()/4 , (height() / 2)-height()/4);

     for (int diameter = 0; diameter < 256; diameter += 9) {
         int delta = abs((frameNo % 128) - diameter / 2);
         int alpha = 255 - (delta * delta) / 4 - diameter;
         if (alpha > 0) {
             painter.setPen(QPen(QColor(0, diameter / 2, 127, alpha), 3));
             painter.drawEllipse(QRect(-diameter / 2, -diameter / 2, diameter, diameter));
         }
     }

	 painter.setRenderHint(QPainter::Antialiasing, false);
     painter.translate((width() / 2) , (height() / 2));

     for (int diameter = 0; diameter < 256; diameter += 27) {
         int delta = abs((frameNo % 128) - diameter / 2);
         int alpha = 255 - (delta * delta) / 4 - diameter;
         if (alpha > 0) {
             painter.setPen(QPen(QColor(0, diameter / 2, 127, alpha), 3));
             painter.drawEllipse(QRect(-diameter / 2, -diameter / 2, diameter, diameter));
         }
     }
}

 void GoalApp::nextAnimationFrame()
 {
     ++frameNo;
     update();
 }
