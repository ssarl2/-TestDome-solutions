#include <stdexcept>
#include <iostream>
#include <vector>
#include <map>

std::vector<int> findUniqueNumbers(const std::vector<int>& numbers)
{
    std::map<int, int> checkUniqueNumbers;

    for (int i = 0; i < numbers.size(); i++)
    {
        int number = numbers[i];
        if (checkUniqueNumbers.find(number) == checkUniqueNumbers.end())
        {
            checkUniqueNumbers[number] = 1;
        }
        else
        {
            checkUniqueNumbers[number] += 1;
        }
    }

    std::vector<int> result;
    for (std::map<int, int>::iterator it = checkUniqueNumbers.begin(); it != checkUniqueNumbers.end(); ++it)
    {
        if(it -> second == 1)
            result.push_back(it->first);
    }
    return result;
}

#ifndef RunTests
int main()
{
    std::vector<int> numbers = { 1, 2, 1, 3 };
    std::vector<int> result = findUniqueNumbers(numbers);
    for (int i = 0; i < result.size(); i++)
        std::cout << result[i] << '\n';
}
#endif

/*

Insert numbers data to a map.
If there are duplicated numbers while code inserts data into the map, then increase the counter numbers.
Move data to vector from the map.
But if second data is greater than 1, just skip the method.
return result.

*/