#include "GoalApp.h"
#include "GoalFactory.h"
#include <QPainter>
#include <iostream>

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
	m_pGoalRenderer.setEvent(event);
	m_pGoalRenderer.setWidget(this);

	std::vector<GoalElement*>::iterator begin = m_pContainer.begin();
	std::vector<GoalElement*>::iterator end = m_pContainer.end();
	std::vector<GoalElement*>::iterator cur = m_pContainer.begin();
	
	while (cur != end) {
		cur++;
		GoalElement* ele = *cur;
		m_pGoalRenderer.render(ele, frameNo);
	}
}

 void GoalApp::nextAnimationFrame()
 {
     ++frameNo;
     update();
 }
