#ifndef GOALAPP_H
#define GOALAPP_H

#include "GoalContainer.h"
#include <qwidget.h>

class GoalApp : public QWidget
{
	Q_OBJECT

public:
	GoalApp(QWidget *parent = 0);

protected:
	void paintEvent(QPaintEvent *event);
	void nextAnimationFrame();

private:
	GoalContainer m_pContainer;
	int frameNo;
};

#endif // GOALAPP_H