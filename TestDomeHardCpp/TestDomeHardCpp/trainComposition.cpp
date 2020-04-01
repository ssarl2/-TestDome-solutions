#include <stdexcept>
#include <iostream>
#include <list>

class TrainComposition
{
public:
    void attachWagonFromLeft(int wagonId)
    {
        train.push_front(wagonId);
    }

    void attachWagonFromRight(int wagonId)
    {
        train.push_back(wagonId);
    }

    int detachWagonFromLeft()
    {
        int pop = train.front();
        train.pop_front();
        return pop;
    }

    int detachWagonFromRight()
    {
        int pop = train.back();
        train.pop_back();
        return pop;
    }
private:
    std::list<int> train;
};

#ifndef RunTests
int main()
{
    TrainComposition train;
    train.attachWagonFromLeft(7);
    train.attachWagonFromLeft(13);
    std::cout << train.detachWagonFromRight() << "\n"; // 7 
    std::cout << train.detachWagonFromLeft(); // 13
}
#endif