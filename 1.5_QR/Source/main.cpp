#include<iostream>
#include<QR.h>
void print(std::vector<double> *arg)
{
    std::cout << "Lam:\n";
    for (int i = 0; i < arg->size(); ++i)
    {
        std::cout << (*(arg))[i] << " ";
    }
    std::cout << "\n";
}
void print(std::vector<std::vector<double> > *arg)
{
    std::cout << "Vec:\n";
    for (int i = 0; i < arg->size(); ++i)
    {
        for (int j = 0; j < arg->size(); ++j)
        {
            std::cout << (*(arg))[i][j] << " ";
        }
        std::cout << "\n";
    }
}
int main()
{
    lab1_5::system sys(3);
    lab1_5::setVar12(&sys);
    //lab1_5::setSam(&sys);
    //lab1_5::QR* qr = sys.getQR();
    //print(qr->Q);
    //print(qr->R);
    //delete qr;
    std::vector<double> *res = sys.getResult();
    print(res);
    delete res;
    system("pause");
    return 0;
}