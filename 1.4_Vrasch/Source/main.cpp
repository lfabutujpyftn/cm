#include<iostream>
#include<Vrasch.h>
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
    lab1_4::system sys(3);
    lab1_4::setVar12(&sys);
    //lab1_4::setSam(&sys);
    lab1_4::LamVec* res = sys.getResult();
    print(res->lambda);
    print(res->vec);
    delete res;
    system("pause");
    return 0;
}