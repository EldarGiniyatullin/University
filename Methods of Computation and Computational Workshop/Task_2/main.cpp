#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <QList>

using namespace std;

static double x_min = 0.0;
static double x_max = 2.0;
static double y_min = 0.0;
static double y_max = 2.0;
static double epsilon = 0.000001;
static double epsilon2 = 0.00000000001;
static double digits = 6;
static double k = 0.5;
static double a = 0.7;

struct x_y
{
    double x;
    double y;
};

operator == (x_y c, x_y b)
{
    return (fabs(c.x - b.x) < epsilon2 && fabs(c.y - b.y) < epsilon2);
}

operator != (x_y c, x_y b)
{
    return (fabs(c.x - b.x) > epsilon2 || fabs(c.y - b.y) > epsilon2);
}

double f(double x, double y)
{
    return cosh(k*x*x + y) - x + y - 1.0;
}

double g(double x, double y)
{
    return pow((x - 0.1) / a, 2) - y*y/2 - 0.8;
}

double df_dx(double x, double y)
{
    return sinh(k*x*x + y)*2*k*x - 1.0;
}

double df_dy(double x, double y)
{
    return sinh(k*x*x + y) + 1.0;
}

double dg_dx(double x, double y)
{
    return (2*(x - 0.1)) / (a*a);
}

double dg_dy(double x, double y)
{
    return -y;
}

double deltaX(double x, double y)
{
    return g(x, y)*df_dy(x, y) - f(x, y)*dg_dy(x, y);
}

double deltaY(double x, double y)
{
    return f(x, y)*dg_dx(x, y) - g(x, y)*df_dx(x, y);
}

double Delta(double x, double y)
{
    return df_dx(x, y)*dg_dy(x, y) - df_dy(x, y)*dg_dx(x, y);
}

double bigX(double x, double y)
{
    return deltaX(x, y)/Delta(x, y);
}

double bigY(double x, double y)
{
    return deltaY(x, y)/Delta(x, y);
}

x_y do_x_k(double x_0, double y_0, bool toPrint)
{
    int i = 0;
    double x_k = x_0;
    double y_k = y_0;
    double x_k_plus_1 = x_0;
    double y_k_plus_1 = y_0;
    if (toPrint)
    {
        cout << "\n--------------------------------------------------------------------------------\n";
        cout << fixed << setprecision(1) << "k = " << k << ";  a = " << a << endl;
    }
    do
    {
        if (toPrint)
            cout << i << " " << fixed << setprecision(digits) << x_k_plus_1 << "  " << y_k_plus_1 << " " << f(x_k_plus_1, y_k_plus_1) << " " << g(x_k_plus_1, y_k_plus_1) << endl << setprecision(0);
        x_k = x_k_plus_1;
        y_k = y_k_plus_1;
        x_k_plus_1 = x_k + bigX(x_k, y_k);
        y_k_plus_1 = y_k + bigY(x_k, y_k);
        i++;
    }while (fabs(x_k_plus_1 - x_k) > epsilon || fabs(y_k_plus_1 - y_k) > epsilon);
    if (toPrint)
    {
        cout << i << " " << fixed << setprecision(digits) << x_k_plus_1 << "  " << y_k_plus_1 << " " << f(x_k_plus_1, y_k_plus_1) << " " << g(x_k_plus_1, y_k_plus_1) << endl << setprecision(0);
        cout << "\n--------------------------------------------------------------------------------\n";
    }
    return {x_k_plus_1, y_k_plus_1};
}

void task_1()
{
    QList<x_y> values;
    x_y newValues;
    for (a = 0.7; a <= 1.2; a += 0.1)
    {
        for (k = 0.5; k >= 0.1; k -= 0.1)
        {
            for (double x = x_min; x <= x_max; x+=0.01)
            {
                for (double y = y_min; y <= y_max; y+=0.01)
                {
                    if (fabs(f(x, y)) < 0.1 && fabs(g(x, y)) < 0.1)
                    {
                        newValues = do_x_k(x, y, false);
                        if (!values.contains(newValues))
                        {
                            values.push_back(newValues);
                            do_x_k(x, y, true);
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    task_1();
    system("pause");
    return EXIT_SUCCESS;
}
