// Rotate the array by “k” steps in right direction
#include <stdio.h>

void rotate_array(int[], int, int);

int main()
{
    int size;
    printf("Size of Array: ");
    scanf("%d", &size);

    int arr[size], k;
    printf("Array: ");
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    printf("Enter steps: ");
    scanf("%d", &k);

    rotate_array(arr, size, k);
    return 0;
}

void rotate_array(int arr[], int size, int k)
{
    int rotated_arr[size], position;
    for (int i = 0; i < size; i++)
    {
        position = k % size + i;
        if (position >= size)
            position -= size;
        rotated_arr[position] = arr[i];
    }

    printf("\nRotated array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", rotated_arr[i]);
}