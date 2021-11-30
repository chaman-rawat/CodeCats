// Check Whether a number is a Duck Number or Not
#include <stdio.h>

int is_duck_number(unsigned long);

int main()
{
    unsigned long number;
    printf("Input: ");
    scanf("%lu", &number);

    if (is_duck_number(number))
        printf("It is a duck number.\n");
    else
        printf("It is not a duck number.\n");
    return 0;
}

int is_duck_number(unsigned long num)
{
    do
    {
        if (!(num % 10) && num % 100)
            return 1;
    } while (num /= 10);

    return 0;
}