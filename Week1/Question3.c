// Q3. Write a C program to find the maximum between three numbers.

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int number1, number2, number3;

    printf("Enter a two number: ");
    scanf("%d %d %d", &number1, &number2, &number3);

    if (number1 >= number2) {
        if (number1 >= number3)
            printf("%d is maximum\n", number1);
        else
            printf("%d is maximum\n", number3);
    }
    else {
        if (number2 >= number3)
            printf("%d is maximum\n", number2);
        else
            printf("%d is maximum\n", number3);
    }

    return 0;
}