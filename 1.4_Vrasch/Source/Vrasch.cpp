#include<iostream>
#include<Vrasch.h>
#include<utility>
#include<cmath>
lab1_4::system::system(int size)
{
    this->size = size;
    this->eps = 0.000001;
    this->a = new std::vector<std::vector<double> >(size, std::vector<double>(size,0));
}
lab1_4::system::~system()
{
    delete this->a;
}

void lab1_4::setVar12(system *arg)
{
    (*(arg->a))[0][0] = 7;
    (*(arg->a))[0][1] = 3;
    (*(arg->a))[0][2] = -1;
    (*(arg->a))[1][0] = 3;
    (*(arg->a))[1][1] = -7;
    (*(arg->a))[1][2] = -8;
    (*(arg->a))[2][0] = -1;
    (*(arg->a))[2][1] = -8;
    (*(arg->a))[2][2] = -2;
}

void lab1_4::setSam(system *arg)
{
    (*(arg->a))[0][0] = 4;
    (*(arg->a))[0][1] = 2;
    (*(arg->a))[0][2] = 1;
    (*(arg->a))[1][0] = 2;
    (*(arg->a))[1][1] = 5;
    (*(arg->a))[1][2] = 3;
    (*(arg->a))[2][0] = 1;
    (*(arg->a))[2][1] = 3;
    (*(arg->a))[2][2] = 6;
}

lab1_4::LamVec* lab1_4::system::getResult()
{
    LamVec *str = new LamVec;
    std::vector<double> *res = new std::vector<double>(this->size, 0);
    

    std::vector<std::vector<std::vector<double> >*> vecU;

    double exz = 1000;

    std::vector<std::vector<double> > aNew((*(this->a)));
    while (exz > this->eps)
    {
        std::vector<std::vector<double> > aCopy(aNew);

        std::vector<std::vector<double> > *u = new std::vector<std::vector<double> >(this->size, std::vector<double>(size, 0));
        for (int i = 0; i < this->size; ++i)
            (*(u))[i][i] = 1;
    
        double max = aCopy[0][1];
        int iMax = 0;
        int jMax = 1;
        for (int i = 0; i < this->size; ++i)
        {
            for (int j = 0; j < this->size; ++j)
            {
                if (i == j)
                    continue;
                if (max < fabs(aCopy[i][j]))
                {
                    max = fabs(aCopy[i][j]);
                    iMax = i;
                    jMax = j;
                }
            }
        }
        (*(u))[iMax][jMax] = -sin(0.5 * atan(2 * aCopy[iMax][jMax] / (aCopy[iMax][iMax] - aCopy[jMax][jMax])));
        (*(u))[jMax][iMax] = sin(0.5 * atan(2 * aCopy[iMax][jMax] / (aCopy[iMax][iMax] - aCopy[jMax][jMax])));
        (*(u))[iMax][iMax] = cos(0.5 * atan(2 * aCopy[iMax][jMax] / (aCopy[iMax][iMax] - aCopy[jMax][jMax])));
        (*(u))[jMax][jMax] = cos(0.5 * atan(2 * aCopy[iMax][jMax] / (aCopy[iMax][iMax] - aCopy[jMax][jMax])));

        /*for (int i = 0; i < this->size; ++i)
        {
            for (int j = 0; j < this->size; ++j)
            {
                std::cout << (*(u))[i][j] << " ";
            }
            std::cout << "\n";
        }
        std::cout << iMax << " " << jMax << "\n";*/

        std::vector<std::vector<double> > tmpA(aCopy);
        for (int i = 0; i < this->size; ++i)
        {
            for (int j = 0; j < this->size; ++j)
            {
                double tmp = 0;
                for (int z = 0; z < this->size; ++z)
                {
                    tmp += (*(u))[z][i] * aCopy[z][j];
                }
                tmpA[i][j] = tmp;
            }
        }
        for (int i = 0; i < this->size; ++i)
        {
            for (int j = 0; j < this->size; ++j)
            {
                double tmp = 0;
                for (int z = 0; z < this->size; ++z)
                {
                    tmp += tmpA[i][z] * (*(u))[z][j];
                }
                aNew[i][j] = tmp;
            }
        }
        exz = 0;
        for (int i = 0; i < this->size; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                exz += pow(aNew[i][j], 2);
            }
        }
        exz = pow(exz, 0.5);
        std::cout << exz << " -exz\n";

        /*for (int i = 0; i < this->size; ++i)
        {
            for (int j = 0; j < this->size; ++j)
            {
                std::cout << aNew[i][j] << " ";
            }
            std::cout << "\n";
        }

        std::cout << "\n";
        std::cout << "=============\n";
        std::cout << "\n";
        _sleep(1000);*/

        vecU.push_back(u);
    }
    
    str->vec = new std::vector<std::vector<double> >((*(vecU[0])));
    for (int k = 1; k < vecU.size(); ++k)
    {
        std::vector<std::vector<double> > tmpV((*(str->vec)));
        for (int i = 0; i < this->size; ++i)
        {
            for (int j = 0; j < this->size; ++j)
            {
                double tmp = 0;
                for (int z = 0; z < this->size; ++z)
                {
                    tmp += tmpV[i][z] * (*(vecU[k]))[z][j];
                }
                (*(str->vec))[i][j] = tmp;
            }
        }
    }
    for (int i = 0; i < vecU.size(); ++i)
    {
        delete vecU[i];
    }

    for (int i = 0; i < this->size; ++i)
    {
        (*(res))[i] = aNew[i][i];
    }
    str->lambda = res;
    return str;
}