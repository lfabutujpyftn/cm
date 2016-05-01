#include<iostream>
#include<Lagrange.h>
int main()
{
    lab3_1_lagr::polynom lagr;
    //lagr.initInterpolation();
    double x = 0.8;
    lagr.setA();
    std::cout << "a) fx: " << log(x) + x << " Lx: " << lagr.getvalue(x) << " |fx-Lx|: " << fabs(log(x) + x - lagr.getvalue(x)) << "\n";
    lagr.setB();
    std::cout << "b) fx: " << log(x) + x << " Lx: " << lagr.getvalue(x) << " |fx-Lx|: " << fabs(log(x) + x - lagr.getvalue(x)) << "\n";
    system("pause");
    return 0;
}