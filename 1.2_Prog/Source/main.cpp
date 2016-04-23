#include<iostream>
#include<Prog.h>
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
    lab1_2::system sys(5);
    lab1_2::setVar12(&sys);
    std::vector<double>* res = sys.getResult();
    if (res == nullptr)
    {
        return 1;
    }
    print(res);
    delete res;
    system("pause");
    return 0;
}