#include <iomanip>
#include <iostream>
#include <cmath>

using namespace std;

double arithmeticMean()
{
    int currentSummand = 0;
    double sum = 0.0;
    int numberOfSummands = 0;
    do
    {
        cin >> currentSummand;
        sum += currentSummand;
        numberOfSummands++;
    } while (currentSummand);
    numberOfSummands--;
    return (numberOfSummands ? sum / numberOfSummands : 0.0);
}

int main()
{
    double result = arithmeticMean();
    cout << endl << fixed << setprecision(6) << result;
    return 0;
}

