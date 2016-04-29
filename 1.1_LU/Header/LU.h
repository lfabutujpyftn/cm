#pragma once
#include<vector>
namespace lab1_1
{

    struct LU
    {
        std::vector<std::vector<double> > *L;
        std::vector<std::vector<double> > *U;
        std::vector<std::pair<int, int> > *p;
    };
    class system
    {
    private:
        int size;
        std::vector<std::vector<double> > *sys;
        std::vector<double> *ext;

        void swapline(std::vector<std::vector<double> > *arg, int i, int j);
        void swapcolum(std::vector<std::vector<double> > *arg, int i, int j);
    public:
        system(int size);
        virtual ~system();
        LU* getLU();
        std::vector<double>* getResult(LU* lu);
        std::vector<std::vector<double> >* getRevers();
        void setSys(int i, int j, double arg);
        void setExt(int i, double arg);
        double det(LU* lu);
        friend void setVar1(system *arg);
        friend void setVar12(system *arg);
        friend void print(system *arg);


    };
}