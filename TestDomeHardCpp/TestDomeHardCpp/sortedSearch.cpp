#include <vector>
#include <stdexcept>
#include <iostream>

int countNumbers(const std::vector<int>& sortedVector, int lessThan)
{
    int cnt = 0;
    for (auto elements : sortedVector) if (elements < lessThan) cnt++;

    return cnt;
    throw std::logic_error("Waiting to be implemented");
}

#ifndef RunTests
int main()
{
    std::vector<int> v{ 1, 3, 5, 7 };
    std::cout << countNumbers(v, 4);
}
#endif