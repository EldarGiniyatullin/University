#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void count(int howMany, int n, double values[])
{
    double array[n][n];
    for (int i = 0; i < n; i++)
    {
        array[i][0] = values[i];
    }
    for (int i = 1; i <= howMany; i++)
    {
        for (int j = 0; j < n - i; j++)
        array[j][i] = array[j+1][i-1] - array[j][i-1];
    }
    fstream fout("result.txt", ios_base::trunc);
    fout.open("result.txt");
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i <= howMany && i < n - j; i++)
        {
            fout << std::fixed << std::setprecision(9) << array[j][i] << "   ";
        }
        fout << "\n";
    }
}


int main()
{
    double values[10] = {1.614419, 1.656832, 1.694888, 1.728606, 1.758030, 1.783225, 1.804279, 1.821299, 1.834414, 1.843768};
    count(4, 10, values);
    return 0;
}

