#include "GoalContainer.h"
#include <assert.h>
#include <string>
#include <stdexcept>
#include <iostream>

#define MAX_LEVELS 50 // TODO, check these
#define MAX_NEIGHBOARS 10 // TODO, check these

void GoalContainer::add(GoalElement* ele)
{
    if (!canAdd(ele)) {
        assert(false);
    }

    m_pGoalElements.push_back(ele);
    resize();
}

bool GoalContainer::canAdd(GoalElement* ele)
{
    std::vector<GoalElement*>::iterator end = m_pGoalElements.end();
    std::vector<GoalElement*>::iterator cur = m_pGoalElements.begin();

    bool foundRoot = false;

    // check for duplicate root elements (level == 1)
    while (cur != end) {
        GoalElement* ele = (*cur);
        if (ele->getLevel() == 1) {
            foundRoot = true;
        }
        cur++;
    }

    if (ele->getLevel() == 1 && foundRoot == true) {
        return false;
    }

    return true;
}

void GoalContainer::resize()
{
    GoalElement ***levelGoals = new GoalElement**[MAX_LEVELS];

    for (int x = 0; x < MAX_LEVELS; x++) {
        levelGoals[x] = new GoalElement*[MAX_NEIGHBOARS];
        for (int y = 0; y < MAX_NEIGHBOARS; y++) {
            levelGoals[x][y] = NULL;
        }
    }

    std::vector<GoalElement*>::iterator end = m_pGoalElements.end();
    std::vector<GoalElement*>::iterator cur = m_pGoalElements.begin();

    while (cur != end) {
        GoalElement* ele = (*cur);
        assert(ele != NULL);

        int x = ele->getLevel();
        std::cout << "adding level: " << x << std::endl;

        assert(x > 0 && x < MAX_LEVELS); // check range

        for (int y = 0; y < MAX_NEIGHBOARS; y++) {
            if (levelGoals[x][y] == NULL) {
                levelGoals[x][y] = ele;
                break;
            }
            assert(MAX_NEIGHBOARS != (y+1)); // we couldnt assign our variable
        }

        cur++;
    }

    for (int x = 0; x < MAX_LEVELS; x++) {
        int c = 0; // no of elements in that level

        for (int y = 0; y < MAX_NEIGHBOARS; y++) {
            if (levelGoals[x][y] != NULL) {
                c++;
            }
        }

        for (int y = 0; y < MAX_NEIGHBOARS; y++) {
            if (levelGoals[x][y] != NULL) {
                GoalElement* ele = levelGoals[x][y];
                ele->resize(c, y);
                assert(ele != NULL);
            }
        }
    }

    // cleanup
    for (int x = 0; x < MAX_LEVELS; x++) {
        delete levelGoals[x];
    }
    delete levelGoals;
}
