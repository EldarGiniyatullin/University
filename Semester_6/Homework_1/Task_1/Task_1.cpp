#include <iostream>
#include <cmath>

using namespace std;

//считает сумму кубов в лоб
double countRow(int n)
{
    double sum = 0.0;
    for (int i = 1; i <= 2 * n + 1; i+=2)
        sum += 1/pow(i, 3);
    return sum;
}

//считает сумму обобщенного гармонического ряда, начиная с @param from заканчивая @param to
double partialSum(unsigned int degree, unsigned int from, unsigned int to)
{
    double sum = 0.0;
    for (unsigned int i = from; i <= to; i++)
        sum += 1/pow(i, degree);
    return sum;
}

int main()
{
    int n = 0;
    cin >> n;
    double sumCountRow = countRow(n);
    double sumPartialSum = partialSum(3, 1, 2*n+2) - 0.125*partialSum(3, 1, n+1);
    cout << sumCountRow << " = " << sumPartialSum;
    return 0;
}

