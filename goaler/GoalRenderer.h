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
    void getCoordsForCircle(float radius, float angle, float& x, float& y);

private:
    void _drawElement(QPainter &painter, GoalElement* ele);
    void _drawArc(QPainter &painter, GoalElement* ele);
    void _drawArcBorders(QPainter &painter, GoalElement* ele);

	QPaintEvent* m_pEvent;
	QWidget* m_pWidget;
    float mRadius, mRectX, mRectY, mRectH, mRectW;
    int mRectSize;
};

#endif // GOALRENDERER_H
