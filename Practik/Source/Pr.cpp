#include<iostream>
#include<Pr.h>
#include<utility>
#include<cmath>
#include<LU.h>

practik::polinom::polinom()
{
    this->data = new std::vector < std::pair<double, double> >;
}

practik::polinom::~polinom()
{
    delete this->data;
    this->data = nullptr;
}

void practik::polinom::initTable0()
{
    if (this->data)
    {
        delete this->data;
        this->data = new std::vector < std::pair<double, double> > ;
    }
    this->data->push_back(std::make_pair(100, 23.703));
    this->data->push_back(std::make_pair(200, 22.734));
    this->data->push_back(std::make_pair(298.15, 21.911));
    this->data->push_back(std::make_pair(300, 21.901));
    this->data->push_back(std::make_pair(400, 21.482));
    this->data->push_back(std::make_pair(500, 21.257));
    this->data->push_back(std::make_pair(600, 21.124));
    this->data->push_back(std::make_pair(700, 21.040));
    this->data->push_back(std::make_pair(800, 20.984));
    this->data->push_back(std::make_pair(900, 20.944));
    this->data->push_back(std::make_pair(1000, 20.915));
    this->data->push_back(std::make_pair(1100, 20.893));
    this->data->push_back(std::make_pair(1200, 20.877));
    this->data->push_back(std::make_pair(1300, 20.864));
    this->data->push_back(std::make_pair(1400, 20.853));
    this->data->push_back(std::make_pair(1500, 20.845));
    this->data->push_back(std::make_pair(1600, 20.838));
    this->data->push_back(std::make_pair(1700, 20.833));
    this->data->push_back(std::make_pair(1800, 20.830));
    this->data->push_back(std::make_pair(1900, 20.827));
    this->data->push_back(std::make_pair(2000, 20.826));
    this->data->push_back(std::make_pair(2100, 20.827));
    this->data->push_back(std::make_pair(2200, 20.830));
    this->data->push_back(std::make_pair(2300, 20.835));
    this->data->push_back(std::make_pair(2400, 20.841));
    this->data->push_back(std::make_pair(2500, 20.851));
    this->data->push_back(std::make_pair(2600, 20.862));
    this->data->push_back(std::make_pair(2700, 20.877));
    this->data->push_back(std::make_pair(2800, 20.894));
    this->data->push_back(std::make_pair(2900, 20.914));
    this->data->push_back(std::make_pair(3000, 20.937));
    this->data->push_back(std::make_pair(3100, 20.963));
    this->data->push_back(std::make_pair(3200, 20.991));
    this->data->push_back(std::make_pair(3300, 21.022));
    this->data->push_back(std::make_pair(3400, 21.056));
    this->data->push_back(std::make_pair(3500, 21.092));
    this->data->push_back(std::make_pair(3600, 21.130));
    this->data->push_back(std::make_pair(3700, 21.170));
    this->data->push_back(std::make_pair(3800, 21.213));
    this->data->push_back(std::make_pair(3900, 21.257));
    this->data->push_back(std::make_pair(4000, 21.302));
    this->data->push_back(std::make_pair(4100, 21.349));
    this->data->push_back(std::make_pair(4200, 21.397));
    this->data->push_back(std::make_pair(4300, 21.445));
    this->data->push_back(std::make_pair(4400, 21.495));
    this->data->push_back(std::make_pair(4500, 21.545));
    this->data->push_back(std::make_pair(4600, 21.596));
    this->data->push_back(std::make_pair(4700, 21.647));
    this->data->push_back(std::make_pair(4800, 21.697));
    this->data->push_back(std::make_pair(4900, 21.748));
    this->data->push_back(std::make_pair(5000, 21.799));
    this->data->push_back(std::make_pair(5100, 21.849));
    this->data->push_back(std::make_pair(5200, 21.899));
    this->data->push_back(std::make_pair(5300, 21.949));
    this->data->push_back(std::make_pair(5400, 21.997));
    this->data->push_back(std::make_pair(5500, 22.045));
    this->data->push_back(std::make_pair(5600, 22.093));
    this->data->push_back(std::make_pair(5700, 22.139));
    this->data->push_back(std::make_pair(5800, 22.184));
    this->data->push_back(std::make_pair(5900, 22.229));
    this->data->push_back(std::make_pair(6000, 22.273));
}

void practik::polinom::initTable0two()
{
    if (this->data)
    {
        delete this->data;
        this->data = new std::vector < std::pair<double, double> >;
    }
    this->data->push_back(std::make_pair(100, 23.703));
    //this->data->push_back(std::make_pair(200, 22.734));
    //this->data->push_back(std::make_pair(298.15, 21.911));
    //this->data->push_back(std::make_pair(300, 21.901));
    this->data->push_back(std::make_pair(400, 21.482));
    //this->data->push_back(std::make_pair(500, 21.257));
    //this->data->push_back(std::make_pair(600, 21.124));
    //this->data->push_back(std::make_pair(700, 21.040));
    this->data->push_back(std::make_pair(800, 20.984));
    //this->data->push_back(std::make_pair(900, 20.944));
    //this->data->push_back(std::make_pair(1000, 20.915));
    //this->data->push_back(std::make_pair(1100, 20.893));
    this->data->push_back(std::make_pair(1200, 20.877));
    //this->data->push_back(std::make_pair(1300, 20.864));
    //this->data->push_back(std::make_pair(1400, 20.853));
    //this->data->push_back(std::make_pair(1500, 20.845));
    this->data->push_back(std::make_pair(1600, 20.838));
    //this->data->push_back(std::make_pair(1700, 20.833));
    //this->data->push_back(std::make_pair(1800, 20.830));
    //this->data->push_back(std::make_pair(1900, 20.827));
    this->data->push_back(std::make_pair(2000, 20.826));
    //this->data->push_back(std::make_pair(2100, 20.827));
    //this->data->push_back(std::make_pair(2200, 20.830));
    this->data->push_back(std::make_pair(2300, 20.835));
    //this->data->push_back(std::make_pair(2400, 20.841));
    //this->data->push_back(std::make_pair(2500, 20.851));
    //this->data->push_back(std::make_pair(2600, 20.862));
    this->data->push_back(std::make_pair(2700, 20.877));
    //this->data->push_back(std::make_pair(2800, 20.894));
    //this->data->push_back(std::make_pair(2900, 20.914));
    //this->data->push_back(std::make_pair(3000, 20.937));
    this->data->push_back(std::make_pair(3100, 20.963));
    //this->data->push_back(std::make_pair(3200, 20.991));
    //this->data->push_back(std::make_pair(3300, 21.022));
    //this->data->push_back(std::make_pair(3400, 21.056));
    this->data->push_back(std::make_pair(3500, 21.092));
    //this->data->push_back(std::make_pair(3600, 21.130));
    //this->data->push_back(std::make_pair(3700, 21.170));
    //this->data->push_back(std::make_pair(3800, 21.213));
    this->data->push_back(std::make_pair(3900, 21.257));
    //this->data->push_back(std::make_pair(4000, 21.302));
    //this->data->push_back(std::make_pair(4100, 21.349));
    //this->data->push_back(std::make_pair(4200, 21.397));
    this->data->push_back(std::make_pair(4300, 21.445));
    //this->data->push_back(std::make_pair(4400, 21.495));
    //this->data->push_back(std::make_pair(4500, 21.545));
    //this->data->push_back(std::make_pair(4600, 21.596));
    this->data->push_back(std::make_pair(4700, 21.647));
    //this->data->push_back(std::make_pair(4800, 21.697));
    //this->data->push_back(std::make_pair(4900, 21.748));
    //this->data->push_back(std::make_pair(5000, 21.799));
    this->data->push_back(std::make_pair(5100, 21.849));
    //this->data->push_back(std::make_pair(5200, 21.899));
    //this->data->push_back(std::make_pair(5300, 21.949));
    //this->data->push_back(std::make_pair(5400, 21.997));
    this->data->push_back(std::make_pair(5500, 22.045));
    //this->data->push_back(std::make_pair(5600, 22.093));
    //this->data->push_back(std::make_pair(5700, 22.139));
    //this->data->push_back(std::make_pair(5800, 22.184));
    this->data->push_back(std::make_pair(5900, 22.229));
    //this->data->push_back(std::make_pair(6000, 22.273));
}

void practik::polinom::mainFunc(int n)
{
    /*this->initTable0();
    this->printGraficValue(n);*/
    this->initTable0two();
    this->printGraficValuetwo(n);
    //int n = 3;
    //int start = 40;
    //this->printData();
}

void practik::polinom::mainFunc()
{
    /*this->initTable0();
    this->printGraficValue();*/
    this->initTable0two();
    this->printGraficValuetwo();
    //int n = 3;
    //int start = 40;
    //this->printData();
}

double practik::polinom::getValuePolinom(std::vector<double>* arr, double arg)
{
    double res = 0;
    for (int i = 0; i < arr->size(); ++i)
    {
        res += (*(arr))[i] * pow(arg, i);
    }
    return res;
}

std::vector<double>* practik::polinom::getPolinom(std::vector<std::pair<double, double> > *data)
{
    lab1_1::system sys(data->size());
    for (int i = 0; i < data->size(); ++i)
    {
        for (int j = 0; j < data->size(); ++j)
        {
            sys.setSys(i, j, pow((*(data))[i].first, j));
        }
        sys.setExt(i, (*(data))[i].second);
    }
    //sys.print();
    lab1_1::LU* lu = sys.getLU();
    std::vector<double>* res = sys.getResult(lu);
    delete lu;
    return res;
}

void practik::polinom::printGraficValue(int n)
{
    for (int st = 0; st < 60; st += (n - 1))
    {
        std::vector<std::pair<double, double> > data;
        for (int i = 0; i < n; ++i)
        {
            data.push_back((*(this->data))[st + i]);
        }
        std::vector<double>* res = this->getPolinom(&data);
        /*for (int i = 0; i < res->size(); ++i)
        {
        std::cout << (*(res))[i] << "\n";
        }*/
        for (double arg = (*(this->data))[st].first; arg <= (*(this->data))[st + n - 1].first; arg += .1)
        {
            std::cout << arg << "\t" << this->getValuePolinom(res, arg) << "\n";
        }
        delete res;
    }
}

void practik::polinom::printGraficValuetwo(int n)
{
    for (int st = 0; st < 60 / 4 ; st += (n - 1))
    {
        std::vector<std::pair<double, double> > data;
        for (int i = 0; i < n; ++i)
        {
            data.push_back((*(this->data))[st + i]);
        }
        std::vector<double>* res = this->getPolinom(&data);
        /*for (int i = 0; i < res->size(); ++i)
        {
        std::cout << (*(res))[i] << "\n";
        }*/
        for (double arg = (*(this->data))[st].first; arg <= (*(this->data))[st + n - 1].first; arg += .1)
        {
            std::cout << arg << "\t" << this->getValuePolinom(res, arg) << "\n";
        }
        delete res;
    }
}

void practik::polinom::printData()
{
    for (int i = 0; i < this->data->size(); ++i)
    {
        std::cout << (*(this->data))[i].first << "\t" << (*(this->data))[i].second << "\n";
    }
}

double practik::polinom::getValuePolinomTwo(std::vector<double>* arr, double arg)
{
    double res = 1 * (*(arr))[0] + log(arg) * (*(arr))[1] + pow(arg, -1) * (*(arr))[2]
        + pow(arg, -2) * (*(arr))[3] + arg * (*(arr))[4] + pow(arg, 2) * (*(arr))[5] + pow(arg, 3) * (*(arr))[6];
    return res;
}

double getValue(double arg, int i)
{
    switch (i)
    {
    case 0:
        return 1;
    case 1:
        return log(arg);
    case 2:
        return pow(arg, -1);
    case 3:
        return pow(arg, -2);
    case 4:
        return arg;
    case 5:
        return pow(arg, 2);
    case 6:
        return pow(arg, 3);
    default:
        break;
    }
}

std::vector<double>* practik::polinom::getPolinomTwo(std::vector<std::pair<double, double> > *data)
{
    int n = data->size();

    lab1_1::system sys(data->size());
    for (int i = 0; i < data->size(); ++i)
    {
        for (int j = 0; j < data->size(); ++j)
        {
            sys.setSys(i, j, getValue((*(data))[i].first, j));
        }
        sys.setExt(i, (*(data))[i].second);
    }
    //sys.print();

    lab1_1::LU* lu = sys.getLU();
    std::vector<double>* res = sys.getResult(lu);
    delete lu;
    return res;
}

void practik::polinom::printGraficValue()
{
    int n = 7;
    for (int st = 0; st < 60; st += (n - 1))
    {
        std::vector<std::pair<double, double> > data;
        for (int i = 0; i < n; ++i)
        {
            data.push_back((*(this->data))[st + i]);
        }
        std::vector<double>* res = this->getPolinomTwo(&data);
        /*for (int i = 0; i < res->size(); ++i)
        {
        std::cout << (*(res))[i] << "\n";
        }*/

        for (double arg = (*(this->data))[st].first; arg <= (*(this->data))[st + n - 1].first; arg += .1)
        {
            std::cout << arg << "\t" << this->getValuePolinomTwo(res, arg) << "\n";
        }
        delete res;
    }
}

void practik::polinom::printGraficValuetwo()
{
    int n = 7;
    for (int st = 0; st < 12; st += (n - 1))
    {
        std::vector<std::pair<double, double> > data;
        for (int i = 0; i < n; ++i)
        {
            data.push_back((*(this->data))[st + i]);
        }
        std::vector<double>* res = this->getPolinomTwo(&data);
        /*for (int i = 0; i < res->size(); ++i)
        {
        std::cout << (*(res))[i] << "\n";
        }*/
        for (double arg = (*(this->data))[st].first; arg <= (*(this->data))[st + n - 1].first; arg += .1)
        {
            std::cout << arg << "\t" << this->getValuePolinomTwo(res, arg) << "\n";
        }
        delete res;
    }
}