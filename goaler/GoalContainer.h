#ifndef GOALCONTAINER_H
#define GOALCONTAINER_H

#include <vector>
#include "GoalElement.h"

class GoalContainer
{
public:
    GoalContainer() { };

    void    add(GoalElement* ele);
    bool    canAdd(GoalElement* ele);
    void    resize();

	std::vector<GoalElement*>::iterator begin() {
		return m_pGoalElements.begin();
	}

	std::vector<GoalElement*>::iterator end() {
		return m_pGoalElements.end();
	}    

private:
	std::vector<GoalElement*> m_pGoalElements;
};

#endif // GOALELEMENT_H
