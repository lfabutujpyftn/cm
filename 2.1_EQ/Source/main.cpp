#include<iostream>
#include<equation.h>
int main()
{
    lab2_1::equation eq;
    double res1 = eq.getResultIter();
    double res2 = eq.getResultNewton();
    system("pause");
    return 0;
}