#include<iostream>
#include<DU.h>
#include<utility>
#include<cmath>

lab4_1::func::func()
{
    h = 0.1;
    a = 2;
    b = 3;
}

lab4_1::func::~func()
{}

double lab4_1::func::f(double x)
{
    return x*x + x + 1;
}

void lab4_1::func::getTable()
{
    for (double x = a; x <= b + h / 3; x += h)
    {
        std::cout << "x: " << x << " y: " << this->f(x) << "\n";
    }
}

void lab4_1::func::getEuler()
{
    double yi = 7;
    double fi = 5;
    for (double x = a; x <= b + h / 3; x += h)
    {
        std::cout << "x: " << x << " y: " << yi << "\n";
        if (x == a)
            yi = yi + h * fi;
        else
        {
            yi = yi + h * f(x, yi);
        }
    }
}

double lab4_1::func::f(double x, double y)
{
    return (2 * x * x + 2 * y) / (x * x - 1);
}

void lab4_1::func::getRK()
{
    double yi = 7;
    double fi = 5;
    for (double x = a; x <= b + h / 3; x += h)
    {
        std::cout << "x: " << x << " y: " << yi << "\n";
        double k1 = 0;
        if (x == a)
            k1 = h * fi;
        else
            k1 = h * f(x, yi);
        double k2 = h * f(x + 1.0 / 3 * h, yi + 1.0 / 3 * k1);
        double k3 = h * f(x + 2.0 / 3 * h, yi + 2.0 / 3 * k2);;
        double dy = 1.0 / 4 * (k1 + 3 * k3);
        /*std::cout << "k1: " << k1 << "\n";
        std::cout << "k2: " << k2 << "\n";
        std::cout << "k3: " << k3 << "\n";
        std::cout << "dy: " << dy << "\n";*/
        yi = yi + dy;
    }
}

void lab4_1::func::getAdams()
{
    double yi = 7;
    double fi = 5;
    int i = 1;
    std::vector<double> afi;
    afi.push_back(yi);
    for (double x = a; x <= b + h / 3 && i < 4; x += h, ++i)
    {
        //std::cout << "x: " << x << " y: " << yi << "\n";
        double k1 = 0;
        if (x == a)
            k1 = h * fi;
        else
            k1 = h * f(x, yi);
        double k2 = h * f(x + 1.0 / 3 * h, yi + 1.0 / 3 * k1);
        double k3 = h * f(x + 2.0 / 3 * h, yi + 2.0 / 3 * k2);;
        double dy = 1.0 / 4 * (k1 + 3 * k3);
        /*std::cout << "k1: " << k1 << "\n";
        std::cout << "k2: " << k2 << "\n";
        std::cout << "k3: " << k3 << "\n";
        std::cout << "dy: " << dy << "\n";*/
        yi = yi + dy;
        afi.push_back(yi);
    }
   // std::cout << "i: " << i << "\n";
    for (double x = a + 4 * h; x <= b + h / 3; x += h, ++i)
    {

        //std::cout << "i: " << i << "\n";
        yi = yi + h / 24 * (55 * f(x, afi[i - 1]) - 59 * f(x - 1 * h, afi[i - 2]) + 37 * f(x - 2*h, afi[i - 3])
            - 9 * f(x - 3*h, afi[i - 4]));
        afi.push_back(yi);
    }
    for (int i = 0; i < afi.size(); ++i)
    {
        std::cout << "x: " << a + i * h << " y: " <<  afi[i] << "\n";
    }
}

void lab4_1::func::getRumRob()
{
    std::vector<double> afi1;
    {
        double yi = 7;
        double fi = 5;
        int i = 1;
        afi1.push_back(yi);
        for (double x = a; x <= b + h / 3 && i < 4; x += h, ++i)
        {
          //  std::cout << "x: " << x << " y: " << yi << "\n";
            double k1 = 0;
            if (x == a)
                k1 = h * fi;
            else
                k1 = h * f(x, yi);
            double k2 = h * f(x + 1.0 / 3 * h, yi + 1.0 / 3 * k1);
            double k3 = h * f(x + 2.0 / 3 * h, yi + 2.0 / 3 * k2);;
            double dy = 1.0 / 4 * (k1 + 3 * k3);
            /*std::cout << "k1: " << k1 << "\n";
            std::cout << "k2: " << k2 << "\n";
            std::cout << "k3: " << k3 << "\n";
            std::cout << "dy: " << dy << "\n";*/
            yi = yi + dy;
            afi1.push_back(yi);
        }
        //std::cout << "i: " << i << "\n";
        for (double x = a + 4 * h; x <= b + h / 3; x += h, ++i)
        {

           // std::cout << "i: " << i << "\n";
            yi = yi + h / 24 * (55 * f(x, afi1[i - 1]) - 59 * f(x - 1 * h, afi1[i - 2]) + 37 * f(x - 2 * h, afi1[i - 3])
                - 9 * f(x - 3 * h, afi1[i - 4]));
            afi1.push_back(yi);
        }
        /*for (int i = 0; i < afi1.size(); ++i)
        {
            std::cout << afi1[i] << " afi\n";
        }*/
    }
    std::vector<double> afi2;
    {
        double yi = 7;
        double fi = 5;
        int i = 1;
        afi2.push_back(yi);
        double nh = h / 2;
        for (double x = a; x <= b + nh / 3 && i < 4; x += nh, ++i)
        {
          //  std::cout << "x: " << x << " y: " << yi << "\n";
            double k1 = 0;
            if (x == a)
                k1 = nh * fi;
            else
                k1 = nh * f(x, yi);
            double k2 = nh * f(x + 1.0 / 3 * nh, yi + 1.0 / 3 * k1);
            double k3 = nh * f(x + 2.0 / 3 * nh, yi + 2.0 / 3 * k2);;
            double dy = 1.0 / 4 * (k1 + 3 * k3);
            /*std::cout << "k1: " << k1 << "\n";
            std::cout << "k2: " << k2 << "\n";
            std::cout << "k3: " << k3 << "\n";
            std::cout << "dy: " << dy << "\n";*/
            yi = yi + dy;
            afi2.push_back(yi);
        }
        //std::cout << "i: " << i << "\n";
        for (double x = a + 4 * nh; x <= b + nh / 3; x += nh, ++i)
        {

          //  std::cout << "i: " << i << "\n";
            yi = yi + nh / 24 * (55 * f(x, afi2[i - 1]) - 59 * f(x - 1 * nh, afi2[i - 2]) + 37 * f(x - 2 * nh, afi2[i - 3])
                - 9 * f(x - 3 * nh, afi2[i - 4]));
            afi2.push_back(yi);
        }
        /*for (int i = 0; i < afi2.size(); ++i)
        {
            std::cout << afi2[i] << " afi\n";
        }*/
    }
    for (int i = 0; i < afi1.size(); ++i)
    {
        std::cout << "x: " << a + i * h << " y: " << afi1[i] + (afi1[i] - afi2[2 * i]) / 15 << "\n";
    }
}