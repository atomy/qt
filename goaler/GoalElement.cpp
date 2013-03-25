#include "GoalElement.h"

GoalElement::GoalElement()
{
}

void GoalElement::doX()
{
}

void GoalElement::doY()
{
}

void GoalElement::resize(int elementsInThatLevel, int elementNo)
{
    float a = 360.0 / (elementsInThatLevel);

    startAngle = (a * elementNo) + 0.0;
    endAngle = startAngle + a;
}
