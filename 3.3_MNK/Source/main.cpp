#include<iostream>
#include<MNK.h>
int main()
{
    lab3_3::MNK mnk;
    std::vector<double>* res1 = mnk.getPolynom1();
    double err1 = mnk.getError1(res1);
    std::cout << "Error1: " << err1 << "\n";
    delete res1;
    std::vector<double>* res2 = mnk.getPolynom2();
    double err2 = mnk.getError2(res2);
    std::cout << "Error2: " << err2 << "\n";
    delete res2;
    system("pause");
    return 0;
}