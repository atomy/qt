#ifndef GOALCONTAINER_H
#define GOALCONTAINER_H

#include <vector>
#include "GoalElement.h"

class GoalContainer
{
public:
	GoalContainer();

	void add(GoalElement* ele) {
		m_pGoalElements.push_back(ele);
	}

private:
	std::vector<GoalElement*> m_pGoalElements;
};

#endif // GOALELEMENT_H