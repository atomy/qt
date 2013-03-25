#include "GoalApp.h"
#include "GoalFactory.h"
#include <QPainter>
#include <iostream>
#include <assert.h>

GoalApp::GoalApp(QWidget *parent)
	: QWidget(parent)
{	    
    resize(1000, 800);
    m_pContainer.add(GoalFactory::get(1));
    m_pContainer.add(GoalFactory::get(2));
    m_pContainer.add(GoalFactory::get(2));
    m_pContainer.add(GoalFactory::get(3));
    m_pContainer.add(GoalFactory::get(3));
    m_pContainer.add(GoalFactory::get(4));
    m_pContainer.add(GoalFactory::get(4));
    m_pContainer.add(GoalFactory::get(4));
	frameNo = 0;        
}

void GoalApp::paintEvent(QPaintEvent *event)
{
	m_pGoalRenderer.setEvent(event);
	m_pGoalRenderer.setWidget(this);

    std::vector<GoalElement*>::iterator end = m_pContainer.end();
	std::vector<GoalElement*>::iterator cur = m_pContainer.begin();

    std::cout << "bla bla" << std::endl;

    while (cur != end) {
        GoalElement* ele = (*cur);
        assert(ele != NULL);
        m_pGoalRenderer.render(ele);
        cur++;
	}
}

 void GoalApp::nextAnimationFrame()
 {
     ++frameNo;
     update();
 }
