#include<iostream>
#include<Iter.h>
#include<Zeid.h>
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
    lab1_3_iter::system sys1(4);
    lab1_3_iter::setVar12(&sys1);
    sys1.lead();
    std::vector<double> *res1 = sys1.getResult();
    print(res1);
    delete res1;

    lab1_3_zeid::system sys2(4);
    lab1_3_zeid::setVar12(&sys2);
    sys2.lead();
    std::vector<double> *res2 = sys2.getResult();
    print(res2);
    delete res2;

    system("pause");
    return 0;
}