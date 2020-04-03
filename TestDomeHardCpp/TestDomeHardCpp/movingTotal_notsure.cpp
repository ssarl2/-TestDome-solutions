#include <iostream>
#include <list>
#include <iterator>

class MovingTotal
{
public:
    MovingTotal() {};

    void Append(const std::list<int>& list)
    {
        for (auto it = list.begin(); it != list.end(); ++it)
        {
            //std::cout << "list : " << *it << std::endl;
            li.push_back(*it);
        }
    }

    bool Contains(int total)
    {
        int sum = 0;
        std::list<int>::iterator itd;
        for (auto itd = li.rbegin(); itd != li.rend(); ++itd)
        {
            sum += *itd;
            if (sum == total)
                return true;
        }

        return false;
    }
private:
    std::list<int> li;
};

#ifndef RunTests
int main()
{
    MovingTotal movingTotal;

    std::list<int> list = { 1, 2, 3 };
    movingTotal.Append(list);

    std::cout << std::boolalpha << movingTotal.Contains(6) << std::endl;
    std::cout << std::boolalpha << movingTotal.Contains(9) << std::endl;

    list.emplace_back(4);
    movingTotal.Append(list);

    std::cout << std::boolalpha << movingTotal.Contains(9) << std::endl;

}
#endif // !
