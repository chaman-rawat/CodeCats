// Write a C program to check whether a given number is an armstrong number or not.
#include <stdio.h>

int is_armstrong (int);
int cube_of (int);

int main(int argc, char const *argv[])
{
    int number;
    printf("Input a number: ");
    scanf("%d", &number);

    if (is_armstrong(number))
        printf("%d is an Armstrong number.\n", number);
    else        
        printf("%d is not an Armstrong number.\n", number);
    return 0;
}

int is_armstrong (int number) {
    int sum = 0,            // To store sums of digit's cubes
        temp = number;

    do
        sum += cube_of(temp % 10);
    while ((temp /= 10) != 0);
    
    return sum == number;
}

int cube_of (int number) {
    return number * number * number;
}