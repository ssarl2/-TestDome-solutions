#include <stdexcept>
#include <iostream>
#include <vector>

std::vector<int> findUniqueNumbers(const std::vector<int>& numbers)
{
    
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