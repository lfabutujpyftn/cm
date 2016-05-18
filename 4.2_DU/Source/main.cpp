#include<iostream>
#include<DU2.h>
int main()
{
    lab4_2::func f;
    std::cout << "=======\n";
    f.getTable();
    std::cout << "=======\n";
    f.getRes1();
    f.printResult();
    f.getRumRob(1);
    /*std::cout << "=======\n";
    f.getRes2();
    f.printResult();
    f.getRumRob(1);
    std::cout << "=======\n";*/
    system("pause");
    return 0;
}