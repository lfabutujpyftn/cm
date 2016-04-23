#include<iostream>
#include<LU.h>
void print(lab1_1::LU* lu)
{
    std::cout << "L:\n";
    for (int i = 0; i < lu->L->size(); ++i)
    {
        for (int j = 0; j < lu->L->size(); ++j)
        {
            std::cout << (*(lu->L))[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "U:\n";
    for (int i = 0; i < lu->L->size(); ++i)
    {
        for (int j = 0; j < lu->L->size(); ++j)
        {
            std::cout << (*(lu->U))[i][j] << " ";
        }
        std::cout << "\n";
    }
}
void print(std::vector<double> *arg)
{
    std::cout << "Res:\n";
    for (int i = 0; i < arg->size(); ++i)
    {
        std::cout << (*(arg))[i] << " ";
    }
    std::cout << "\n";
}
void print(std::vector<std::vector<double> > *arg)
{
    std::cout << "Rev:\n";
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
    lab1_1::system sys(4);
    lab1_1::setVar12(&sys);
    lab1_1::LU* lu = sys.getLU();
    std::vector<double>* res = sys.getResult(lu);
    std::vector<std::vector<double> >* rev = sys.getRevers();
    std::cout << "Det:\n" <<  sys.det(lu) << "\n";
    print(rev);
    print(lu);
    print(res);
    delete lu;
    delete res;
    delete rev;
    system("pause");
    return 0;
}