// COIN-FLIP GAME
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int T, G, I, N, Q;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &G);
        while (G--)
        {
            scanf("%d%d%d", &I, &N, &Q);
            printf("%d\n", (N + (I == Q ? 0 : 1)) / 2);
        }
    }
    return 0;
}