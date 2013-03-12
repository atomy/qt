#include "GoalFactory.h"

GoalElement* GoalFactory::get()
{
	return new GoalElement();
}