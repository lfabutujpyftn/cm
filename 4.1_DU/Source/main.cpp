#include<iostream>
#include<DU.h>
int main()
{
    lab4_1::func f;
    std::cout << "=======\n";
    f.getTable();
    f.printResult();
    //f.getRumRob(1);
    /*std::cout << "=======\n";
    f.getEuler();
    f.printResult();
    f.getRumRob(1);*/
    std::cout << "=======\n";
    f.getRK();
    f.printResult();
    f.getRumRob(3);
    /*std::cout << "=======\n";
    f.getAdams();
    std::cout << "=======\n";
    f.getRumRob();
    std::cout << "=======\n";*/
    system("pause");
    return 0;
}