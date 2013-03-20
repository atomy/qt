#ifndef GOALAPP_H
#define GOALAPP_H

#include "GoalContainer.h"
#include "GoalRenderer.h"
#include <qwidget.h>

class GoalApp : public QWidget
{
	Q_OBJECT

public:
	GoalApp(QWidget *parent = 0);

	void setEvent(QPaintEvent*);

protected:
	void paintEvent(QPaintEvent *event);
	void nextAnimationFrame();

private:
	GoalContainer m_pContainer;
	GoalRenderer m_pGoalRenderer;
	int frameNo;
};

#endif // GOALAPP_H