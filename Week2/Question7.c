// Find number of trailing zeroes in the factorial of a given numbers array.
#include <stdio.h>
#include <math.h>

int count_factorial_trailing_zeroes(int);

int main(int argc, char const *argv[])
{
    int total_numbers;
    
    printf("Input numbers count and then numbers: ");
    scanf("%d", &total_numbers);
    
    int numbers[total_numbers];
    for (int i = 0; i < total_numbers; i++)
        scanf("%d", &numbers[i]);
    
    int trailing_zeroes[total_numbers];
    for (int i = 0; i < total_numbers; i++)
        trailing_zeroes[i] = count_factorial_trailing_zeroes(numbers[i]);

    printf("Trailing zeroes:\n");
    for (int i = 0; i < total_numbers; i++)
        printf("%d\n", trailing_zeroes[i]);
    return 0;
}

int count_factorial_trailing_zeroes(int number) {
    int zeroes = 0;
    for (int i = 1; number / pow(5, i); i++)
        zeroes += number / pow(5, i);
    return zeroes;
}