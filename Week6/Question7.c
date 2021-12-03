// Check Whether Two Strings are Almost Equivalent
#include <stdio.h>
#include <stdbool.h>
bool check_almost_equivalent(char *, char *);

int main()
{
    char word1[50], word2[50];
    printf("Word1: ");
    scanf("%s", word1);
    printf("Word2: ");
    scanf("%s", word2);

    check_almost_equivalent(word1, word2)
        ? printf("True\n")
        : printf("False\n");
    return 0;
}

bool check_almost_equivalent(char *word1, char *word2)
{
    short count1[26] = {0};
    short count2[26] = {0};

    for (int i = 0; word1[i]; i++)
    {
        count1[word1[i] - 'a']++;
        count2[word2[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++)
        if ((count1[i] - count2[i]) * (count1[i] - count2[i]) > 9)
            return false;
    return true;
}