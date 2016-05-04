#pragma once
#include<vector>
namespace lab3_3
{
    class MNK
    {
    private:
        std::vector<double> *x;
        std::vector<double> *f;
    public:
        MNK();
        virtual ~MNK();
        std::vector<double>* getPolynom1();
        double getError1(std::vector<double>*);
        std::vector<double>* getPolynom2();
        double getError2(std::vector<double>*);
    };
}