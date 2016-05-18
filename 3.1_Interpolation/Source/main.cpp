#include<iostream>
#include<Lagrange.h>
#include<Newton.h>
void val()
{
    std::cout << "x:   y:\n";
    for (double x = 0.1; x < 1.3; x += 0.01)
    {
        std::cout << x << "    " << log(x) + x << "\n";
    }
}
int main()
{
    lab3_1_lagr::polynom lagr;
    //val();
    //lagr.initInterpolation();
    double x = 0.8;
    lagr.setA();
    //lagr.val();
    std::cout << "a) fx: " << log(x) + x << " Lx: " << lagr.getvalue(x) << " |fx-Lx|: " << fabs(log(x) + x - lagr.getvalue(x)) << "\n";
    lagr.setB();
    ///lagr.val();
    std::cout << "b) fx: " << log(x) + x << " Lx: " << lagr.getvalue(x) << " |fx-Lx|: " << fabs(log(x) + x - lagr.getvalue(x)) << "\n";
    
    lab3_1_newt::polynom newt;
    newt.setA();
    //newt.val();
    //newt.initInterpolation();
    std::cout << "a) fx: " << log(x) + x << " Nx: " << newt.getvalue(x) << " |fx-Nx|: " << fabs(log(x) + x - newt.getvalue(x)) << "\n";
    newt.setB();
    //newt.val();
    std::cout << "b) fx: " << log(x) + x << " Nx: " << newt.getvalue(x) << " |fx-Nx|: " << fabs(log(x) + x - newt.getvalue(x)) << "\n";
    
    
    system("pause");
    return 0;
}