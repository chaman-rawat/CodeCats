// Write a C program to calculate the factorial of a given number.
#include <stdio.h>

int factorial (int);

int main(int argc, char const *argv[])
{
    int number;
    printf("Input the number: ");
    scanf("%d", &number);

    printf("The Factorial of %d is: %d\n", number, factorial(number));
    return 0;
}

int factorial (int number) {
    if (number == 1 || number == 0) // Base case
        return 1;

    return number * factorial(number - 1);
}