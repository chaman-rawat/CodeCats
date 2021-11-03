// Write a program in C to find the sum of all elements of the array.
#include <stdio.h>

int sum, sum_even, sum_odd, sum_even_pos, sum_odd_pos;

int main(int argc, char const *argv[])
{
    int size;
    scanf("%d", &size);
    int arr[size];
    for (int i = 0; i < size; i++) scanf("%d", &arr[i]);

    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
        (arr[i] & 1 ? sum_odd : sum_even) += arr[i];
        (i & 1 ? sum_odd_pos : sum_even_pos) += arr[i];
    }

    printf("%d %d %d %d %d\n", sum, sum_even, sum_odd, sum_even_pos, sum_odd_pos);
    return 0;
}