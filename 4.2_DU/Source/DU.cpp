#include<iostream>
#include<DU2.h>
#include<utility>
#include<cmath>

lab4_2::func::func()
{
    h = 0.01;
    a = 0;
    b = 3.14 / 6;
}

lab4_2::func::~func()
{}

double lab4_2::func::f(double x)
{
    return sin(x) + 2 - sin(x) * log((1 + sin(x)) / (1 - sin(x)));
}

void lab4_2::func::getTable()
{
    for (double x = a; x <= b + h / 3; x += h)
    {
        std::cout << "x: " << x << " y: " << this->f(x) << "\n";
    }
}

void lab4_2::func::getRes()
{
    DU du(this);
    double n1 = 2.0;
    double n2 = 2.1;
    double r1 = du.getValue(n1, 0);
    double r2 = du.getValue(n2, 0);
    int i = 0;
    //std::cout << "resr " << 2.5 - 0.5 * log(3) << "\n";
    while (fabs(r2 - 2.5 + 0.5 * log(3)) > 0.01 && i++ < 10)
    {
     //   std::cout << "fabs " << fabs(r2 - 2.5 + 0.5 * log(3)) << "\n";
        double n3 = n2 - (n2 - n1) * (r2 - 2.5 + 0.5 * log(3)) / (r2 - r1);
        double r3 = du.getValue(n3, 0);
       // std::cout << "n1 " << n1 << " r1 " << r1 << " n2 " << n2 << " r2 " << r2 << " n3 " << n3 << " r3 " << r3 << "\n";
        n1 = n2;
        n2 = n3;
        r1 = r2;
        r2 = r3;
    }
   // std::cout << "n2 " << n2 << "\n";
    du.getValue(n2, 1);
    
}

double lab4_2::func::f(double x, double y)
{
    return tan(x * x) - 2 * y;
}

lab4_2::DU::DU(func *arg)
{
    this->arg = arg;
}

lab4_2::DU::~DU()
{

}

double lab4_2::DU::getValue(double nu, bool p)
{
    double yi = 2;
    double fi = nu;
    if (p)
        std::cout << "x: " << this->arg->a << " y: " << yi << "\n";
    for (double x = this->arg->a; x <= this->arg->b + this->arg->h / 3; x += this->arg->h)
    {
        double k1 = 0;
        if (x == this->arg->a)
            k1 = this->arg->h * fi;
        else
            k1 = this->arg->h * this->arg->f(x, yi);
        double k2 = this->arg->h * this->arg->f(x + 1.0 / 3 * this->arg->h, yi + 1.0 / 3 * k1);
        double k3 = this->arg->h * this->arg->f(x + 2.0 / 3 * this->arg->h, yi + 2.0 / 3 * k2);;
        double dy = 1.0 / 4 * (k1 + 3 * k3);
        /*std::cout << "k1: " << k1 << "\n";
        std::cout << "k2: " << k2 << "\n";
        std::cout << "k3: " << k3 << "\n";
        std::cout << "dy: " << dy << "\n";*/
        yi = yi + dy;
        if (p)
            std::cout << "x: " << x + this->arg->h << " y: " << yi << "\n";
    }
    return yi;
}