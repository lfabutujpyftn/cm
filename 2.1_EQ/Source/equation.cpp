#include<iostream>
#include<equation.h>
#include<utility>
#include<cmath>
lab2_1::equation::equation()
{

}
lab2_1::equation::~equation()
{

}
double lab2_1::equation::getResultIter()
{
    double res = 3.5;
    double q = 0.84;
    double eps = 0.000001;
    int i = 0;
    while (i < 1000)
    {
        double newRes = res - 0.01 * (pow(3,res) - 5 * res * res + 1);
        if ((q / (1 - q)) * fabs(res - newRes) < eps)
        {
            res = newRes;
            break;
            //i = 1001;
        }
        res = newRes;
        ++i;
        //std::cout << res << "\n";
    }
    std::cout << "res: " << res << " i: " << i << "\n";
    return res;
}

double lab2_1::equation::getResultNewton()
{
    double res = 4.5;
    double eps = 0.000001;
    int i = 0;
    while (i < 1000)
    {
        double newRes = res - (pow(3, res) - 5 * res * res + 1) / (pow(3, res) * log(3) - 10 * res);
        if (fabs(res - newRes) < eps)
        {
            res = newRes;
            break;
            //i = 1001;
        }
        res = newRes;
        ++i;

        //std::cout << "res: " << res << " i: " << i << "\n";
    }
    std::cout << "res: " << res << " i: " << i << "\n";
    return res;
}
