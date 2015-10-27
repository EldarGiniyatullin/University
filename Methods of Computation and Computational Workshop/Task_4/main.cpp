#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

static double x_s_1 = 0.128079;
static double x_s_2 = 0.703418;
static double x_s_3 = 0.530937;

static double y_s = 1.692909;

vector< vector<double> > count(int howMany, int n, double values[])
{
    vector< vector<double> > array(n, vector<double>(n));
    for (int i = 0; i < n; i++)
    {
        array[i][0] = values[i];
    }
    for (int i = 1; i <= howMany; i++)
    {
        for (int j = 0; j < n - i; j++)
        array[j][i] = array[j+1][i-1] - array[j][i-1];
    }
    return array;
}

double headPolynom(vector< vector<double> > subs, double t, double i)
{
    return subs[i][0] + t*subs[i][1] + t*(t-1)*subs[i][2]/2.0 + t*(t-1)*(t-2)*subs[i][3]/6.0 + t*(t-1)*(t-2)*(t-3)*subs[i][4]/24.0;
}

double endPolynom(vector< vector<double> > subs, double t, double i)
{
    return subs[i][0] + t*subs[i-1][1] + t*(t+1)*subs[i-2][2]/2.0 + t*(t+1)*(t+2)*subs[i-3][3]/6.0 + t*(t+1)*(t+2)*(t+3)*subs[i-4][4]/24.0;
}

int main()
{
    double values[10] = {1.614419, 1.656832, 1.694888, 1.728606, 1.758030, 1.783225, 1.804279, 1.821299, 1.834414, 1.843768};
    vector< vector<double> > subs = count(4, 10, values);
//    fstream fout("result.txt", ios_base::trunc);
//    fout.open("result.txt");
//    for (int j = 0; j < 10; j++)
//    {
//        //fout << std::fixed << std::setprecision(9) << values[j] << "   ";
//        for (int i = 0; i <= 4 && i < 10 - j; i++)
//        {
//            fout << std::fixed << std::setprecision(9) << subs[j][i] << "   ";
//        }
//        fout << "\n";
//    }
    cout << "X[i]          X*            X[i+1]" << endl;
    cout << std::fixed << std::setprecision(9) << values[1] << "   " << headPolynom(subs, (x_s_1 - 0.1)/0.1, 1) << "   " << values[2] << endl;
    cout << std::fixed << std::setprecision(9) << values[7] << "   " << endPolynom(subs, (x_s_2 - 0.8)/0.1, 8) << "   " << values[8] << endl;
    return 0;
}

