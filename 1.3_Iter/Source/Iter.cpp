#include<iostream>
#include<Iter.h>
#include<utility>
#include<cmath>
lab1_3_iter::system::system(int size)
{
    this->size = size;
    this->eps = 0.000001;
    this->sys = new std::vector<std::vector<double> >(size, std::vector<double>(size, 0));
    this->ext = new std::vector<double>(size, 0);
    this->b = new std::vector<double>(size, 0);
    this->a = new std::vector<std::vector<double> >(size, std::vector<double>(size, 0));
}
lab1_3_iter::system::~system()
{
    delete this->sys;
    delete this->ext;
}

void lab1_3_iter::setVar12(system *arg)
{
    (*(arg->sys))[0][0] = 14;
    (*(arg->sys))[0][1] = -4;
    (*(arg->sys))[0][2] = -2;
    (*(arg->sys))[0][3] = 3;
    (*(arg->sys))[1][0] = -3;
    (*(arg->sys))[1][1] = 23;
    (*(arg->sys))[1][2] = -6;
    (*(arg->sys))[1][3] = -9;
    (*(arg->sys))[2][0] = -7;
    (*(arg->sys))[2][1] = -8;
    (*(arg->sys))[2][2] = 21;
    (*(arg->sys))[2][3] = -5;
    (*(arg->sys))[3][0] = -2;
    (*(arg->sys))[3][1] = -2;
    (*(arg->sys))[3][2] = 8;
    (*(arg->sys))[3][3] = 18;

    (*(arg->ext))[0] = 38;
    (*(arg->ext))[1] = -195;
    (*(arg->ext))[2] = -27;
    (*(arg->ext))[3] = 142;
}

void lab1_3_iter::system::lead()
{
    for (int i = 0; i < this->size; ++i)
    {
        (*(this->b))[i] = (*(this->ext))[i] / (*(this->sys))[i][i];
    }
    for (int i = 0; i < this->size; ++i)
    {
        for (int j = 0; j < this->size ; ++j)
        {
            if (i == j)
                (*(this->a))[i][j] = 0;
            else
                (*(this->a))[i][j] = -1 * (*(this->sys))[i][j] / (*(this->sys))[i][i];
        }
    }
}

std::vector<double>* lab1_3_iter::system::getResult()
{
    std::vector<double> *res = new std::vector<double>((*(this->b)));

    double alph = 0;
    for (int i = 0; i < this->size; ++i)
    {
        for (int j = 0; j < this->size; ++j)
        {
            alph += pow((*(this->a))[i][j], 2);
        }
    }
    alph = pow(alph, 0.5);
    if (alph >= 1)
    {
        std::cout << "Error: alph = " << alph << "\n";
        return res;
    }
    alph = alph / (1 - alph);
    int count = 0;
    while (true)
    {
        count++;
        if (count >= 1000)
        {
            std::cout << "Error: count = " << count << "\n";
            break;
        }
        std::vector<double> tmp(*res);
        for (int i = 0; i < this->size; ++i)
        {
            double value = 0;
            for (int j = 0; j < this->size; ++j)
            {
                value += (*(this->a))[i][j] * tmp[j];
            }
            (*(res))[i] = (*(this->b))[i] + value;
        }
        double x = 0;
        for (int i = 0; i < this->size; ++i)
        {
            x += pow((*(res))[i] - tmp[i], 2);
        }
        x = pow(x, 0.5);
        if (alph * x < this->eps)
        {
            std::cout << "Count = " << count << "\n";
            break;
        }
    }
    return res;
}

void lab1_3_iter::system::setSys(int i, int j, double arg)
{
    (*(this->sys))[i][j] = arg;
}

void lab1_3_iter::system::setExt(int i, double arg)
{
    (*(this->ext))[i] = arg;
}
