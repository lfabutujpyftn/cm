#pragma once
#include<vector>
namespace lab1_4
{
    struct LamVec
    {
        std::vector<double>* lambda;
        std::vector<std::vector<double> >* vec;
    };
    class system
    {
    private:
        int size;
        double eps;
        std::vector<std::vector<double> > *a;
    public:
        system(int size);
        virtual ~system();
        LamVec* getResult();
        friend void setVar12(system *arg);
        friend void setSam(system *arg);
    };
}