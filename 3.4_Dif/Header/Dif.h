#pragma once
#include<vector>
namespace lab3_4
{
    class func
    {
    private:
        double xz;
        std::vector<double> x;
        std::vector<double> y;
    public:
        func();
        virtual ~func();
        double getDif1();
        double getDif2();
    };
}