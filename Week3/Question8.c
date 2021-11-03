// COIN-FLIP GAME
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int T, G;
    scanf("%d%d", &T, &G);
    int games[G][3];
    for (int i = 0; i < G; i++)
        scanf("%d%d%d", &games[i][0], &games[i][1], &games[i][2]);

    int result[G];
    for (int i = 0; i < G; i++)
    {
        int game[games[i][1]];
        result[i] = 0;

        // Set coins face to default before playing
        for (int j = 0; j < games[i][1]; j++)
            game[j] = (games[i][0] == 1) ? 1 : 2;

        // Flip the coins
        for (int j = 0; j < games[i][1]; j++)
            for (int k = 0; k <= j; k++)
                game[k] = (game[k] == 1) ? 2 : 1;

        // All turns over now, count the result
        for (int j = 0; j < games[i][1]; j++)
            if (games[i][2] == game[j])
                result[i]++;
    }

    for (int i = 0; i < G; i++)
        printf("%d\n", result[i]);
    return 0;
}