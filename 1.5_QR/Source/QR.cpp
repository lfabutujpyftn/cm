#include<iostream>
#include<QR.h>
#include<utility>
#include<cmath>
lab1_5::system::system(int size)
{
    this->size = size;
    this->eps = 0.000001;
    this->matr = new std::vector<std::vector<double> >(size, std::vector<double>(size,0));
}
lab1_5::system::~system()
{
    delete this->matr;
}

void lab1_5::setVar12(system *arg)
{
    (*(arg->matr))[0][0] = 5;
    (*(arg->matr))[0][1] = -1;
    (*(arg->matr))[0][2] = -2;
    (*(arg->matr))[1][0] = -4;
    (*(arg->matr))[1][1] = 3;
    (*(arg->matr))[1][2] = -3;
    (*(arg->matr))[2][0] = -2;
    (*(arg->matr))[2][1] = -1;
    (*(arg->matr))[2][2] = 1;
}

void lab1_5::setSam(system *arg)
{
    (*(arg->matr))[0][0] = 1;
    (*(arg->matr))[0][1] = 3;
    (*(arg->matr))[0][2] = 1;
    (*(arg->matr))[1][0] = 1;
    (*(arg->matr))[1][1] = 1;
    (*(arg->matr))[1][2] = 4;
    (*(arg->matr))[2][0] = 4;
    (*(arg->matr))[2][1] = 3;
    (*(arg->matr))[2][2] = 1;
}

double sign(double arg)
{
    return (arg == 0) ? 0 : (arg < 0)? -1 :1;
}

lab1_5::QR* lab1_5::system::getQR()
{
    QR *str = new QR;

    str->R = new std::vector<std::vector<double> >(this->size, std::vector<double>(this->size, 0));
    
    std::vector<std::vector<std::vector<double> >* > arrH;

    std::vector<std::vector<double> >a((*(this->matr)));

    for (int i = 0; i < this->size - 1; ++i)
    {
        std::vector<std::vector<double> > aN(a);
        std::vector<double> v(this->size, 0);
        for (int j = i; j < this->size; ++j)
        {
            if (j == i)
            {
                double sum = 0;
                for (int z = j; z < this->size; ++z)
                {
                    sum += pow(a[z][i], 2);
                }
                sum = pow(sum, 0.5);
                v[j] = a[j][i] + sign(a[j][i]) * sum;
            }
            else
            {
                v[j] = a[j][i];
            }
        }

        /*for (int j = 0; j < this->size; ++j)
        {
            std::cout << v[j] << " ";
        }
        std::cout << " -v\n";*/

        std::vector<std::vector<double> > *H = new std::vector<std::vector<double> >(this->size, std::vector<double>(this->size, 0));
        for (int j = 0; j < this->size; ++j)
        {
            (*(H))[j][j] = 1;
        }
        double k = 0;
        for (int j = 0; j < this->size; ++j)
        {
            k += v[j] * v[j];
        }
        k = 2 / k;
        for (int q = 0; q < this->size; ++q)
        {
            for (int j = 0; j < this->size; ++j)
            {
                (*(H))[q][j] -= k * v[q] * v[j];
            }
        }
        
        for (int k = 0; k < this->size; ++k)
        {
            for (int j = 0; j < this->size; ++j)
            {
                double tmp = 0;
                for (int z = 0; z < this->size; ++z)
                {
                    tmp += (*(H))[z][k] * a[z][j];
                }
                aN[k][j] = tmp;
            }
        }

        /*for (int j = 0; j < this->size; ++j)
        {
            for (int k = 0; k < this->size; ++k)
            {
                std::cout << (*(H))[j][k] << " ";
            }
            std::cout << " -h\n";
        }

        for (int j = 0; j < this->size; ++j)
        {
            for (int k = 0; k < this->size; ++k)
            {
                std::cout << aN[j][k] << " ";
            }
            std::cout << " -a\n";
        }*/

        a = aN;

        
        arrH.push_back(H);
    }
    (*(str->R)) = a;

    str->Q = new std::vector<std::vector<double> >((*(arrH[0])));
    for (int k = 1; k < arrH.size(); ++k)
    {
        std::vector<std::vector<double> > tmpV((*(str->Q)));
        for (int i = 0; i < this->size; ++i)
        {
            for (int j = 0; j < this->size; ++j)
            {
                double tmp = 0;
                for (int z = 0; z < this->size; ++z)
                {
                    tmp += tmpV[i][z] * (*(arrH[k]))[z][j];
                }
                (*(str->Q))[i][j] = tmp;
            }
        }
    }
    for (int i = 0; i < arrH.size(); ++i)
    {
        delete arrH[i];
    }
    return str;
}