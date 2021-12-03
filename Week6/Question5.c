// Jewels and Stones
#include <stdio.h>

int find_jewels(char *, char *);

int main()
{
    char jewels[50], stones[50];
    printf("Jewels: ");
    scanf("%s", jewels);
    printf("Stones: ");
    scanf("%s", stones);
    printf("Output: %d\n", find_jewels(jewels, stones));
    return 0;
}

int find_jewels(char *jewels, char *stones)
{
    int count = 0;
    for (int i = 0; i < jewels[i] != '\0'; i++)
        for (int j = 0; stones[j] != '\0'; j++)
            if (jewels[i] == stones[j])
                count++;
    return count;
}