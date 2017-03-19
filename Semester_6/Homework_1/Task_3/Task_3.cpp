#include <iostream>

using namespace std;

int numberOfNonZeroes(int* array, int size)
{
    int* p = array;
    do
    {
        if (!*p)
            break;
        p++;
    } while(p <= array + size);
    return p - array;
}

int main()
{
    int a[10] {2, 3, 7, 9, 0, 0, 0, 0, 0, 0}; // == int a[10] {2, 3, 7, 9};
    int b[10] {2, 3, 7, 9, 4, 6, 2, -3, 5, 4};
    int c[10] {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int d[10] {5, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    cout << numberOfNonZeroes(a, 10) << endl;
    cout << numberOfNonZeroes(b, 10) << endl;
    cout << numberOfNonZeroes(c, 10) << endl;
    cout << numberOfNonZeroes(d, 10) << endl;
    return 0;
}

