#pragma once
#include<vector>
/*namespace lab3_2
{
    class spline
    {
    private:
        std::vector<double> *x;
        std::vector<double> *f;
        std::vector<double> *a;
        std::vector<double> *b;
        std::vector<double> *c;
        std::vector<double> *d;
    public:
        spline();
        virtual ~spline();
        void initInterpolation();
        double getvalue(double x);
        void val();
    };
}*/
class cubic_spline
{
private:
    // ���������, ����������� ������ �� ������ �������� �����
    struct spline_tuple
    {
        double a, b, c, d, x;
    };

    spline_tuple *splines; // ������
    std::size_t n; // ���������� ����� �����

    void free_mem(); // ������������ ������

public:
    cubic_spline(); //�����������
    ~cubic_spline(); //����������

    // ���������� �������
    // x - ���� �����, ������ ���� ����������� �� �����������, ������� ���� ���������
    // y - �������� ������� � ����� �����
    // n - ���������� ����� �����
    void build_spline(const double *x, const double *y, std::size_t n);

    // ���������� �������� ����������������� ������� � ������������ �����
    double f(double x) const;
};

