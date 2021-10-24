// Write a program in C to display the number in reverse order.
#include <stdio.h>
#include <math.h>

int to_reverse (int);
int digits_in_number (int);

int main(int argc, char const *argv[])
{
    int number;
    printf("Input a number: ");
    scanf("%d", &number);
    printf("The number in reverse order is: %d\n", to_reverse(number));
    return 0;
}

int to_reverse (int number){
    int reverse_number = 0,
        digits = digits_in_number(number);

    for (int i = number; i > 0 ; i/=10, digits--)
        reverse_number += (i%10) * pow(10, digits - 1);

    return reverse_number;
}

int digits_in_number (int number) {
    int digits = 0;
    for (number; number > 0; number /= 10)
        digits++;

    return digits;
}