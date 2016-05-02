#pragma once
#include<vector>
namespace lab3_2
{
    class spline
    {
    private:
        std::vector<double> *x;
        std::vector<double> *f;
        std::vector<double> *a;
        std::vector<double> *b;
        std::vector<double> *c;
        std::vector<double> *d;
    public:
        spline();
        virtual ~spline();
        void initInterpolation();
        double getvalue(double x);
    };
}