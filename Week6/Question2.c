// Check Whether a number is a Duck Number or Not
#include <stdio.h>

int is_duck_number(char *);

int main()
{
    char number[50];
    printf("Input string 1: ");
    scanf("%s", number);

    if (is_duck_number(number))
        printf("It is a duck number.\n");
    else
        printf("It is not a duck number.\n");
    return 0;
}

int is_duck_number(char *num)
{
    for (int i = 1; num[i] != '\0'; i++)
        if (num[i] == '0')
            if (num[i - 1] >= '1' && num[i - 1] <= '9')
                return 1;
    return 0;
}