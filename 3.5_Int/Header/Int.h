#pragma once
#include<vector>
namespace lab3_5
{
    class func
    {
    private:
        double x0;
        double xk;
        double h1;
        double h2;
        double f(double x);
    public:
        func();
        virtual ~func();
        double getIntPh1();
        double getIntPh2();
        double getIntTh1();
        double getIntTh2();
        double getIntSh1();
        double getIntSh2();
        double getRumbRombP();
        double getRumbRombT();
        double getRumbRombS();
    };
}