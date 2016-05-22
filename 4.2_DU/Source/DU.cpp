#include<iostream>
#include<DU2.h>
#include<utility>
#include<cmath>
#include<Prog.h>
#include<LU.h>

lab4_2::func::func()
{
    h = 0.1;
    a = 0;
    b = 0.5;// 3.14 / 6;
    this->sth = new std::vector < double >;
    this->st2h = new std::vector < double >;
}

lab4_2::func::~func()
{
    delete this->st2h;
    delete this->sth;
}

double lab4_2::func::f(double x)
{
    return sin(x) + 2 - sin(x) * log((1 + sin(x)) / (1 - sin(x)));
}

void lab4_2::func::getTable()
{
    std::cout << "x\ty\n";
    for (double x = a; x <= b + h / 3; x += h)
    {
        std::cout  << x << "  " << this->f(x) << "\n";
    }
}

void lab4_2::func::getRes1()
{
    DU du(this);
    double n1 = 2.0;
    double n2 = 2.1;
    double r1 = du.getValue(n1, 0);
    double r2 = du.getValue(n2, 0);
    int i = 0;
    while (fabs(r2 - this->f(0.5)) > 0.001 && i++ < 10)
    {
        double n3 = n2 - (n2 - n1) * (r2 - this->f(0.5)) / (r2 - r1);
        double r3 = du.getValue(n3, 0);
        n1 = n2;
        n2 = n3;
        r1 = r2;
        r2 = r3;
    }
    du.getValue(n2, 0);
    h /= 2;

    n1 = 2.0;
    n2 = 2.1;
    r1 = du.getValue(n1, 1);
    r2 = du.getValue(n2, 1);
    i = 0;
    while (fabs(r2 - this->f(0.5)) > 0.01 && i++ < 10)
    {
        double n3 = n2 - (n2 - n1) * (r2 - this->f(0.5)) / (r2 - r1);
        double r3 = du.getValue(n3, 1);
        n1 = n2;
        n2 = n3;
        r1 = r2;
        r2 = r3;
    }
    du.getValue(n2, 1);
    h *= 2;
}

double lab4_2::func::f(double x, double y)
{
    return tan(x * x) - 2 * y;
}

lab4_2::DU::DU(func *arg)
{
    this->arg = arg;
}

lab4_2::DU::~DU()
{

}

double lab4_2::DU::getValue(double nu, bool p)
{
    if (this->arg->sth && p == false)
    {
        delete this->arg->sth;
        this->arg->sth = new std::vector < double >;
    }
    if (this->arg->st2h && p == true)
    {
        delete this->arg->st2h;
        this->arg->st2h = new std::vector < double >;
    }
    if (p == false)
    {
        double yi = 2;
        double fi = nu;
        double zi = fi;
        for (double x = this->arg->a; x <= this->arg->b + this->arg->h / 3; x += this->arg->h)
        {
            if (x == this->arg->a)
            {
            }
            else
            {
                zi = zi + this->arg->h * this->arg->f(x, yi, zi);
                yi = yi + this->arg->h * zi;
            }
            this->arg->sth->push_back(yi);
        }
        return yi;
    }

    if (p == true)
    {
        double yi = 2;
        double fi = nu;
        double zi = fi;
        for (double x = this->arg->a; x <= this->arg->b + this->arg->h / 3.0 ; x += this->arg->h)
        {
            if (x == this->arg->a)
            {
            }
            else
            {
                zi = zi + this->arg->h * this->arg->f(x, yi, zi);
                yi = yi + this->arg->h * zi;
            }
            this->arg->st2h->push_back(yi);
        }
        return yi;
    }
}

void lab4_2::func::getRes2()
{
    if (this->sth)
    {
        delete this->sth;
        this->sth = new std::vector < double >;
    }
    if (this->st2h)
    {
        delete this->st2h;
        this->st2h = new std::vector < double >;
    }
    int n = (this->b - this->a) / h - 1;
    lab1_2::system sys(n);
    sys.seta(0, 0);
    sys.setb(0, -2 + h * h * 2.0);
    sys.setc(0, 1.0 + -1 * tan(this->a + h) * h / 2.0);
    sys.setext(0, -2 * (1.0 - -1 * tan(this->a + h) * h / 2.0));
    for (int i = 1; i < n - 1; ++i)
    {
        sys.seta(i, (1 - -1*tan(this->a + (i + 1) * h) * h / 2));
        sys.setb(i, -2 + h * h * 2);
        sys.setc(i, (1 + -1*tan(this->a + (i + 1) * h) * h / 2));
        sys.setext(i, 0);
    }
    sys.seta(n - 1, (1 - -1* tan(0.4) * h / 2));
    sys.setb(n - 1, -2 + h * h * 2);
    sys.setc(n - 1, 0);
    sys.setext(n - 1, -1* this->f(0.5) * (1 + -1* tan(0.4) * h / 2));
    this->sth->push_back(this->f(0));
    std::vector<double> *tmp = sys.getResult();
    tmp->push_back(this->f(0.5));
    for (int i = 0; i < tmp->size(); ++i)
    {
        this->sth->push_back((*(tmp))[i]);
    }
    h /= 2;
    n = (this->b - this->a) / h - 1;
    lab1_2::system sys2(n);
    sys2.seta(0, 0);
    sys2.setb(0, -2 + h * h * 2.0);
    sys2.setc(0, 1.0 + -1 * tan(this->a + h) * h / 2.0);
    sys2.setext(0, -2 * (1.0 - -1 * tan(this->a + h) * h / 2.0));
    for (int i = 1; i < n - 1; ++i)
    {
        sys2.seta(i, (1 - -1 * tan(this->a + (i + 1) * h) * h / 2));
        sys2.setb(i, -2 + h * h * 2);
        sys2.setc(i, (1 + -1 * tan(this->a + (i + 1) * h) * h / 2));
        sys2.setext(i, 0);
    }
    sys2.seta(n - 1, (1 - -1 * tan(0.4) * h / 2));
    sys2.setb(n - 1, -2 + h * h * 2);
    sys2.setc(n - 1, 0);
    sys2.setext(n - 1, -1 * this->f(0.5) * (1 + -1 * tan(0.4) * h / 2));
    this->st2h->push_back(this->f(0));
    std::vector<double> *tmp2 = sys2.getResult();
    tmp2->push_back(this->f(0.5));
    for (int i = 0; i < tmp2->size(); ++i)
    {
        this->st2h->push_back((*(tmp2))[i]);
    }
    h *= 2;
}

void lab4_2::func::printResult()
{
    std::cout << "h x\ty\n";
    for (int i = 0; i < this->sth->size(); ++i)
    {
        std::cout << a + i * h << " " << (*(this->sth))[i] << "\n";
    }
    std::cout << ".5h x\ty\n";
    for (int i = 0; i < this->st2h->size(); ++i)
    {
        std::cout << a + i * h / 2 << " " << (*(this->st2h))[i] << "\n";
    }
}

void lab4_2::func::getRumRob(int p)
{
    std::cout << "rr x\ty\n";
    for (int i = 0; i < this->sth->size(); ++i)
    {
        std::cout << a + i * h << " y: " << (*(this->sth))[i] + ((*(this->sth))[i] - (*(this->st2h))[2 * i]) / (pow(2, p) + 1) << "\n";
    }
}

double lab4_2::func::f(double x, double y, double z)
{
    return tan(x) * x - 2 * y;
}