// Diagonal Traversal
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

    cout << "\nResult:\n";

    for (int i = 0; i < r; i++)
        for (int j = 0; j < r - i; j++)
            cout << matrix[j][j + i] << " ";

    return 0;
}