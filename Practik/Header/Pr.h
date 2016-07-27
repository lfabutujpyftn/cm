#pragma once
#include<vector>
namespace practik
{
    class polinom
    {
    public:
        polinom();
        ~polinom();
        void mainFunc(int n);
        void mainFunc();
        std::vector<double>* getPolinom(std::vector<std::pair<double, double> > *data);
        std::vector<double>* getPolinomTwo(std::vector<std::pair<double, double> > *data);
        void printGraficValue(int n);
        void printGraficValuetwo(int n);
        void printGraficValue();
        void printGraficValuetwo();
        void mainFunc2();
        void printData();
        void printsprpol();
    private:
        std::vector<std::pair<double, double> > *data;

        void initTable0();
        void initTable0two();
        double getValuePolinom(std::vector<double>* arr, double arg);
        double getValuePolinomTwo(std::vector<double>* arr, double arg);
        double getsprpol(double arg);

    };
}