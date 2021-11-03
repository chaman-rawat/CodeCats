// COIN-FLIP GAME
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int T, G;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &G);
        int games[G][3], result[G];
        for (int i = 0; i < G; i++)
        {
            scanf("%d%d%d", &games[i][0], &games[i][1], &games[i][2]);
            result[i] = (games[i][1] + (games[i][0] == games[i][2] ? 0 : 1)) / 2;
        }
        for (int i = 0; i < G; i++)
            printf("%d\n", result[i]);
    }
    return 0;
}