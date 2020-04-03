#include <iostream>
#include <functional>
#include <vector>

template<class T>
std::function<T(T)> makePipeline(const std::vector<std::function<T(T)>>& funcs) {
    return [&funcs](const T& arg) {
        T v = arg; // initial value
        for (const auto& f : funcs) {
            v = f(v); // sequentially apply a function.
        }
        return v;
    };
}

#ifndef RunTests
int main()
{
    std::vector<std::function<int(int)>> functions;
    functions.push_back([](int x) -> int { return x * 3; });
    functions.push_back([](int x) -> int { return x + 1; });
    functions.push_back([](int x) -> int { return x / 2; });

    std::function<int(int)> func = makePipeline(functions);
    std::cout << "1 : " << func(1) << std::endl; // should print ?
    std::cout << "2 : " << func(2) << std::endl; // should print ?
    std::cout << "3 : " << func(3) << std::endl; // should print 5
    std::cout << "4 : " << func(4) << std::endl; // should print ?
    std::cout << "5 : " << func(5) << std::endl; // should print ?
    std::cout << "6 : " << func(6) << std::endl; // should print ?
    std::cout << "7 : " << func(7) << std::endl; // should print ?
    std::cout << "8 : " << func(8) << std::endl; // should print ?
    std::cout << "9 : " << func(9) << std::endl; // should print ...
}
#endif

/* 
<int()>            vector    (int)       std::function
return    =>     ([&funcs](const T& arg) { return });
push_back =>     ([0](int x) -> int { return x * 3; });
    Let's think about       'return' = '-> int'

19 | vector<function<int(int)>> functions;
...
27 | functions structor
     return [funcs[0][1][2]](const int& 3)
     {
       int v = 3;
       const auto& f => f[0][1][2]
           {
20 |           v = f[0](3)  = return 3  * 3;    => v = 9
21 |           v = f[1](9)  = return 9  + 1;    => v = 10
22 |           v = f[2](10) = return 10 / 2;    => v = 5
           }
       return 5;
     };


*/


// https://github.com/walidAbbassi/TestDomeCpp/blob/1846ce5f5191a57369b9f68eec631fb6df8a596a/Pipeline.cpp