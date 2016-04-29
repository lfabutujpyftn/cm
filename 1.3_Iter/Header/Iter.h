#pragma once
#include<vector>
namespace lab1_3_iter
{
    class system
    {
    private:
        int size;
        std::vector<std::vector<double> > *sys;
        std::vector<std::vector<double> > *a;
        std::vector<double> *b;
        std::vector<double> *ext;
        double eps;
    public:
        system(int size);
        virtual ~system();
        void lead();
        void setSys(int i, int j, double arg);
        void setExt(int i, double arg);
        std::vector<double>* getResult();
        friend void setVar12(system *arg);
    };
}
