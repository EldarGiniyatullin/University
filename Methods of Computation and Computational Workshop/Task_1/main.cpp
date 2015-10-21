#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double p_x4(double x)
{
    double x2 = x * x;
    return x2 * (x2 - 25.0) + 2 * x * (x2 - 1.0) + 24.0;
}

double d_p_x4(double x)
{
    double x2 = x * x;
    return 2 * (2 * x2 * x + 3 * x2 - 25 * x - 1);
}

double p_x2(double x)
{
    return 1.5 * x * x - sin(x) - 3;
}

double d_p_x2(double x)
{
    return 3 * x - cos(x);
}


double p_x12(double x)
{
    double x2 = x * x;
    double x4 = x2 * x2;
    double x8 = x4 * x4;
    return (128 * x8 * x2 * (x2 - 3) + 432 * x8 - 224 * x4 * x2 + 52.5 * x4 - 4.5 * x2) + 1.0 / 16.0;
}

double d_p_x12(double x)
{
    double x2 = x * x;
    double x4 = x2 * x2;
    double x8 = x4 * x4;
    return 512*3*x8*x2*x - 768*5*x8*x + 3456*x4*x2*x - 448*3*x4*x + 210*x2*x - 9*x;
}


void print_X_k(double x, double (*p_x)(double), double (*d_p_x)(double), bool toPrint)
{
    double x_k = x;
    double x_k_plus_1 = x;
    double p_x_k = p_x(x_k);
    double k = 0;
    if (toPrint)
        cout << k << "      " << fixed << setprecision(9) << x_k_plus_1 << "      " << p_x_k << endl << setprecision(0);
    do
    {
        x_k = x_k_plus_1;
        x_k_plus_1 = x_k - (p_x_k / d_p_x(x_k));
        p_x_k = p_x(x_k_plus_1);
        k++;
        if (toPrint)
            cout << k << "      " << fixed << setprecision(9) << x_k_plus_1 << "      " << p_x_k << endl << setprecision(0);
    }while (fabs(x_k - x_k_plus_1) > 0.00000001);
    cout << "\nx = " << fixed << setprecision(9) << x_k_plus_1 << "\np(x) = " << p_x_k << endl << setprecision(0);
}


void findZeros(double a, double b, double di, double (*p_x)(double), double (*d_p_x)(double), bool toPrint)
{
    if (p_x(a) == 0.0)
        cout << "x = " << fixed << setprecision(9) << a << endl << setprecision(0);
    bool mainState = (p_x(a) > 0.0 ? true : false);
    bool currentState;
    double currentValue;
    for (double i = a; i <= b; i += di)
    {
        currentValue = p_x(i);
        currentState = (currentValue > 0.0 ? true : false);
        if (mainState != currentState)
        {
            if (fabs(currentValue) > 0.1)
                findZeros(i - di, i, di / 10.0, p_x, d_p_x, toPrint);
            else
            {
                print_X_k(i, p_x, d_p_x, toPrint);
                cout << "\n";
            }
            mainState = currentState;
        }
    }
}


int main()
{
    double k1_x4 = 6.0;
    double k2_x4 = 1.0 / (1.0 + (25.0 / 24.0));
    double k3_x4 = -6.0;
    double k4_x4 = -1.0 / (1.0 + sqrt(25.0 / 24.0));

    double k1_x2 = 1 + sqrt(8.0 / 3.0);
    double k2_x2 = 1.0 / (1.0 + sqrt(3.0 / 8.0));
    double k3_x2 = -1.0 * k1_x2;
    double k4_x2 = -1.0 * k2_x2;

    double k1_x12 = 1.0 + sqrt(3.0);
    double k2_x12 = 1.0 / 73.0;
    double k3_x12 = -1.0 * k1_x12;
    double k4_x12 = -1.0 * k2_x12;
    cout << "x4+2x3+.." << endl;
    findZeros(k2_x4, k1_x4, 0.1, p_x4, d_p_x4, true);
    cout << "\n----------------------------------------------------------\n" << endl;
    findZeros(k3_x4, k4_x4, 0.1, p_x4, d_p_x4, true);
    cout << "\n\n----------------------------------------------------------\n\n" << endl;
    print_X_k(4.4, p_x4, d_p_x4, true);
    cout << "\n\n----------------------------------------------------------\n\n" << endl;
    cout << "1.5x2-sinx-.." << endl;
    findZeros(k2_x2, k1_x2, 0.1, p_x2, d_p_x2, true);
    cout << "\n----------------------------------------------------------\n" << endl;
    findZeros(k3_x2, k4_x2, 0.1, p_x2, d_p_x2, true);
    cout << "\n\n----------------------------------------------------------\n\n" << endl;

    cout << "2048x12+.." << endl;
    findZeros(k2_x12, k1_x12, 0.01, p_x12, d_p_x12, true);
    cout << "\n----------------------------------------------------------\n" << endl;
    findZeros(k3_x12, k4_x12, 0.01, p_x12, d_p_x12, true);
    cout << "\n\n----------------------------------------------------------\n\n" << endl;
    return 0;
}

