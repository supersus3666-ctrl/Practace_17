#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
    srand(time(NULL));

    const int row = 3;
    const int col = 4;
    int a[row][col];
    int zeros = 0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            a[i][j] = rand() % 4;
            cout << a[i][j] << "\t";
            if (a[i][j] == 0)
                zeros++;
        }
        cout << "\n";
    }

    cout << "\nKolichestvo nulevyh elementov = " << zeros << "\n";

    return 0;
}
