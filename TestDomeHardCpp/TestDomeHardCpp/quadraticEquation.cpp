#include <tuple>
#include <stdexcept>
#include <iostream>
#include <string>
#include <cmath>

std::pair<double, double> findRoots(double a, double b, double c)
{

    double x, y, sqr;
    sqr = sqrt(pow(b, 2) - (4.0 * a * c));

    x = (sqr - b) / 2.0 * a;
    y = (-1 * sqr - b) / 2.0 * a;

    int ix = x;
    int iy = y;
    int tmp;

    // get GCD
    while (iy != 0) {
        tmp = ix % iy;
        ix = iy;
        iy = tmp;
    }

    // divide depending on +, -
    if(x<0)
        x = x / ix * -1;
    else
        x = x / ix;

    if(y<0)
        y = y / ix * -1;
    else
        y = y / ix;

    return std::pair<double, double> (x,y);
}

#ifndef RunTests
int main()
{
    std::pair<double, double> roots = findRoots(2, 10, 8);
    std::cout << "Roots: " + std::to_string(roots.first) + ", " + std::to_string(roots.second);
}
#endif