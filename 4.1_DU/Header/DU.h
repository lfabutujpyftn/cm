#pragma once
#include<vector>
namespace lab4_1
{
    class func
    {
    private:
        double h;
        double a;
        double b;
        double f(double x);
        double f(double x, double y);
    public:
        func();
        virtual ~func();
        void getTable();
        void getEuler();
        void getRK();
        void getAdams();
        void getRumRob();
    };
}