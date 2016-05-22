#include<iostream>
#include<Int.h>
#include<utility>
#include<cmath>

lab3_5::func::func()
{
    x0 = 0;
    xk = 2;
    h1 = 0.5;
    h2 = 0.25;
}

lab3_5::func::~func()
{}

double lab3_5::func::f(double x)
{
    return x*x / (pow(x, 4) + 256);
}

double lab3_5::func::getIntPh1()
{
    double res = 0;
    double a = x0;
    double b = a + h1;
    while (b <= xk)
    {
        res += f((a + b) / 2);
        a = b;
        b += h1;
    }
    return res * h1;
}

double lab3_5::func::getIntPh2()
{
    double res = 0;
    double a = x0;
    double b = a + h2;
    while (b <= xk)
    {
        res += f((a + b) / 2);
        a = b;
        b += h2;
    }
    return res * h2;
}

double lab3_5::func::getIntTh1()
{
    double res = 0;
    double a = x0 + h1;
    while (a <= xk)
    {
        /*if (a == x0 || a == xk)
        {
            res += f(a) / 2;
            a += h1;
            continue;
        }*/
        //std::cout << a << " " << a - h1 << "\n";
        res += (f(a) + f(a - h1));
        a += h1;
    }
    return 0.5*res * h1;
}

double lab3_5::func::getIntTh2()
{
    double res = 0;
    double a = x0 + h2;
    while (a <= xk)
    {
        /*if (a == x0 || a == xk)
        {
            res += f(a) / 2;
            a += h2;
            continue;
        }*/
        res += (f(a) + f(a - h2));
        a += h2;
    }
    return 0.5*res * h2;
}

double lab3_5::func::getIntSh1()
{
    double res = 0;
    double a = x0;
    int i = 0;
    while (a <= xk)
    {
        if (a == x0 || a == xk)
        {
            res += f(a);
            a += h1;
            ++i;
            continue;
        }
        if (i % 2 == 1)
        {
            res += 4 * f(a);
        }
        if (i % 2 == 0)
        {
            res += 2 * f(a);
        }
        a += h1;
        ++i;
    }
    return res * h1 / 3;
}

double lab3_5::func::getIntSh2()
{
    double res = 0;
    double a = x0;
    int i = 0;
    while (a <= xk)
    {
        if (a == x0 || a == xk)
        {
            res += f(a);
            a += h2;
            ++i;
            continue;
        }
        if (i % 2 == 1)
        {
            res += 4 * f(a);
        }
        if (i % 2 == 0)
        {
            res += 2 * f(a);
        }
        a += h2;
        ++i;
    }
    return res * h2 / 3;
}

double lab3_5::func::getRumbRombP()
{
    double p = 1.0;
    return this->getIntPh2() + (this->getIntPh2() - this->getIntPh1()) / (pow(2, p) - 1);
}

double lab3_5::func::getRumbRombT()
{
    double p = 2.0;
    return this->getIntTh2() + (this->getIntTh2() - this->getIntTh1()) / (pow(2, p) - 1);
}

double lab3_5::func::getRumbRombS()
{
    double p = 4.0;
    return this->getIntSh2() + (this->getIntSh2() - this->getIntSh1()) / (pow(2, p) - 1);
}