#ifndef GOALFACTORY_H
#define GOALFACTORY_H

#include "GoalElement.h"

class GoalFactory
{
public:
	static GoalElement* get();
};

#endif // GOALFACTORY_H