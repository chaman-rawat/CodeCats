// Matrix multiplication
#include <iostream>
using namespace std;

int main()
{
    int n1, n2, m1, m2;

    cin >> n1 >> m1;
    int mat1[n1][m1];
    for (int r = 0; r < n1; r++)
        for (int c = 0; c < m1; c++)
            cin >> mat1[r][c];

    cin >> n2 >> m2;
    int mat2[n2][m2];
    for (int r = 0; r < n2; r++)
        for (int c = 0; c < m2; c++)
            cin >> mat2[r][c];

    if (m1 != n2)
    {
        cout << "Multiplication not possible!";
        return 1;
    }

    int res_mat[n1][m2];

    for (int r = 0; r < n1; r++)
        for (int c = 0; c < m2; c++)
        {
            res_mat[r][c] = 0;
            for (int x = 0; x < n2; x++)
                res_mat[r][c] += mat1[r][x] * mat2[x][c];
        }

    cout << "\nResult: " << endl;
    for (int r = 0; r < n1; r++)
    {
        for (int c = 0; c < m2; c++)
            cout << res_mat[r][c] << '\t';
        cout << endl;
    }

    return 0;
}