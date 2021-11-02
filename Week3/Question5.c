// Write a program in C to find the sum of all elements of the array.
#include <stdio.h>

void print_sum(int[], int);

int main(int argc, char const *argv[])
{
    int size;
    scanf("%d", &size);
    int arr[size];
    for (int i = 0; i < size; i++) scanf("%d", &arr[i]);

    print_sum(arr, size);
    return 0;
}

void print_sum(int arr[], int size)
{
    int sum = 0, sum_even = 0, sum_odd = 0, sum_even_pos = 0, sum_odd_pos = 0;

    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
        (arr[i] & 1) ? sum_odd += arr[i] : sum_even += arr[i];
        (i & 1) ? sum_odd_pos += arr[i] : sum_even_pos += arr[i];
    }

    printf("%d %d %d %d %d\n", sum, sum_even, sum_odd, sum_even_pos, sum_odd_pos);
}