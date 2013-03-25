#include "GoalFactory.h"

GoalElement* GoalFactory::get(int level)
{
    return new GoalElement(level);
}
