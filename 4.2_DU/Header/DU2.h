#pragma once
#include<vector>
namespace lab4_2
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
        void getRes1();
        void getRes2();
        friend class DU;
    };
    class DU
    {
    private:
        func *arg;
    public:
        DU(func *arg);
        virtual ~DU();
        double getValue(double nu, bool p);
    };
}