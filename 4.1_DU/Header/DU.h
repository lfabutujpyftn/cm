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
        double f(double x, double y, double z);
        std::vector<double> *sth;
        std::vector<double> *st2h;

    public:
        func();
        virtual ~func();
        void getTable();
        void getEuler();
        void getRK();
        void getAdams();
        void getRumRob(int p);
        void printResult();
    };
}