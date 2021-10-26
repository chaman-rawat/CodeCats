// Write a program in C to display n terms of natural number and their sum.
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int num;

    printf("Enter a natural number: ");
    scanf("%d", &num);

    // Calculate sum numbers
    int sum = num * (num + 1) / 2,
        sum_odd = (num & 1) ? (num / 2 + 1)*(num / 2 + 1) : (num / 2) * (num / 2),
        sum_even = sum - sum_odd;

    printf("\nThe Sum of Natural Numbers upto %d terms: %d\n", num, sum);
    printf("The Sum of Odd Natural Numbers upto %d terms: %d\n", num, sum_odd);
    printf("The Sum of Even Natural Numbers upto %d terms: %d\n", num, sum_even);
    return 0;
}