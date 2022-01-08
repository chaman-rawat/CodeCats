// Exit Point Of A Matrix
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

    int x = 0, y = 0;
    int result[2];
    int dir = 0;

    // Direction
    // 0 -> east
    // 1 -> south
    // 2 -> west
    // 3 -> north

    while (x >= 0 && x < r && y >= 0 && y < c)
    {
        result[0] = x;
        result[1] = y;

        if (matrix[x][y] == 1)
            dir = (dir + 1) % 4;

        if (dir == 0)
            y++;
        else if (dir == 1)
            x++;
        else if (dir == 2)
            y--;
        else
            x--;
    }

    cout << "Result: (" << result[0] << ", " << result[1] << ")" << endl;
    return 0;
}