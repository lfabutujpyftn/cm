#include<iostream>
#include<Lagrange.h>
#include<utility>
#include<cmath>

lab3_1_lagr::polynom::polynom()
{
    this->t = nullptr;
    this->ti = nullptr;
    /*for (int i = 0; i < x.size(); ++i)
    {
        std::cout << (*(this->t))[i].first << " : " << (*(this->t))[i].second << "\n";
    }*/
}

lab3_1_lagr::polynom::~polynom()
{
    delete this->t;
}

void lab3_1_lagr::polynom::initInterpolation()
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

double lab3_1_lagr::polynom::getvalue(double arg)
{
    double fxi = 0;
    for (int i = 0; i < this->t->size(); ++i)
    {
        
        fxi += (*(this->t))[i].second * this->getlagr(i, arg);
        //std::cout << "xi " << (*(this->t))[i].first << " fxi " << fxi << "\n";
    }
    return fxi;
}

double lab3_1_lagr::polynom::getlagr(int i, double x)
{
    double tmp = 1;
    for (int j = 0; j < this->t->size(); ++j)
    {
        if (j == i)
            continue;
        tmp *= (x - (*(this->t))[j].first) / ((*(this->t))[i].first - (*(this->t))[j].first);
        
    }
    //std::cout << "lagr x: " << x << " tmp: " << tmp << "\n";
    return tmp;
}

void lab3_1_lagr::polynom::setA()
{
    if (this->t)
        delete this->t;
    if (this->t)
        delete this->ti;
    this->t = new std::vector < std::pair<double, double> > ;
    this->ti = new std::vector < std::pair<double, double> > ;
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

void lab3_1_lagr::polynom::setB()
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

void lab3_1_lagr::polynom::val()
{
    std::cout << "x:   y:\n";
    for (double x = 0.1; x < 1.3; x += 0.01)
    {
        std::cout << x << "    " << this->getvalue(x) << "\n";
    }
}