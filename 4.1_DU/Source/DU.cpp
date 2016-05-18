#include<iostream>
#include<DU.h>
#include<utility>
#include<cmath>

lab4_1::func::func()
{
    h = 0.1;
    a = 2;
    b = 3;
    this->sth = new std::vector < double > ;
    this->st2h = new std::vector < double >;
}

lab4_1::func::~func()
{
    delete this->st2h;
    delete this->sth;
}

double lab4_1::func::f(double x)
{
    return x*x + x + 1;
}

void lab4_1::func::getTable()
{
    if (this->sth)
    {
        delete this->sth;
        this->sth = new std::vector < double > ;
    }
    if (this->st2h)
    {
        delete this->st2h;
        this->st2h = new std::vector < double >;
    }
    for (double x = a; x <= b + h / 3; x += h)
    {
        //std::cout << "x: " << x << " y: " << this->f(x) << "\n";
        this->sth->push_back(this->f(x));
    }
    for (double x = a; x <= b + h / 2 / 3; x += h / 2)
    {
        //std::cout << "x: " << x << " y: " << this->f(x) << "\n";
        this->st2h->push_back(this->f(x));
    }
}

void lab4_1::func::getEuler()
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
    double zi = 5;
    double yi = 7;
    for (double x = a; x <= b + h / 3; x += h)
    {
        //std::cout << "x: " << x << " y: " << yi << "\n";
        if (x == a)
        {
         //   zi = fi;// +h * f(a, yi, fi);
           // yi = yi;// +h * zi;
        }
        else
        {
            zi = zi + h * f(x, yi, zi);
            yi = yi + h * zi;
        }
        this->sth->push_back(yi);
    }
    yi = 7;
    zi = 5;
    //zi = 0;
    for (double x = a; x <= b + h/2 / 3; x += h/2)
    {
        //std::cout << "x: " << x << " y: " << yi << "\n";
        if (x == a)
        {
         //   zi = fi;// +h * f(a, yi, fi);
           // yi = yi;// +h * zi;
        }
        else
        {
            zi = zi + h/2 * f(x, yi, zi);
            yi = yi + h/2 * zi;
        }
        this->st2h->push_back(yi);
    }
}

double lab4_1::func::f(double x, double y, double z)
{
    return (2 * x * z - 2 * y) / (x * x - 1);
}
double lab4_1::func::f(double x, double y)
{
    return 0;
}

void lab4_1::func::getRK()
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
    double yi = 7;
    double fi = 5;
    double zi = fi;
    for (double x = a; x <= b + h / 3; x += h)
    {
        if (x != a)
        {
            double z1 = 0;
            double z2 = 0;
            //std::cout << "x: " << x << " y: " << yi << "\n";
            {
                double k1 = 0;
                if (x == a)
                    k1 = h * fi;
                else
                    k1 = h * f(x, yi, zi);
                double k2 = h * f(x + 1.0 / 3 * h, yi + 1.0 / 3 * k1, zi);
                double k3 = h * f(x + 2.0 / 3 * h, yi + 2.0 / 3 * k2, zi);
                double dz = 1.0 / 4 * (k1 + 3 * k3);
                /*std::cout << "k1: " << k1 << "\n";
                std::cout << "k2: " << k2 << "\n";
                std::cout << "k3: " << k3 << "\n";
                std::cout << "dy: " << dy << "\n";*/
                zi = zi + dz;
                k1 = h * f(x + 1.0 / 3 * h, yi + 1.0 / 3 * zi, zi);
                k2 = h * f(x + 2.0 / 3 * h, yi + 1.0 / 3 * k1 + 1.0 / 3 * zi, zi);
                k3 = h * f(x + 3.0 / 3 * h, yi + 2.0 / 3 * k2 + 1.0 / 3 * zi, zi);
                dz = 1.0 / 4 * (k1 + 3 * k3);
                z1 = zi + dz;
                k1 = h * f(x + 2.0 / 3 * h, yi + 2.0 / 3 * z1, zi);
                k2 = h * f(x + 3.0 / 3 * h, yi + 1.0 / 3 * k1 + 2.0 / 3 * z1, zi);
                k3 = h * f(x + 4.0 / 3 * h, yi + 2.0 / 3 * k2 + 2.0 / 3 * z1, zi);
                dz = 1.0 / 4 * (k1 + 3 * k3);
                z2 = zi + dz;
            }
        {
            double k1 = 0;
            if (x == a)
                k1 = h * zi;
            else
                k1 = h * zi;
            double k2 = h * z1;
            double k3 = h * z2;
            double dy = 1.0 / 4 * (k1 + 3 * k3);
            /*std::cout << "k1: " << k1 << "\n";
            std::cout << "k2: " << k2 << "\n";
            std::cout << "k3: " << k3 << "\n";
            std::cout << "*/
            yi = yi + dy;
        }
        }
        this->sth->push_back(yi);
    }
    h /= 2;
    yi = 7;
    fi = 5;
    zi = fi;
    for (double x = a; x <= b + h / 3; x += h)
    {
        if (x != a)
        {
            double z1 = 0;
            double z2 = 0;
            //std::cout << "x: " << x << " y: " << yi << "\n";
            {
                double k1 = 0;
                if (x == a)
                    k1 = h * fi;
                else
                    k1 = h * f(x, yi, zi);
                double k2 = h * f(x + 1.0 / 3 * h, yi + 1.0 / 3 * k1, zi);
                double k3 = h * f(x + 2.0 / 3 * h, yi + 2.0 / 3 * k2, zi);
                double dz = 1.0 / 4 * (k1 + 3 * k3);
                /*std::cout << "k1: " << k1 << "\n";
                std::cout << "k2: " << k2 << "\n";
                std::cout << "k3: " << k3 << "\n";
                std::cout << "dy: " << dy << "\n";*/
                zi = zi + dz;
                k1 = h * f(x + 1.0 / 3 * h, yi + 1.0 / 3 * zi, zi);
                k2 = h * f(x + 2.0 / 3 * h, yi + 1.0 / 3 * k1 + 1.0 / 3 * zi, zi);
                k3 = h * f(x + 3.0 / 3 * h, yi + 2.0 / 3 * k2 + 1.0 / 3 * zi, zi);
                dz = 1.0 / 4 * (k1 + 3 * k3);
                z1 = zi + dz;
                k1 = h * f(x + 2.0 / 3 * h, yi + 2.0 / 3 * z1, zi);
                k2 = h * f(x + 3.0 / 3 * h, yi + 1.0 / 3 * k1 + 2.0 / 3 * z1, zi);
                k3 = h * f(x + 4.0 / 3 * h, yi + 2.0 / 3 * k2 + 2.0 / 3 * z1, zi);
                dz = 1.0 / 4 * (k1 + 3 * k3);
                z2 = zi + dz;
            }
        {
            double k1 = 0;
            if (x == a)
                k1 = h * zi;
            else
                k1 = h * zi;
            double k2 = h * z1;
            double k3 = h * z2;
            double dy = 1.0 / 4 * (k1 + 3 * k3);
            /*std::cout << "k1: " << k1 << "\n";
            std::cout << "k2: " << k2 << "\n";
            std::cout << "k3: " << k3 << "\n";
            std::cout << "*/
            yi = yi + dy;
        }
        }
        this->st2h->push_back(yi);
    }
    h *= 2;

}

void lab4_1::func::getAdams()
{
    double yi = 7;
    double fi = 5;
    int i = 1;
    std::vector<double> afi;
    afi.push_back(yi);
    for (double x = a; x <= b + h / 3 && i < 4; x += h, ++i)
    {
        //std::cout << "x: " << x << " y: " << yi << "\n";
        double k1 = 0;
        if (x == a)
            k1 = h * fi;
        else
            k1 = h * f(x, yi);
        double k2 = h * f(x + 1.0 / 3 * h, yi + 1.0 / 3 * k1);
        double k3 = h * f(x + 2.0 / 3 * h, yi + 2.0 / 3 * k2);;
        double dy = 1.0 / 4 * (k1 + 3 * k3);
        /*std::cout << "k1: " << k1 << "\n";
        std::cout << "k2: " << k2 << "\n";
        std::cout << "k3: " << k3 << "\n";
        std::cout << "dy: " << dy << "\n";*/
        yi = yi + dy;
        afi.push_back(yi);
    }
   // std::cout << "i: " << i << "\n";
    for (double x = a + 4 * h; x <= b + h / 3; x += h, ++i)
    {

        //std::cout << "i: " << i << "\n";
        yi = yi + h / 24 * (55 * f(x, afi[i - 1]) - 59 * f(x - 1 * h, afi[i - 2]) + 37 * f(x - 2*h, afi[i - 3])
            - 9 * f(x - 3*h, afi[i - 4]));
        afi.push_back(yi);
    }
    for (int i = 0; i < afi.size(); ++i)
    {
        std::cout << "x: " << a + i * h << " y: " <<  afi[i] << "\n";
    }
}

void lab4_1::func::getRumRob(int p)
{
    std::cout << "rr x\ty\n";
    for (int i = 0; i < this->sth->size(); ++i)
    {
        std::cout << a + i * h << " y: " << (*(this->sth))[i] + ((*(this->sth))[i] - (*(this->st2h))[2 * i]) / (pow(2, p) + 1) << "\n";
    }
}

void lab4_1::func::printResult()
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