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
        double f(double x, double y, double z);
        std::vector<double> *sth;
        std::vector<double> *st2h;
        

        
    public:
        func();
        virtual ~func();
        void getTable();
        void getRes1();
        void getRes2();
        void printResult();
        void getRumRob(int p); 
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