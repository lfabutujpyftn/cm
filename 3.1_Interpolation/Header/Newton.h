#pragma once
#include<vector>
namespace lab3_1_newt
{
    class polynom
    {
    private:
        std::vector<std::pair<double, double> > *t;
        std::vector<std::pair<double, double> > *ti;
        double xe;
        //double getlagr(int i, double x);
    public:
        polynom();
        virtual ~polynom();
        void setA();
        void setB();
        void initInterpolation();
        double getvalue(double x);
        double f2(int i, int j);
        double f3(int i, int j, int k);
        double f4(int i, int j, int k, int z);
    };
}