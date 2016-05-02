#include<iostream>
#include<Spline.h>
int main()
{
    lab3_2::spline spl;
    spl.initInterpolation();
    std::cout << "f(0.8): " << spl.getvalue(0.8) << "\n";
    system("pause");
    return 0;
}