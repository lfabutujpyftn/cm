#include<iostream>
#include<Newton.h>
#include<utility>
#include<cmath>

lab3_1_newt::polynom::polynom()
{
    this->t = nullptr;
    this->ti = nullptr;
    /*for (int i = 0; i < x.size(); ++i)
    {
    std::cout << (*(this->t))[i].first << " : " << (*(this->t))[i].second << "\n";
    }*/
}

lab3_1_newt::polynom::~polynom()
{
    if (this->t)
        delete this->t;
    if (this->t)
        delete this->ti;
}

void lab3_1_newt::polynom::initInterpolation()
{
    for (int i = 0; i < this->t->size(); ++i)
    {
        std::cout << "============\n";
        this->ti->push_back(std::make_pair((*(this->t))[i].first, this->getvalue((*(this->t))[i].first)));
        std::cout << "++++++++++++\n";
    }

    for (int i = 0; i < this->t->size(); ++i)
    {
        std::cout << (*(this->ti))[i].first << " : " << (*(this->ti))[i].second << "\n";
    }
}

double lab3_1_newt::polynom::getvalue(double arg)
{
    return (*(this->t))[0].second + (arg - (*(this->t))[0].first) * f2(0, 1) + 
        (arg - (*(this->t))[0].first) * (arg - (*(this->t))[1].first) * f3(0, 1, 2) +
        (arg - (*(this->t))[0].first) * (arg - (*(this->t))[1].first) * (arg - (*(this->t))[2].first) * 
        f4(0, 1, 2 , 3);
}


void lab3_1_newt::polynom::setA()
{
    if (this->t)
        delete this->t;
    if (this->t)
        delete this->ti;
    this->t = new std::vector < std::pair<double, double> >;
    this->ti = new std::vector < std::pair<double, double> >;
    this->xe = 0.8;
    std::vector<double> x;
    x.push_back(0.1);
    x.push_back(0.5);
    x.push_back(0.9);
    x.push_back(1.3);
    for (int i = 0; i < x.size(); ++i)
    {
        this->t->push_back(std::make_pair(x[i], log(x[i]) + x[i]));
    }
}

void lab3_1_newt::polynom::setB()
{
    if (this->t)
        delete this->t;
    if (this->t)
        delete this->ti;
    this->t = new std::vector < std::pair<double, double> >;
    this->ti = new std::vector < std::pair<double, double> >;
    this->xe = 0.8;
    std::vector<double> x;
    x.push_back(0.1);
    x.push_back(0.5);
    x.push_back(1.1);
    x.push_back(1.3);
    for (int i = 0; i < x.size(); ++i)
    {
        this->t->push_back(std::make_pair(x[i], log(x[i]) + x[i]));
    }
}

double lab3_1_newt::polynom::f2(int i, int j)
{
    return ((*(this->t))[i].second - (*(this->t))[j].second) / ((*(this->t))[i].first - (*(this->t))[j].first);
}

double lab3_1_newt::polynom::f3(int i, int j, int k)
{
    return (f2(i, j) - f2(j, k)) / ((*(this->t))[i].first - (*(this->t))[k].first);
}

double lab3_1_newt::polynom::f4(int i, int j, int k, int z)
{
    return (f3(i, j, k) - f3(j, k, z)) / ((*(this->t))[i].first - (*(this->t))[z].first);
}

void lab3_1_newt::polynom::val()
{
    std::cout << "x:   y:\n";
    for (double x = 0.1; x < 1.3; x += 0.05)
    {
        std::cout << x << "    " << this->getvalue(x) << "\n";
    }
}