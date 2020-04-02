#include <vector>
#include <stdexcept>
#include <iostream>
#include <algorithm>

int countNumbers(const std::vector<int>& sortedVector, int lessThan)
{
    return std::distance
    (
        sortedVector.begin(),
        std::lower_bound(sortedVector.begin(), sortedVector.end(), lessThan)
    );
}

#ifndef RunTests
int main()
{
    std::vector<int> v{ 1, 3, 5, 7 };
    std::cout << countNumbers(v, 4);
}
#endif

/*For instance,
**about lower_bound*/
    /*
    #include<iostream>
    #include<algorithm>
    using namespace std;

    int main(void) {
        int arr[10] = { 1, 2, 4, 5, 6, 6, 7, 7, 7, 9 };

        cout << "lower_bound(6) : " << lower_bound(arr, arr + 10, 6) - arr + 1 << endl;
        cout << "lower_bound(7) : " << lower_bound(arr, arr + 10, 7) - arr + 1 << endl;
        cout << "lower_bound(8) : " << lower_bound(arr, arr + 10, 8) - arr + 1 << endl;
        cout << "lower_bound(9) : " << lower_bound(arr, arr + 10, 9) - arr + 1 << endl;
        return 0;
    }
    */

/*For instance,
**about */
    /*
    #include <iostream> 
    #include <vector> 
    #include <iterator> 
    using namespace std;
    int main()
    {
        vector<int> v;
        int i;

        for (i = 0; i < 10; ++i)
        {
            v.push_back(i);
        }

        // v contains 0 1 2 3 4 5 6 7 8 9

        vector<int>::iterator first;
        vector<int>::iterator last;

        // first pointing to 0 
        first = v.begin();

        // last pointing to 5 
        last = v.begin() + 5;

        // Calculating no. of elements between first and last 
        int num = std::distance(first, last);

        // Displaying num 
        cout << num << "\n";
        return 0;
    } // Output 5
    */

/*
Reference : Github
https://github.com/ha271923/TestCpp/blob/2e774dc1a2a4ee6416a755943188e3ae680eca2d/testdome/cpp/sortedsearch.cpp
*/