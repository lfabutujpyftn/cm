#include<iostream>
#include<Spline.h>

int main()
{
    /*lab3_2::spline spl;
    spl.initInterpolation();
    spl.val();
    std::cout << "f(0.8): " << spl.getvalue(0.8) << "\n";*/
    cubic_spline spl;
    double x[5];
    double y[5];
    x[0] = .1;
    x[1] = .5;
    x[2] = .9;
    x[3] = 1.3;
    x[4] = 1.7;
    y[0] = -2.2026;
    y[1] = -0.19315;
    y[2] = 0.79464;
    y[3] = 1.5624;
    y[4] = 2.2306;
    spl.build_spline(x, y, 5);
    /*std::cout << "#x\ty\n";
    for (double i = 0; i < 1.7; i += 0.01)
    {
        std::cout << i << "\t" << spl.f(i) << "\n";
    }*/
    spl.print();
//std::cout << "f(x): " << spl.f(0.8) << "\n";
std::cout << "f(x): " << spl.f(0.0) << "\n";
    system("pause");
    return 0;
}