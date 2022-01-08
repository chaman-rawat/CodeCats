// Saddle Point
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
    {
        int min_row_ele = 0;

        // Find least element of current row
        for (int j = 0; j < r; j++)
            if(matrix[i][j] < matrix[i][min_row_ele])
                min_row_ele = j;

        // Check if min row element is also max in it's column
        int k;
        for (k = 0; k < r; k++)
            if (matrix[k][min_row_ele] > matrix[i][min_row_ele])
                break;

        if (k == r)
        {
            cout << matrix[i][min_row_ele] << endl;
            return 0;
        }
    }

    cout << "No Saddle Point" << endl;
    return 0;
}