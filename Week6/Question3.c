// Longest Subsequence where every character appears at least k-times
#include <stdio.h>

void print_subsequence(char *, int);

int main()
{
    char str[100];
    printf("String = ");
    scanf("%s", str);

    int k;
    printf("k = ");
    scanf("%d", &k);

    print_subsequence(str, k);
    return 0;
}

void print_subsequence(char *str, int k)
{
    int count_letters[26] = {0};
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] < 97) // Uppercase to lowercase letters
            str[i] = str[i] + 32;
        count_letters[str[i] - 'a']++;
    }

    for (int i = 0; str[i] != '\0'; i++)
        if (count_letters[str[i] - 'a'] >= k)
            printf("%c", str[i]);
}