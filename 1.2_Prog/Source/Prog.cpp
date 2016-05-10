#include<iostream>
#include<Prog.h>
#include<utility>
#include<cmath>
lab1_2::system::system(int size)
{
    this->size = size;
    this->a = new std::vector<double>(size, 0);
    this->b = new std::vector<double>(size, 0);
    this->c = new std::vector<double>(size, 0);
    this->ext = new std::vector<double>(size, 0);
}
lab1_2::system::~system()
{
    delete this->a;
    delete this->b;
    delete this->c;
    delete this->ext;
}

void lab1_2::setVar12(system *arg)
{

    (*(arg->a))[0] = 0;
    (*(arg->a))[1] = 1;
    (*(arg->a))[2] = -2;
    (*(arg->a))[3] = 3;
    (*(arg->a))[4] = 8;
    (*(arg->b))[0] = -11;
    (*(arg->b))[1] = -8;
    (*(arg->b))[2] = -11;
    //(*(arg->b))[2] = 0;
    (*(arg->b))[3] = -14;
    (*(arg->b))[4] = 10;
    (*(arg->c))[0] = 9;
    (*(arg->c))[1] = 1;
    (*(arg->c))[2] = 5;
    (*(arg->c))[3] = 7;
    (*(arg->c))[4] = 0;

    (*(arg->ext))[0] = -114;
    (*(arg->ext))[1] = 81;
    (*(arg->ext))[2] = -8;
    (*(arg->ext))[3] = -38;
    (*(arg->ext))[4] = 144;
}


std::vector<double>* lab1_2::system::getResult()
{
    std::vector<double> *res = new std::vector<double>(this->size, 0);
    std::vector<double> P(this->size, 0);
    std::vector<double> Q(this->size, 0);

    /*if (!(this->valid()))
    {
        return nullptr;
    }*/

    P[0] = -1 * (*(this->c))[0] / (*(this->b))[0];
    Q[0] = (*(this->ext))[0] / (*(this->b))[0];

    for (int i = 1; i < this->a->size(); ++i)
    {
        P[i] = -1 * (*(this->c))[i] / ((*(this->b))[i] + (*(this->a))[i] * P[i - 1]);
        Q[i] = ((*(this->ext))[i] - (*(this->a))[i] * Q[i - 1]) / ((*(this->b))[i] + (*(this->a))[i] * P[i - 1]);
    }

    (*(res))[P.size() - 1] = Q[P.size() - 1];

    for (int i = P.size() - 2; i >= 0; --i)
    {
        (*(res))[i] = P[i] * (*(res))[i + 1] + Q[i];
    }

    return res;
}

bool lab1_2::system::valid()
{
    for (int i = 1; i < this->c->size() - 1; ++i)
    {
        if ((*(this->a))[i] == 0 || (*(this->c))[i] == 0)
            return false;
    }
    for (int i = 0; i < this->c->size(); ++i)
    {
        if (abs((*(this->b))[i]) < abs((*(this->a))[i]) + abs((*(this->c))[i]))
            return false;
    }
    return true;
}

void lab1_2::system::seta(int i, double val)
{
    (*(this->a))[i] = val;
}
void lab1_2::system::setb(int i, double val)
{
    (*(this->b))[i] = val;
}
void lab1_2::system::setc(int i, double val)
{
    (*(this->c))[i] = val;
}
void lab1_2::system::setext(int i, double val)
{
    (*(this->ext))[i] = val;
}