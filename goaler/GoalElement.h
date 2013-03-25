#ifndef GOALELEMENT_H
#define GOALELEMENT_H

class GoalElement
{
public:
	GoalElement();

    GoalElement(int level) {
        this->level = level;
    }

    int getLevel() {
        return level;
    }

    int getStartAngle() {
        return startAngle;
    }

    int getEndAngle() {
        return endAngle;
    }

	void doX();
	void doY();

    void resize(int elementsInThatLevel, int elementNo);

private:
    int level;
    float startAngle;
    float endAngle;
};

#endif // GOALELEMENT_H
