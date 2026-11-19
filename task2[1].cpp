#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

const int N = 7;

// Проверка: попадает ли элемент [i][j] в тёмно-синюю часть фигуры.
bool inZone(int fig, int i, int j)
{
    bool top    = (i <= j && i <= N - 1 - j);
    bool bottom = (i >= j && i >= N - 1 - j);
    bool left   = (j <= i && j <= N - 1 - i);
    bool right  = (j >= i && j >= N - 1 - i);

    switch (fig)
    {
    case 1:  return j >= i;
    case 2:  return j <= i;
    case 3:  return top;
    case 4:  return bottom;
    case 5:  return top || bottom;
    case 6:  return left || right;
    case 7:  return left;
    case 8:  return right;
    case 9:  return i + j <= N - 1;
    case 10: return i + j >= N - 1;
    }
    return false;
}

//Задание 2: наибольший элемент в тёмно - синих частях матрицы
int main()
{
    srand(time(NULL));

    int m[N][N];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            m[i][j] = rand() % 100;
            cout << m[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";

    const char* names[10] = { "a", "b", "v", "g", "d", "e", "zh", "z", "i", "k" };

    for (int fig = 1; fig <= 10; fig++)
    {
        bool found = false;
        int max = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (inZone(fig, i, j))
                {
                    if (!found || m[i][j] > max)
                    {
                        max = m[i][j];
                        found = true;
                    }
                }
            }
        }
        cout << "Figura " << names[fig - 1] << ": max = " << max << "\n";
    }

    return 0;
}
