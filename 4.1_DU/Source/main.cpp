#include<iostream>
#include<DU.h>
int main()
{
    lab4_1::func f;
    std::cout << "=======\n";
    f.getTable();
    std::cout << "=======\n";
    f.getEuler();
    std::cout << "=======\n";
    f.getRK();
    std::cout << "=======\n";
    f.getAdams();
    std::cout << "=======\n";
    f.getRumRob();
    std::cout << "=======\n";
    system("pause");
    return 0;
}