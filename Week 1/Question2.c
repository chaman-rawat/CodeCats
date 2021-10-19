// Q2. Write a C program to find the maximum between two numbers.

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int number1, number2;

    printf("Enter a two number: ");
    scanf("%d %d", &number1, &number2);

    if (number1 == number2)
        printf("Both numbers are equal\n");
    else if (number1 > number2)
        printf("%d is greater than %d\n", number1, number2);
    else
        printf("%d is greater than %d\n", number2, number1);
    return 0;
}