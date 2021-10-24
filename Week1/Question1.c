// Q1. Write a C program to check whether a number is even or odd.

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int number;
    
    printf("Enter a number: ");
    scanf("%d", &number);

    // Using bitwise AND operator
    if (number&1)
        printf("%d is a odd number\n", number);
    else
        printf("%d is a even number\n", number);

    // Using modulus operator
    // if (number%2 == 0)
    //     printf("%d is a even number\n", number);
    // else
    //     printf("%d is a odd number\n", number);

    return 0;
}