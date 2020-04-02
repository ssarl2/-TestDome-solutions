#include <stdexcept>
#include <iostream>
#include <vector>
#include <utility>

std::pair<int, int> findTwoSum(const std::vector<int>& list, int sum)
{
    for (size_t i = 0; i < list.size(); i++)
    {
        for (size_t j = 0; j < list.size(); j++)
        {
            if (i == j) continue;
            if (list[i] + list[j] == sum)
                return std::pair<int, int>(i, j);
        }

    }
    return std::pair<int, int>(-1, -1);
}

#ifndef RunTests
int main()
{
    std::vector<int> list = { 3, 1, 5, 7, 5, 9 };
    std::pair<int, int> indices = findTwoSum(list, 10);
    std::cout << indices.first << '\n' << indices.second;
}
#endif