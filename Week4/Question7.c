// Odd Grasshopper
#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int x, n, i = 0;
        scanf("%d %d", &x, &n);
        while (i++ < n)
            x += (x & 1) ? i : -i;
        printf("Output: %d\n", x);
    }
    return 0;
}