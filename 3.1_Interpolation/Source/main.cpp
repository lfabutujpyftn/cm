#include<iostream>
#include<Lagrange.h>
#include<Newton.h>
int main()
{
    lab3_1_lagr::polynom lagr;
    //lagr.initInterpolation();
    double x = 0.8;
    lagr.setA();
    std::cout << "a) fx: " << log(x) + x << " Lx: " << lagr.getvalue(x) << " |fx-Lx|: " << fabs(log(x) + x - lagr.getvalue(x)) << "\n";
    lagr.setB();
    std::cout << "b) fx: " << log(x) + x << " Lx: " << lagr.getvalue(x) << " |fx-Lx|: " << fabs(log(x) + x - lagr.getvalue(x)) << "\n";
    
    lab3_1_newt::polynom newt;
    newt.setA();
    //newt.initInterpolation();
    std::cout << "a) fx: " << log(x) + x << " Nx: " << newt.getvalue(x) << " |fx-Nx|: " << fabs(log(x) + x - newt.getvalue(x)) << "\n";
    newt.setB();
    std::cout << "b) fx: " << log(x) + x << " Nx: " << newt.getvalue(x) << " |fx-Nx|: " << fabs(log(x) + x - newt.getvalue(x)) << "\n";

    
    system("pause");
    return 0;
}