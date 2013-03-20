#include "GoalRenderer.h"
#include <iostream>

GoalRenderer::GoalRenderer()
{
}

void GoalRenderer::setEvent(QPaintEvent* event)
{
	m_pEvent = event;
}

void GoalRenderer::render(GoalElement* ele, int frameNo)
{
	std::cout << 'test' << std::endl;

	QPainter painter;
	painter.setRenderHint(QPainter::Antialiasing, true);

	int w = m_pWidget->width();
	int h = m_pWidget->height();

	painter.translate((w / 2)-w/4 , (h / 2)-h/4);

	for (int diameter = 0; diameter < 256; diameter += 9) {
		int delta = abs((frameNo % 128) - diameter / 2);
		int alpha = 255 - (delta * delta) / 4 - diameter;
		if (alpha > 0) {
			painter.setPen(QPen(QColor(0, diameter / 2, 127, alpha), 3));
			painter.drawEllipse(QRect(-diameter / 2, -diameter / 2, diameter, diameter));
		}
	}

	painter.setRenderHint(QPainter::Antialiasing, false);
	painter.translate((w / 2) , (h / 2));

	for (int diameter = 0; diameter < 256; diameter += 27) {
		int delta = abs((frameNo % 128) - diameter / 2);
		int alpha = 255 - (delta * delta) / 4 - diameter;
		if (alpha > 0) {
			painter.setPen(QPen(QColor(0, diameter / 2, 127, alpha), 3));
			painter.drawEllipse(QRect(-diameter / 2, -diameter / 2, diameter, diameter));
		}
	}
}

void GoalRenderer::setWidget(QWidget* widget)
{
}