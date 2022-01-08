// Find transpose matrix of a given matrix
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

    int transpose[c][r];
    for (int i = 0; i < c; i++)
        for (int j = 0; j < r; j++)
            transpose[i][j] = matrix[j][i];

    cout << "\nResult:\n";
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
            cout << transpose[i][j] << ' ';
        cout<< endl;
    }
    return 0;
}