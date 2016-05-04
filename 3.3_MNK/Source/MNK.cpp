#include<iostream>
#include<MNK.h>
#include<LU.h>
#include<utility>
#include<cmath>
lab3_3::MNK::MNK()
{
    this->x = new std::vector < double >;
    this->x->push_back(0.1);
    this->x->push_back(0.5);
    this->x->push_back(0.9);
    this->x->push_back(1.3);
    this->x->push_back(1.7);
    this->x->push_back(2.1);
    this->f = new std::vector < double >;
    this->f->push_back(-2.2026);
    this->f->push_back(-0.19315);
    this->f->push_back(0.79464);
    this->f->push_back(1.5624);
    this->f->push_back(2.2306);
    this->f->push_back(2.8419);
}
lab3_3::MNK::~MNK()
{
    delete this->x;
    delete this->f;
}
std::vector<double>* lab3_3::MNK::getPolynom1()
{
    lab1_1::system sys(2);
    double tmp = 0;
    for (int i = 0; i < this->f->size(); ++i)
    {
        tmp += (*(this->f))[i];
    }
    sys.setExt(0, tmp);
    tmp = 0;
    for (int i = 0; i < this->f->size(); ++i)
    {
        tmp += (*(this->f))[i] * (*(this->x))[i];
    }
    sys.setExt(1, tmp);
    sys.setSys(0, 0, 6);
    tmp = 0;
    for (int i = 0; i < this->f->size(); ++i)
    {
        tmp += (*(this->x))[i];
    }
    sys.setSys(0, 1, tmp);
    sys.setSys(1, 0, tmp);
    tmp = 0;
    for (int i = 0; i < this->f->size(); ++i)
    {
        tmp += (*(this->x))[i] * (*(this->x))[i];
    }
    sys.setSys(1, 1, tmp);
    lab1_1::LU *lu = sys.getLU();
    std::vector<double>* res = sys.getResult(lu);
    /*for (int i = 0; i < res->size(); ++i)
    {
        std::cout << "r " << (*(res))[i] << "\n";
    }*/
    return res;
}

double lab3_3::MNK::getError1(std::vector<double>* arg)
{
    double res = 0;
    for (int i = 0; i < this->x->size(); ++i)
    {
        res += pow((*(arg))[0] + (*(arg))[1] * (*(this->x))[i] - (*(this->f))[i], 2);
    }
    return res;
}

std::vector<double>* lab3_3::MNK::getPolynom2()
{
    lab1_1::system sys(3);
    double tmp = 0;
    for (int i = 0; i < this->f->size(); ++i)
    {
        tmp += (*(this->f))[i];
    }
    sys.setExt(0, tmp);
    tmp = 0;
    for (int i = 0; i < this->f->size(); ++i)
    {
        tmp += (*(this->f))[i] * (*(this->x))[i];
    }
    sys.setExt(1, tmp);
    tmp = 0;
    for (int i = 0; i < this->f->size(); ++i)
    {
        tmp += (*(this->f))[i] * (*(this->x))[i] * (*(this->x))[i];
    }
    sys.setExt(2, tmp);
    sys.setSys(0, 0, 6);
    tmp = 0;
    for (int i = 0; i < this->f->size(); ++i)
    {
        tmp += (*(this->x))[i];
    }
    sys.setSys(0, 1, tmp);
    sys.setSys(1, 0, tmp);
    tmp = 0;
    for (int i = 0; i < this->f->size(); ++i)
    {
        tmp += (*(this->x))[i] * (*(this->x))[i];
    }
    sys.setSys(1, 1, tmp);
    sys.setSys(0, 2, tmp);
    sys.setSys(2, 0, tmp);
    tmp = 0;
    for (int i = 0; i < this->f->size(); ++i)
    {
        tmp += (*(this->x))[i] * (*(this->x))[i] * (*(this->x))[i];
    }
    sys.setSys(1, 2, tmp);
    sys.setSys(2, 1, tmp);
    tmp = 0;
    for (int i = 0; i < this->f->size(); ++i)
    {
        tmp += (*(this->x))[i] * (*(this->x))[i] * (*(this->x))[i] * (*(this->x))[i];
    }
    sys.setSys(2, 2, tmp);
    lab1_1::LU *lu = sys.getLU();
    std::vector<double>* res = sys.getResult(lu);
    /*for (int i = 0; i < res->size(); ++i)
    {
        std::cout << "r " << (*(res))[i] << "\n";
    }*/
    return res;
}

double lab3_3::MNK::getError2(std::vector<double>* arg)
{
    double res = 0;
    for (int i = 0; i < this->x->size(); ++i)
    {
        res += pow((*(arg))[0] + (*(arg))[1] * (*(this->x))[i] + (*(arg))[2] * (*(this->x))[i] * (*(this->x))[i] - (*(this->f))[i], 2);
    }
    return res;
}