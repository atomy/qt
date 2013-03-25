#ifndef GOALFACTORY_H
#define GOALFACTORY_H

#include "GoalElement.h"

class GoalFactory
{
public:
    static GoalElement* get(int level);
};

#endif // GOALFACTORY_H
