// Rotate By 90 Degree
#include <iostream>
using namespace std;

int main()
{
    int r;
    cin >> r;

    int matrix[r][r];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < r; j++)
            cin >> matrix[i][j];

    // Transpose
    for (int i = 0; i < r; i++)
        for (int j = i + 1; j < r; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }

    // Exchange columns
    for (int i = 0; i < r; i++)
        for (int j = 0; j < r / 2; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][r - j - 1];
            matrix[i][r - j - 1] = temp;
        }

    cout << "\nResult:\n";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }

    return 0;
}