#pragma once
#include<vector>
namespace lab2_2
{
    class system
    {
    public:
        system();
        virtual ~system();
        std::vector<double>* getResultIter();
        std::vector<double>* getResultNewton();
    };
}