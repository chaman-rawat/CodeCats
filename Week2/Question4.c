// Write a C program to determine whether a given number is prime or not.
#include <stdio.h>

int is_prime(int);
void primes_in_range(int);

int main(int argc, char const *argv[])
{
    int number;
    printf("Input a number: ");
    scanf("%d", &number);

    if (is_prime(number))
        printf("%d is a prime number.\n", number);
    else
        printf("%d is not a prime number.\n", number);

    printf("Prime numbers within %d are: \n", number);
    primes_in_range(number);
    return 0;
}

int is_prime(int number) {
    for (int i = 2; i <= (number / 2); i++)
        if (!(number % i))            
            return 0;
    return 1;
}

void primes_in_range(int range) {
    for (int number = 1; number <= range; number++)
        if(is_prime(number))
            printf("%d ", number);
    printf("\n");
}