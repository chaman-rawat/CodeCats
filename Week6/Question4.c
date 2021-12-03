// Roman to Integer
#include <stdio.h>
#include <string.h>
#include <math.h>

int roman_to_int(char *);
int count_digits(int);

int main()
{
    char roman[10];
    printf("Input: ");
    scanf("%s", roman);

    int integer = roman_to_int(roman);
    printf("Output: %d\n", integer);
    return 0;
}

int roman_to_int(char *roman)
{
    const char symbol[] = "IVXLCDM";
    const int value[] = {1, 5, 10, 50, 100, 500, 1000};

    const int len = strlen(roman);
    const int symbol_len = strlen(symbol);
    int integer = 0;

    for (int i = 0; i < len; i++)
        for (int j = 0; j < symbol_len; j++)
            if (roman[i] == symbol[j]) // Symbol Identified
            {
                if ((j + 1) < symbol_len && roman[i + 1] == symbol[j + 1]) // Check special cases
                {
                    int exponent = count_digits(value[j + 1] - 1) - 1;
                    int subtract = pow(10, exponent);
                    integer += value[j + 1] - subtract;
                    i++; // skip next letter
                }
                else if ((j + 2) < symbol_len && roman[i + 1] == symbol[j + 2]) // Check special cases
                {
                    int exponent = count_digits(value[j + 2] - 1) - 1;
                    int subtract = pow(10, exponent);
                    integer += value[j + 2] - subtract;
                    i++; // skip next letter
                }
                else // No special case
                    integer += value[j];

                break;
            }

    return integer;
}

int count_digits(int number)
{
    int digit = 1;
    while (number /= 10)
        digit++;
    return digit;
}