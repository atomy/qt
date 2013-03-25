#ifndef GOALRENDERER_H
#define GOALRENDERER_H

#include "GoalElement.h"
#include <QPainter>
#include <qwidget.h>

class GoalRenderer
{

public:
	GoalRenderer();

    void render(GoalElement* ele);
    void renderOld(GoalElement* ele);
	void setEvent(QPaintEvent*);
	void setWidget(QWidget* widget);
    void getCoordsForCircle(float center, float radius, float angle, float& x, float& y);

private:
    void _drawCircleForLevel(QPainter &painter, int);
    void _drawElement(QPainter &painter, GoalElement* ele);

	QPaintEvent* m_pEvent;
	QWidget* m_pWidget;
};

#endif // GOALRENDERER_H
