// Reverse the input Array
#include <stdio.h>

void reverse_array(int[], int);

int main()
{
    int size;
    printf("Size of array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Array: ");
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    reverse_array(arr, size);
    return 0;
}

void reverse_array(int arr[], int size)
{
    int reverse_arr[size];
    for (int i = 0; i < size; i++)
        reverse_arr[i] = arr[size - i - 1];

    printf("Output: ");
    for (int i = 0; i < size; i++)
        printf("%d ", reverse_arr[i]);
}