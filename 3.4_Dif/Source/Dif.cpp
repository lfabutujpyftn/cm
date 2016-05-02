#include<iostream>
#include<Dif.h>
#include<utility>
#include<cmath>

lab3_4::func::func()
{
    x.push_back(0.0);
    x.push_back(1.0);
    x.push_back(2.0);
    x.push_back(3.0);
    x.push_back(4.0);

    y.push_back(0.0);
    y.push_back(2.0);
    y.push_back(3.4142);
    y.push_back(4.7321);
    y.push_back(6.0);

    xz = 2.0;
}

lab3_4::func::~func()
{}

double lab3_4::func::getDif1()
{
    double dif = 0;
    int i = 2;
    dif = (y[i + 1] - y[i]) / (x[i + 1] - x[i]) + ((y[i + 2] - y[i + 1]) / (x[i + 2] - x[i + 1])
        - (y[i + 1] - y[i]) / (x[i + 1] - x[i])) / (x[i + 2] - x[i]) * (2 * xz - x[i] - x[i + 1]);
    return dif;
}

double lab3_4::func::getDif2()
{
    double dif = 0;
    int i = 2;
    dif = 2 * (((y[i + 2] - y[i + 1]) / (x[i + 2] - x[i + 1])
        - (y[i + 1] - y[i]) / (x[i + 1] - x[i])) / (x[i + 2] - x[i]));
    return dif;
}