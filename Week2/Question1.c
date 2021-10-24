// Write a program in C to display n terms of natural number and their sum.
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int number,
        sum = 0,
        sum_odd = 0,
        sum_even = 0;

    printf("Enter a natural number: ");
    scanf("%d", &number);

    // Calculate sum numbers
    for (int i = 1; i <= number; i++) {
        printf("%d ", i);
        sum += i;
        if (i & 1)
            sum_odd += i;
        else
            sum_even += i;
    }
    
    printf("\nThe Sum of Natural Numbers upto %d terms: %d\n", number, sum);
    printf("The Sum of Odd Natural Numbers upto %d terms: %d\n", number, sum_odd);
    printf("The Sum of Even Natural Numbers upto %d terms: %d\n", number, sum_even);
    return 0;
}