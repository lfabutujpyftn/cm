#include<iostream>
#include<Spline.h>
#include<utility>
#include<cmath>
#include<Prog.h>

lab3_2::spline::spline()
{
   // this->t = nullptr;
    //this->ti = nullptr;
    /*for (int i = 0; i < x.size(); ++i)
    {
        std::cout << (*(this->t))[i].first << " : " << (*(this->t))[i].second << "\n";
    }*/
    this->x = new std::vector < double > ;
    this->x->push_back(0.1);
    this->x->push_back(0.5);
    this->x->push_back(0.9);
    this->x->push_back(1.3);
    this->x->push_back(1.7);
    this->f = new std::vector < double >;
    this->f->push_back(-2.2026);
    this->f->push_back(-0.19315);
    this->f->push_back(0.79464);
    this->f->push_back(1.5624);
    this->f->push_back(2.2306);
    this->a = new std::vector < double >(this->x->size() - 1, 0);
    this->b = new std::vector < double >(this->x->size() - 1, 0);
    this->c = new std::vector < double >(this->x->size() - 1, 0);
    this->d = new std::vector < double >(this->x->size() - 1, 0);
}

lab3_2::spline::~spline()
{
    delete this->x;
    delete this->a;
    delete this->b;
    delete this->c;
    delete this->d;
}

void lab3_2::spline::initInterpolation()
{
    lab1_2::system sys(3);
    sys.seta(0, 0);
    sys.seta(1, 0.4);
    sys.seta(2, 0.4);
    sys.setb(0, 1.6);
    sys.setb(1, 1.6);
    sys.setb(2, 1.6);
    sys.setc(0, 0.4);
    sys.setc(1, 0.4);
    sys.setc(2, 0);
    sys.setext(0, 3 * ((0.79464 - -0.19315) / 0.4 - (-0.19315 - -2.2026) / 0.4));
    sys.setext(1, 3 * ((1.5624 - 0.79464) / 0.4 - (0.79464 - -0.19315) / 0.4));
    sys.setext(2, 3 * ((2.2306 - 1.5624) / 0.4 - (1.5624 - 0.79464) / 0.4));
    std::vector<double> *res = sys.getResult();
    /*for (int i = 0; i < res->size(); ++i)
    {
        std::cout << "r " << (*(res))[i] << "\n";
    }*/
    (*(this->a))[0] = 0;
    for (int i = 0; i < this->a->size(); ++i)
    {
        (*(this->a))[i] = (*(this->f))[i];
    }
    (*(this->c))[0] = 0;
    for (int i = 0; i < res->size(); ++i)
    {
        (*(this->c))[i + 1] = (*(res))[i];
    }
    for (int i = 0; i < this->b->size() - 2; ++i)
    {
        (*(this->b))[i] = ((*(this->f))[i + 1] - (*(this->f))[i]) / 0.4 - 1.0 / 3.0 * 0.4 * ((*(this->c))[i + 2] + 2.0 * (*(this->c))[i + 1]);
    }
    for (int i = 0; i < this->d->size() - 2; ++i)
    {
        (*(this->d))[i] = ((*(this->c))[i + 2] - (*(this->c))[i + 1]) / (3.0 * 0.4);
    }
    (*(this->c))[0] = 0;
    //int n = this->f->size() - 2;
    int n = 3;
    (*(this->b))[3] = ((*(this->f))[n] - (*(this->f))[n - 1]) / 0.4 - 2.0 / 3 * 0.4 * (*(res))[res->size() - 1];
    (*(this->d))[3] = -(*(res))[res->size() - 1] / (3 * 0.4);
    delete res;
    for (int i = 0; i < this->a->size(); ++i)
    {
        std::cout << "a " << (*(this->a))[i] << " " <<
            "b " << (*(this->b))[i] << " " <<
            "c " << (*(this->c))[i] << " " <<
            "d " << (*(this->d))[i] << "\n";
    }
}

double lab3_2::spline::getvalue(double arg)
{
    double fxi = 0;
    /*for (int i = 0; i < this->a->size(); ++i)
    {
        std::cout << "a : " << (*(this->a))[i] << "\n";
    }
    for (int i = 0; i < this->b->size(); ++i)
    {
        std::cout << "b : " << (*(this->b))[i] << "\n";
    }
    for (int i = 0; i < this->c->size(); ++i)
    {
        std::cout << "c : " << (*(this->c))[i] << "\n";
    }
    for (int i = 0; i < this->d->size(); ++i)
    {
        std::cout << "d : " << (*(this->d))[i] << "\n";
    }
    */
    int i = 0;
    while (arg >= (*(this->x))[i])
    {
      //  std::cout << "arg " << arg << " x " << (*(this->x))[i] << "\n";
        ++i;
    }
    //std::cout << "i: " << i << "\n";
    --i;
    //if ()
    fxi = (*(this->a))[i] + (*(this->b))[i] * (arg - (*(this->x))[i]) + (*(this->c))[i] * 
        pow((arg - (*(this->x))[i]), 2) + (*(this->d))[i] * pow((arg - (*(this->x))[i]), 3);
    //std::cout << "fxi: " << fxi << "\n";
    return fxi;
}

void lab3_2::spline::val()
{
    std::cout << "# x y\n";
    for (double x = 0.1; x < 1.7; x += 0.01)
    {
        std::cout << x << " " << this->getvalue(x) << "\n";
    }
}