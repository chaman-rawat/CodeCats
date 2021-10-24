// C program to find power of a number using for loop.
#include <stdio.h>

int find_power(int, int);

int main(int argc, char const *argv[])
{
    int base, exponent;
    printf("Input two numbers: ");
    scanf("%d %d", &base, &exponent);
    printf("%d^%d : %d\n", base, exponent, find_power(base, exponent));
    return 0;
}

int find_power(int base, int exponent) {
    if (exponent == 1)      // Base Case
        return base * 1;

    return base * find_power(base, --exponent);
}