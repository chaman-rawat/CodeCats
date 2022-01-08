// Search in a sorted array
#include <iostream>
using namespace std;

int main()
{
    int r, ele;
    cin >> r >> ele;

    int matrix[r][r];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < r; j++)
            cin >> matrix[i][j];

    cout << "\nResult:\n";
    int x = 0, y = r - 1;
    while (x <= r && y <= r)
    {
        if (ele == matrix[x][y])
        {
            cout << x << ", " << y << endl;
            return 0;
        }

        if (ele > matrix[x][y])
            x++;
        else
            y--;
    }

    cout << "Element Not Found" << endl;
    return 0;
}