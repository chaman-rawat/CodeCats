// Use bubble sort to sort an array of integers using pointers
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int arr[] = {5, 2, 4, 6, 1, 3};
    const int len = sizeof(arr) / sizeof(int);

    printf("Unsorted Array:\n\t");
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);

    int *ele = arr,
        temp,
        is_sorted = 0;

    for (int i = 0; i < len; i++)
    {
        is_sorted = 1;
        for (int j = 0; j < len - i - 1; j++)
            if (*(ele + j) > *(ele + j + 1)) // compare current and next element
            {
                // Current element is greater swap these two
                temp = *(ele + j);
                *(ele + j) = *(ele + j + 1);
                *(ele + j + 1) = temp;

                is_sorted = 0; // set flag to false
            }

        if (is_sorted) // If all elements are sorted then end loop
            break;
    }

    printf("\nSorted Array:\n\t");
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    return 0;
}