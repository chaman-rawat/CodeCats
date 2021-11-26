// Use binary searching to search an element in a sorted array
#include <stdio.h>

int binary_search(int[], int *, int *);

int main()
{
    int arr[] = {2, 3, 6, 7, 9, 12, 14, 22, 24};
    int size = sizeof(arr) / sizeof(int);
    int ele;

    printf("Enter search value: ");
    scanf("%d", &ele);

    printf(binary_search(arr, &size, &ele)
               ? "Element exist.\n"
               : "Element doesn't exist.\n");
    return 0;
}

int binary_search(int arr[], int *size, int *ele)
{
    int *begin = arr,
        *end = (arr + *size - 1),
        *middle;

    while (*begin <= *end)
    {
        middle = begin + (end - begin) / 2;
        if (*middle == *ele)
            return 1;
        else if (*middle <= *ele)
            begin = middle + 1;
        else
            end = middle - 1;
    }
    return 0;
}