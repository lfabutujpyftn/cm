#include<iostream>
#include<sysEquation.h>
int main()
{
    lab2_2::system eq;
    std::vector<double>* res1 = eq.getResultIter();
    std::vector<double>* res2 = eq.getResultNewton();
    delete res1;
    system("pause");
    return 0;
}