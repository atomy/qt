#ifndef GOALRENDERER_H
#define GOALRENDERER_H

#include "GoalElement.h"
#include <QPainter>
#include <qwidget.h>

class GoalRenderer
{

public:
	GoalRenderer();

	void render(GoalElement* ele, int);
	void setEvent(QPaintEvent*);
	void setWidget(QWidget* widget);
        void getCoordsForCircle(float center, float radius, float angle, float& x, float& y);

private:
	QPaintEvent* m_pEvent;
	QWidget* m_pWidget;
};

#endif // GOALRENDERER_H
