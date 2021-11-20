// Calculate sum of the elements of an array using pointer
#include <stdio.h>

int main()
{
    int size;
    printf("Size of Array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Array: ");
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    int *ptr = arr,
        sum = 0;
    for (int i = 0; i < size; i++)
        sum += *(ptr + i);

    printf("Sum: %d\n", sum);
    return 0;
}