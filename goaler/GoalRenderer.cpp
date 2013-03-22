#include "GoalRenderer.h"
#include <iostream>
#include <cmath>

#define _USE_MATH_DEFINES

GoalRenderer::GoalRenderer()
{
}

void GoalRenderer::setEvent(QPaintEvent* event)
{
	m_pEvent = event;
}

void GoalRenderer::render(GoalElement* ele, int frameNo)
{
        QPainter painter(m_pWidget);
	painter.setRenderHint(QPainter::Antialiasing, true);

	int w = m_pWidget->width();
	int h = m_pWidget->height();

        painter.setPen(QPen(QColor(255, 0, 0), 3));
        painter.resetTransform();

        //painter.translate(50, 100);

        float x1, y1, x2, y2;

        // arc
        painter.setPen(QPen(QColor(128, 0, 128), 3));
        QRectF rect1(0.0, 0.0, 800.0, 800.0);
        painter.drawRect(rect1);
        painter.setPen(QPen(QColor(255, 0, 0), 3));
        painter.drawEllipse(rect1);

        // arc
        painter.setPen(QPen(QColor(0, 255, 0), 3));
        QRectF rect2(200.0, 200.0, 400.0, 400.0);
        int startAngle2 = 30 * 16;
        int spanAngle2 = 120 * 16;
        painter.drawEllipse(rect2);

        // line        
        getCoordsForCircle(400.0, 400.0, 45.0, x1, y1);
        getCoordsForCircle(400.0, 200.0, 45.0, x2, y2);
        painter.setPen(QPen(QColor(0, 0, 255), 3));
        painter.drawLine(x1, y1, x2, y2);

        // line        
        getCoordsForCircle(400.0, 400.0, 135.0, x1, y1);
        getCoordsForCircle(400.0, 200.0, 135.0, x2, y2);
        painter.setPen(QPen(QColor(128, 128, 0), 3));
        painter.drawLine(x1, y1, x2, y2);

        // line
        getCoordsForCircle(400.0, 400.0, 235.0, x1, y1);
        getCoordsForCircle(400.0, 200.0, 235.0, x2, y2);
        painter.setPen(QPen(QColor(255, 0, 0), 3));
        painter.drawLine(x1, y1, x2, y2);

        // line
        getCoordsForCircle(400.0, 400.0, 315.0, x1, y1);
        getCoordsForCircle(400.0, 200.0, 315.0, x2, y2);
        painter.setPen(QPen(QColor(255, 255, 0), 3));
        painter.drawLine(x1, y1, x2, y2);
}

void GoalRenderer::getCoordsForCircle(float center, float radius, float angle, float& x, float& y)
{
    x = center + radius * std::cos(2 * M_PI * (angle / 360.0));
    y = center + radius * std::sin(2 * M_PI * (angle / 360.0));
}

void GoalRenderer::setWidget(QWidget* widget)
{
    m_pWidget = widget;
}
