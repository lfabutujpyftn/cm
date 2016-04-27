#pragma once
#include<vector>
namespace lab2_1
{
    class equation
    {
    public:
        equation();
        virtual ~equation();
        double getResultIter();
        double getResultNewton();
    };
}