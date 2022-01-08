// Spiral Traversal
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

    cout << "\nResult:\n";

    int te = r * c, // total elements
        lw = 0,     // left wall
        uw = 0,     // upper wall
        rw = c - 1, // right wall
        dw = r - 1; // down wall

    while (te > 0)
    {
        // Left Wall
        for (int i = uw; i <= dw && te > 0; i++)
        {
            cout << matrix[i][lw] << ' ';
            te--;
        }
        lw++;

        // Down Wall
        for (int i = lw; i <= rw && te > 0; i++)
        {
            cout << matrix[dw][i] << ' ';
            te--;
        }
        dw--;

        // Right Wall
        for (int i = dw; i >= uw && te > 0; i--)
        {
            cout << matrix[i][rw] << ' ';
            te--;
        }
        rw--;

        // Up Wall
        for (int i = rw; i >= lw && te > 0; i--)
        {
            cout << matrix[uw][i] << ' ';
            te--;
        }
        uw++;
    }

    return 0;
}