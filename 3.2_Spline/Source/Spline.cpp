#include<iostream>
#include<Spline.h>
#include<utility>
#include<cmath>
#include<Prog.h>

/*lab3_2::spline::spline()
{
   // this->t = nullptr;
    //this->ti = nullptr;
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
    for (int i = 0; i < res->size(); ++i)
    {
        std::cout << "r " << (*(res))[i] << "\n";
    }
    //(*(this->a))[0] = 0;
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
        (*(this->b))[i] = ((*(this->f))[i + 1] - (*(this->f))[i]) / 0.4
            - 0.4 / 3.0 * ((*(this->c))[i + 2] + 2.0 * (*(this->c))[i + 1]);
    }
    for (int i = 0; i < this->d->size() - 2; ++i)
    {
        (*(this->d))[i] = ((*(this->c))[i + 2] - (*(this->c))[i + 1]) / (3.0 * 0.4);
    }
    (*(this->c))[0] = 0;
    //int n = this->f->size() - 2;
    int n = 3;
    (*(this->b))[3] = ((*(this->f))[n + 1] - (*(this->f))[n]) / 0.4 - 2.0 / 3 * 0.4 * (*(res))[res->size() - 1];
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
}*/

#include <cstdlib>
#include <cmath>
#include <limits>

cubic_spline::cubic_spline() : splines(NULL)
{

}

cubic_spline::~cubic_spline()
{
    free_mem();
}

void cubic_spline::build_spline(const double *x, const double *y, std::size_t n)
{
    free_mem();

    this->n = n;

    // Инициализация массива сплайнов
    splines = new spline_tuple[n];
    for (std::size_t i = 0; i < n; ++i)
    {
        splines[i].x = x[i];
        splines[i].a = y[i];
    }
    splines[0].c = 0.;

    // Решение СЛАУ относительно коэффициентов сплайнов c[i] методом прогонки для трехдиагональных матриц
    // Вычисление прогоночных коэффициентов - прямой ход метода прогонки
    double *alpha = new double[n - 1];
    double *beta = new double[n - 1];
    double A, B, C, F, h_i, h_i1, z;
    alpha[0] = beta[0] = 0.;
    for (std::size_t i = 1; i < n - 1; ++i)
    {
        h_i = x[i] - x[i - 1], h_i1 = x[i + 1] - x[i];
        A = h_i;
        C = 2. * (h_i + h_i1);
        B = h_i1;
        F = 6. * ((y[i + 1] - y[i]) / h_i1 - (y[i] - y[i - 1]) / h_i);
        z = (A * alpha[i - 1] + C);
        alpha[i] = -B / z;
        beta[i] = (F - A * beta[i - 1]) / z;
    }

    splines[n - 1].c = (F - A * beta[n - 2]) / (C + A * alpha[n - 2]);

    // Нахождение решения - обратный ход метода прогонки
    for (std::size_t i = n - 2; i > 0; --i)
        splines[i].c = alpha[i] * splines[i + 1].c + beta[i];

    // Освобождение памяти, занимаемой прогоночными коэффициентами
    delete[] beta;
    delete[] alpha;

    // По известным коэффициентам c[i] находим значения b[i] и d[i]
    for (std::size_t i = n - 1; i > 0; --i)
    {
        double h_i = x[i] - x[i - 1];
        splines[i].d = (splines[i].c - splines[i - 1].c) / h_i;
        splines[i].b = h_i * (2. * splines[i].c + splines[i - 1].c) / 6. + (y[i] - y[i - 1]) / h_i;
    }
}

double cubic_spline::f(double x) const
{
    if (!splines)
        return std::numeric_limits<double>::quiet_NaN(); // Если сплайны ещё не построены - возвращаем NaN

    spline_tuple *s;
    if (x <= splines[0].x) // Если x меньше точки сетки x[0] - пользуемся первым эл-том массива
        s = splines + 1;
    else if (x >= splines[n - 1].x) // Если x больше точки сетки x[n - 1] - пользуемся последним эл-том массива
        s = splines + n - 1;
    else // Иначе x лежит между граничными точками сетки - производим бинарный поиск нужного эл-та массива
    {
        std::size_t i = 0, j = n - 1;
        while (i + 1 < j)
        {
            std::size_t k = i + (j - i) / 2;
            if (x <= splines[k].x)
                j = k;
            else
                i = k;
        }
        s = splines + j;
    }

    double dx = (x - s->x);
    return s->a + (s->b + (s->c / 2. + s->d * dx / 6.) * dx) * dx; // Вычисляем значение сплайна в заданной точке.
}

void cubic_spline::free_mem()
{
    delete[] splines;
    splines = NULL;
}