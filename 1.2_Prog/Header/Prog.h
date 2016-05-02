#pragma once
#include<vector>
namespace lab1_2
{
    class system
    {
    private:
        int size;
        std::vector<double> *a;
        std::vector<double> *b;
        std::vector<double> *c;
        std::vector<double> *ext;
    public:
        system(int size);
        virtual ~system();
        std::vector<double>* getResult();
        bool valid();
        void seta(int i, double val);
        void setb(int i, double val);
        void setc(int i, double val);
        void setext(int i, double val);
        friend void setVar12(system *arg);
    };
}