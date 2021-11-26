// Use linear searching to search an element in an sorted array
#include <stdio.h>

int linear_search(int[], int *, int *);

int main()
{
    int arr[] = {2, 3, 6, 7, 9, 12, 14, 22, 24};
    int size = sizeof(arr) / sizeof(int);
    int ele;

    printf("Enter value to search: ");
    scanf("%d", &ele);

    printf(linear_search(arr, &size, &ele)
               ? "Element exist.\n"
               : "Element doesn't exist.\n");
    return 0;
}

int linear_search(int arr[], int *size, int *ele)
{
    for (int i = 0; i < *size; i++)
        if (arr[i] == *ele)
            return 1;
    return 0;
}