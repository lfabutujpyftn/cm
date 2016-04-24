#include<iostream>
#include<Iter.h>
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
        for (int j = 0; j < (*(arg))[i].size(); ++j)
        {
            std::cout << (*(arg))[i][j] << "\t";
        }
        std::cout << "\n";
    }
}
int main()
{
    lab1_3_iter::system sys(4);
    lab1_3_iter::setVar12(&sys);
    sys.lead();
    std::vector<double> *res = sys.getResult();
    print(res);
    delete res;
    system("pause");
    return 0;
}