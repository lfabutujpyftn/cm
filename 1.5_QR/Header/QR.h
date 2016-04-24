#pragma once
#include<vector>
namespace lab1_5
{
    struct QR
    {
        std::vector<std::vector<double> >* Q;
        std::vector<std::vector<double> >* R;
    };
    class system
    {
    private:
        int size;
        double eps;
        std::vector<std::vector<double> > *matr;
    public:
        system(int size);
        virtual ~system();
        QR* getQR();
        friend void setVar12(system *arg);
        friend void setSam(system *arg);
    };
}