// Wave Traversal
#include <iostream>
using namespace std;

int main()
{
    int r, c;
    cin >> r;
    cin >> c;

    int matrix[r][c];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> matrix[i][j];

    for (int i = 0; i < r; i++)
    {
       if (i % 2 == 0)
            for (int j = 0; j < c; j++)
                cout << ' ' << matrix[j][i];
        else
            for (int j = c - 1; j >= 0; j--)
                cout << ' ' << matrix[j][i];
    }

    return 0;
}