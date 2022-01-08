// Find given matrix is Toeplitz or not (A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same elements).
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;
    cin >> m;
    cin >> n;

    int matrix[m][n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];

    int cur_diag_value;

    // Lower Diagonals
    for (int i = m - 1, diff = m; i >= 0 && diff--; i--)
    {
        cur_diag_value = matrix[i][i - diff];
        for (int j = i; j < m && (j - diff) < n; j++)
            if (cur_diag_value != matrix[j][j - diff])
            {
                cout << "\nThis is not a Toeplitz Matrix" << endl;
                return 0;
            }
    }

    // Upper diagonals
    for (int i = n - 1, diff = n; i > 0 && diff--; i--)
    {
        cur_diag_value = matrix[i - diff][i];
        for (int j = i; (j - diff) < m && j < n; j++)
            if (cur_diag_value != matrix[j - diff][j])
            {
                cout << "\nThis is not a Toeplitz Matrix" << endl;
                return 0;
            }
    }

    cout << "\nThis is a Toeplitz Matrix" << endl;
    return 0;
}