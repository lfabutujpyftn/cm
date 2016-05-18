#include<iostream>
#include<DU2.h>
#include<utility>
#include<cmath>
#include<Prog.h>

lab4_2::func::func()
{
    h = 0.1;
    a = 0;
    b = 3.14 / 6;
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
    //std::cout << "resr " << 2.5 - 0.5 * log(3) << "\n";
    while (fabs(r2 - 2.5 + 0.5 * log(3)) > 0.01 && i++ < 10)
    {
     //   std::cout << "fabs " << fabs(r2 - 2.5 + 0.5 * log(3)) << "\n";
        double n3 = n2 - (n2 - n1) * (r2 - 2.5 + 0.5 * log(3)) / (r2 - r1);
        double r3 = du.getValue(n3, 0);
       // std::cout << "n1 " << n1 << " r1 " << r1 << " n2 " << n2 << " r2 " << r2 << " n3 " << n3 << " r3 " << r3 << "\n";
        n1 = n2;
        n2 = n3;
        r1 = r2;
        r2 = r3;
    }
   // std::cout << "n2 " << n2 << "\n";
    du.getValue(n2, 0);
    h /= 2;

    n1 = 2.0;
    n2 = 2.1;
    r1 = du.getValue(n1, 1);
    r2 = du.getValue(n2, 1);
    i = 0;
    //std::cout << "resr " << 2.5 - 0.5 * log(3) << "\n";
    while (fabs(r2 - 2.5 + 0.5 * log(3)) > 0.01 && i++ < 10)
    {
        //   std::cout << "fabs " << fabs(r2 - 2.5 + 0.5 * log(3)) << "\n";
        double n3 = n2 - (n2 - n1) * (r2 - 2.5 + 0.5 * log(3)) / (r2 - r1);
        double r3 = du.getValue(n3, 1);
        // std::cout << "n1 " << n1 << " r1 " << r1 << " n2 " << n2 << " r2 " << r2 << " n3 " << n3 << " r3 " << r3 << "\n";
        n1 = n2;
        n2 = n3;
        r1 = r2;
        r2 = r3;
    }
    // std::cout << "n2 " << n2 << "\n";
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
            if (x != this->arg->a)
            {
                double z1 = 0;
                double z2 = 0;
                //std::cout << "x: " << x << " y: " << yi << "\n";
                {
                    double k1 = 0;
                    if (x == this->arg->a)
                        k1 = this->arg->h * fi;
                    else
                        k1 = this->arg->h * this->arg->f(x, yi, zi);
                    double k2 = this->arg->h * this->arg->f(x + 1.0 / 3 * this->arg->h, yi + 1.0 / 3 * k1, zi);
                    double k3 = this->arg->h * this->arg->f(x + 2.0 / 3 * this->arg->h, yi + 2.0 / 3 * k2, zi);
                    double dz = 1.0 / 4 * (k1 + 3 * k3);
                    /*std::cout << "k1: " << k1 << "\n";
                    std::cout << "k2: " << k2 << "\n";
                    std::cout << "k3: " << k3 << "\n";
                    std::cout << "dy: " << dy << "\n";*/
                    zi = zi + dz;
                    k1 = this->arg->h * this->arg->f(x + 1.0 / 3 * this->arg->h, yi + 1.0 / 3 * zi, zi);
                    k2 = this->arg->h * this->arg->f(x + 2.0 / 3 * this->arg->h, yi + 1.0 / 3 * k1 + 1.0 / 3 * zi, zi);
                    k3 = this->arg->h * this->arg->f(x + 3.0 / 3 * this->arg->h, yi + 2.0 / 3 * k2 + 1.0 / 3 * zi, zi);
                    dz = 1.0 / 4 * (k1 + 3 * k3);
                    z1 = zi + dz;
                    k1 = this->arg->h * this->arg->f(x + 2.0 / 3 * this->arg->h, yi + 2.0 / 3 * z1, zi);
                    k2 = this->arg->h * this->arg->f(x + 3.0 / 3 * this->arg->h, yi + 1.0 / 3 * k1 + 2.0 / 3 * z1, zi);
                    k3 = this->arg->h * this->arg->f(x + 4.0 / 3 * this->arg->h, yi + 2.0 / 3 * k2 + 2.0 / 3 * z1, zi);
                    dz = 1.0 / 4 * (k1 + 3 * k3);
                    z2 = zi + dz;
                }
        {
            double k1 = 0;
            if (x == this->arg->a)
                k1 = this->arg->h * zi;
            else
                k1 = this->arg->h * zi;
            double k2 = this->arg->h * z1;
            double k3 = this->arg->h * z2;
            double dy = 1.0 / 4 * (k1 + 3 * k3);
            /*std::cout << "k1: " << k1 << "\n";
            std::cout << "k2: " << k2 << "\n";
            std::cout << "k3: " << k3 << "\n";
            std::cout << "*/
            yi = yi + dy;
        }
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
        for (double x = this->arg->a; x <= this->arg->b + this->arg->h / 3; x += this->arg->h)
        {
            if (x != this->arg->a)
            {
                double z1 = 0;
                double z2 = 0;
                //std::cout << "x: " << x << " y: " << yi << "\n";
                {
                    double k1 = 0;
                    if (x == this->arg->a)
                        k1 = this->arg->h * fi;
                    else
                        k1 = this->arg->h * this->arg->f(x, yi, zi);
                    double k2 = this->arg->h * this->arg->f(x + 1.0 / 3 * this->arg->h, yi + 1.0 / 3 * k1, zi);
                    double k3 = this->arg->h * this->arg->f(x + 2.0 / 3 * this->arg->h, yi + 2.0 / 3 * k2, zi);
                    double dz = 1.0 / 4 * (k1 + 3 * k3);
                    /*std::cout << "k1: " << k1 << "\n";
                    std::cout << "k2: " << k2 << "\n";
                    std::cout << "k3: " << k3 << "\n";
                    std::cout << "dy: " << dy << "\n";*/
                    zi = zi + dz;
                    k1 = this->arg->h * this->arg->f(x + 1.0 / 3 * this->arg->h, yi + 1.0 / 3 * zi, zi);
                    k2 = this->arg->h * this->arg->f(x + 2.0 / 3 * this->arg->h, yi + 1.0 / 3 * k1 + 1.0 / 3 * zi, zi);
                    k3 = this->arg->h * this->arg->f(x + 3.0 / 3 * this->arg->h, yi + 2.0 / 3 * k2 + 1.0 / 3 * zi, zi);
                    dz = 1.0 / 4 * (k1 + 3 * k3);
                    z1 = zi + dz;
                    k1 = this->arg->h * this->arg->f(x + 2.0 / 3 * this->arg->h, yi + 2.0 / 3 * z1, zi);
                    k2 = this->arg->h * this->arg->f(x + 3.0 / 3 * this->arg->h, yi + 1.0 / 3 * k1 + 2.0 / 3 * z1, zi);
                    k3 = this->arg->h * this->arg->f(x + 4.0 / 3 * this->arg->h, yi + 2.0 / 3 * k2 + 2.0 / 3 * z1, zi);
                    dz = 1.0 / 4 * (k1 + 3 * k3);
                    z2 = zi + dz;
                }
        {
            double k1 = 0;
            if (x == this->arg->a)
                k1 = this->arg->h * zi;
            else
                k1 = this->arg->h * zi;
            double k2 = this->arg->h * z1;
            double k3 = this->arg->h * z2;
            double dy = 1.0 / 4 * (k1 + 3 * k3);
            /*std::cout << "k1: " << k1 << "\n";
            std::cout << "k2: " << k2 << "\n";
            std::cout << "k3: " << k3 << "\n";
            std::cout << "*/
            yi = yi + dy;
        }
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
    //double h = this->h * 10;
    int n = (this->b - this->a) / h + 1;
    std::cout << "n " << n << "\n";
    lab1_2::system sys(n);
    sys.seta(0, 0);
    sys.setb(0, -2 + h * h * 2);
    sys.setc(0, 1 + -tan(this->a) * h / 2);
    sys.setext(0, -2 * (1 + tan(this->a) * h / 2));
    for (int i = 1; i < n - 1; ++i)
    {
        //std::cout << " k1 " << 1 + tan(this->a + i * h) * h / 2 << "\n";
        sys.seta(i, (1 + tan(this->a + i * h) * h / 2));

        //std::cout << " k2 " << -2 + h * h * 22 << "\n";
        sys.setb(i, -2 + h * h * 2);

        //std::cout << " k3 " << 1 - tan(this->a + i * h) * h / 2 << "\n";
        sys.setc(i, (1 - tan(this->a + i * h) * h / 2));
        sys.setext(i, 0);
    }
    sys.seta(n - 1, (1 + tan(this->b - h) * h / 2));
    sys.setb(n - 1, -2 + h * h * 2);
    sys.setc(n - 1, 0);
    sys.setext(n - 1, -(2.5 - 0.5 * log(3)) * (1 - tan(this->b - h) * h / 2));
    this->sth = sys.getResult();
    /*if (res == nullptr)
        std::cout << "error\n";*/
    //std::cout << (*(res))[0] << "\n";
    /*for (int i = 0; i < n; ++i)
    {
        std::cout << "x " << this->a + i*h << " y: " << (*(res))[i] << "\n";
    }*/

    h /= 2;
    n = (this->b - this->a) / h + 1;
    std::cout << "n " << n << "\n";
    lab1_2::system sys2(n);
    sys2.seta(0, 0);
    sys2.setb(0, -2 + h * h * 2);
    sys2.setc(0, 1 + -tan(this->a) * h / 2);
    sys2.setext(0, -2 * (1 + tan(this->a) * h / 2));
    for (int i = 1; i < n - 1; ++i)
    {
        //std::cout << " k1 " << 1 + tan(this->a + i * h) * h / 2 << "\n";
        sys2.seta(i, (1 + tan(this->a + i * h) * h / 2));

        //std::cout << " k2 " << -2 + h * h * 22 << "\n";
        sys2.setb(i, -2 + h * h * 2);

        //std::cout << " k3 " << 1 - tan(this->a + i * h) * h / 2 << "\n";
        sys2.setc(i, (1 - tan(this->a + i * h) * h / 2));
        sys2.setext(i, 0);
    }
    sys2.seta(n - 1, (1 + tan(this->b - h) * h / 2));
    sys2.setb(n - 1, -2 + h * h * 2);
    sys2.setc(n - 1, 0);
    sys2.setext(n - 1, -(2.5 - 0.5 * log(3)) * (1 - tan(this->b - h) * h / 2));
    this->st2h = sys2.getResult();
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