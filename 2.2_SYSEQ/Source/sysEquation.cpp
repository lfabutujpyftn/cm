#include<iostream>
#include<sysEquation.h>
#include<utility>
#include<cmath>
lab2_2::system::system()
{

}
lab2_2::system::~system()
{

}
std::vector<double>* lab2_2::system::getResultIter()
{
    std::vector<double>* res = new std::vector<double>(2);
    (*(res))[0] = 2;
    (*(res))[1] = 4;
    double q = 0.99;
    double eps = 0.000001;
    int i = 0;
    while (i < 1000)
    {
        double newRes0 = 3 + cos((*(res))[1]);
        double newRes1 = 3 + sin((*(res))[0]);
        if ((q / (1 - q)) * pow(pow((*(res))[0] - newRes0, 2) + pow((*(res))[1] - newRes1, 2), 0.5) < eps)
        {
            (*(res))[0] = newRes0;
            (*(res))[1] = newRes1;

            std::cout << "i: " << i << " x1: " << newRes0 << " x2: " << newRes1 << "\n";
            break;
            //i = 1001;
        }
        (*(res))[0] = newRes0;
        (*(res))[1] = newRes1;
        ++i;
        //std::cout << "i: " << i << " x1: " << newRes0 << " x2: " << newRes1 << "\n";
    }
   // std::cout << "res: " << res << " i: " << i << "\n";
    return res;
}

std::vector<double>* lab2_2::system::getResultNewton()
{

    std::vector<double>* res = new std::vector<double>(2);
    (*(res))[0] = 2;
    (*(res))[1] = 4;
    double q = 0.99;
    double eps = 0.000001;
    int i = 0;
    while (i < 1000)
    {

        double newRes0 = 3 + cos((*(res))[1]);
        double newRes1 = 3 + sin((*(res))[0]);
        if ((q / (1 - q)) * pow(pow((*(res))[0] - newRes0, 2) + pow((*(res))[1] - newRes1, 2), 0.5) < eps)
        {
            (*(res))[0] = newRes0;
            (*(res))[1] = newRes1;

            std::cout << "i: " << i << " x1: " << newRes0 << " x2: " << newRes1 << "\n";
            break;
            //i = 1001;
        }
        (*(res))[0] = newRes0;
        (*(res))[1] = newRes1;
        ++i;
        //std::cout << "i: " << i << " x1: " << newRes0 << " x2: " << newRes1 << "\n";
    }
    // std::cout << "res: " << res << " i: " << i << "\n";
    return res;
}
