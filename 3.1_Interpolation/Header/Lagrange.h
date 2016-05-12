#pragma once
#include<vector>
namespace lab3_1_lagr
{
    class polynom
    {
    private:
        std::vector<std::pair<double, double> > *t;
        std::vector<std::pair<double, double> > *ti;
        double xe;
        double getlagr(int i, double x);
    public:
        polynom();
        virtual ~polynom();
        void setA();
        void setB();
        void initInterpolation();
        double getvalue(double x);
        void val();
    };
}