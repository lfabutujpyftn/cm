#include<iostream>
#include<LU.h>
#include<utility>
#include<cmath>
lab1_1::system::system(int size)
{
    this->size = size;
    this->sys = new std::vector<std::vector<double> >(size, std::vector<double>(size, 0));
    this->ext = new std::vector<double>(size, 0);
}
lab1_1::system::~system()
{
    delete this->sys;
    delete this->ext;
}
lab1_1::LU* lab1_1::system::getLU()
{
    LU* res = new LU;
    res->L = new std::vector<std::vector<double> >(this->size, std::vector<double>(this->size, 0));
    res->U = new std::vector<std::vector<double> >((*(this->sys)));
    res->p = new std::vector<std::pair<int, int> > ;
    for (int i = 0; i < this->sys->size(); ++i)
    {
        (*(res->L))[i][i] = 1;
    }

   // return res;

    for (int j = 0; j < this->sys->size() - 1; ++j)
    {
        double max = (*(res->U))[j][j];
        int maxColum = j;
        for (int i = j + 1; i < this->sys->size(); ++i)
        {
            if (max < (*(res->U))[i][j])
            {
                max = (*(res->U))[i][j];
                maxColum = i;
            }
            //std::cout « maxColum « " !!! "«i «" " « max «"\n";
        }
        if (maxColum != j)
        {
            //ïåðåñòàíîâêà!
            swapline(res->U, maxColum, j);
            swapline(res->L, maxColum, j);
            swapcolum(res->L, maxColum, j);

            double tmp = (*(this->ext))[maxColum];
            (*(this->ext))[maxColum] = (*(this->ext))[j];
            (*(this->ext))[j] = tmp;

            res->p->push_back(std::make_pair(maxColum, j));
        }
        for (int i = j + 1; i < this->sys->size(); ++i)
        {
            double tmp = (-1) * (*(res->U))[i][j] / (*(res->U))[j][j];
            (*(res->L))[i][j] = -tmp;// this->l->set(i, j, -tmp);
            for (int z = 0; z < this->size; ++z)
                (*(res->U))[i][z] += (*(res->U))[j][z] * tmp;//this->u->add(j, i, tmp);
            //(*(this->ext))[j] += tmp;//this->ext->add(j,i, tmp);
        }
    }

    return res;
}

void lab1_1::system::swapline(std::vector<std::vector<double> > *arg, int i, int j)
{
    if ((i < 0 || j < 0) || ((unsigned int)i >= arg->size() || (unsigned int)j >= arg->size()))
        return;
    for (unsigned int z = 0; z < arg->size(); ++z)
    {
        double tmp = (*(arg))[i][z];
        (*(arg))[i][z] = (*(arg))[j][z];
        (*(arg))[j][z] = tmp;
    }
}

void lab1_1::system::swapcolum(std::vector<std::vector<double> > *arg, int i, int j)
{
    if ((i < 0 || j < 0) || ((unsigned int)i >= arg->size() || (unsigned int)j >= arg->size()))
        return;
    for (unsigned int z = 0; z < arg->size(); ++z)
    {
        double tmp = (*(arg))[z][i];
        (*(arg))[z][i] = (*(arg))[z][j];
        (*(arg))[z][j] = tmp;
    }
}

void lab1_1::setVar1(system *arg)
{

    (*(arg->sys))[0][0] = 1;
    (*(arg->sys))[0][1] = 2;
    (*(arg->sys))[0][2] = -2;
    (*(arg->sys))[0][3] = 6;
    (*(arg->sys))[1][0] = -3;
    (*(arg->sys))[1][1] = -5;
    (*(arg->sys))[1][2] = 14;
    (*(arg->sys))[1][3] = 13;
    (*(arg->sys))[2][0] = 1;
    (*(arg->sys))[2][1] = 2;
    (*(arg->sys))[2][2] = -2;
    (*(arg->sys))[2][3] = -2;
    (*(arg->sys))[3][0] = -2;
    (*(arg->sys))[3][1] = -4;
    (*(arg->sys))[3][2] = 5;
    (*(arg->sys))[3][3] = 10;

    (*(arg->ext))[0] = 24;
    (*(arg->ext))[1] = 41;
    (*(arg->ext))[2] = 0;
    (*(arg->ext))[3] = 20;
}

void lab1_1::print(system *arg)
{
    for (int i = 0; i < arg->size; ++i)
    {
        for (int j = 0; j < arg->size; ++j)
        {
            std::cout << (*(arg->sys))[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    for (int i = 0; i < arg->size; ++i)
    {
        std::cout << (*(arg->ext))[i] << "\n";
    }
    std::cout << "\n";
}

std::vector<double>* lab1_1::system::getResult(lab1_1::LU* lu)
{
    std::vector<double> *res = new std::vector<double>(this->size, 0);

    std::vector<double>tmp(this->size, 0);
    tmp[0] = (*(this->ext))[0];
    for (int i = 1; i < this->sys->size(); ++i)
    {
        double undo = 0;
        for (int j = 0; j <= i - 1; ++j)
        {
            undo += (*(lu->L))[i][j] * tmp[j];
        }
        //std::cout « "!!!!! " « this->ext->get(i,0) « " " « undo « "\n";
        tmp[i] = (*(this->ext))[i] - undo;
    }

    (*(res))[this->size - 1] = tmp[this->size - 1] / (*(lu->U))[this->size - 1][this->size - 1];
    for (int i = this->size - 2; i >= 0; --i)
    {
        double undo = 0;
        for (int j = i + 1; j < this->size; ++j)
        {
            undo += (*(lu->U))[i][j] * (*(res))[j];
        }
        //std::cout « "!!!!! " « this->u->get(i,i) « " " « undo « "\n";
        (*(res))[i] = (1 / (*(lu->U))[i][i]) * (tmp[i] - undo);
    }
    return res;
}

void lab1_1::setVar12(system *arg)
{

    (*(arg->sys))[0][0] = -1;
    (*(arg->sys))[0][1] = -8;
    (*(arg->sys))[0][2] = 0;
    (*(arg->sys))[0][3] = 5;
    (*(arg->sys))[1][0] = 6;
    (*(arg->sys))[1][1] = -6;
    (*(arg->sys))[1][2] = 2;
    (*(arg->sys))[1][3] = 4;
    (*(arg->sys))[2][0] = 9;
    (*(arg->sys))[2][1] = -5;
    (*(arg->sys))[2][2] = -6;
    (*(arg->sys))[2][3] = 4;
    (*(arg->sys))[3][0] = -5;
    (*(arg->sys))[3][1] = 0;
    (*(arg->sys))[3][2] = -9;
    (*(arg->sys))[3][3] = 1;

    (*(arg->ext))[0] = -60;
    (*(arg->ext))[1] = -10;
    (*(arg->ext))[2] = 65;
    (*(arg->ext))[3] = 18;
}

double lab1_1::system::det(lab1_1::LU* lu)
{
    double tmp = 1;
    for (int i = 0; i < lu->L->size(); ++i)
    {
        tmp *= (*(lu->U))[i][i];
    }
    return pow(-1, lu->p->size()) * tmp;
}

std::vector<std::vector<double> >* lab1_1::system::getRevers()
{
    std::vector<std::vector<double> >* res = new std::vector<std::vector<double> >(this->size, std::vector<double>(this->size));

    system tmp(this->size);
    (*(tmp.sys)) = (*(this->sys));
    (*(tmp.ext)) = (*(this->ext));

    LU* lu = this->getLU();

    for (int i = 0; i < this->size; ++i)
    {
        for (int j = 0; j < this->size; ++j)
        {
            if (i == j)
                (*(tmp.ext))[j] = 1;
            else
                (*(tmp.ext))[j] = 0;
        }
        std::vector<double>* tmpRes = tmp.getResult(lu);
        for (int j = 0; j < this->size; ++j)
        {
            (*(res))[j][i] = (*(tmpRes))[j];
        }
        delete tmpRes;
    }

   /* for (int i = 0; i < lu->p->size(); ++i)
    {
       // swapline(res, (*(lu->p))[i].first, (*(lu->p))[i].second);
        swapcolum(res, (*(lu->p))[i].first, (*(lu->p))[i].second);

    }*/

    delete lu;

    return res;
}