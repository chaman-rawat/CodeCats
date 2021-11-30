// Find one extra character in a string
#include <stdio.h>

int main()
{
    char str1[50], str2[50];
    printf("Input string 1: ");
    scanf("%[^\n]s", str1);

    printf("Input string 2: ");
    scanf(" %[^\n]s", str2);

    int hash1[128] = {0};
    int hash2[128] = {0};

    for (int i = 0; str2[i] != '\0'; i++)
    {
        if (str1[i] != '\0')
            hash1[str1[i]]++;
        hash2[str2[i]]++;
    }

    for (int i = 0; i < 128; i++)
        if (hash1[i] != hash2[i])
        {
            printf("%c\n", i);
            break;
        }

    return 0;
}
