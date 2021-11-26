// Find the largest number in a dynamically allocated memory.
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;
    printf("Enter Array size: ");
    scanf("%d", &size);

    int *arr = (int *)calloc(size, sizeof(int));
    if (arr == NULL)
    {
        printf("Error! memory not allocated.\n");
        return 1;
    }

    printf("Enter elements: ");
    for (int i = 0; i < size; i++)
        scanf("%d", arr + i);

    int *largest = arr;
    for (int i = 1; i < size; i++)
        if (*(arr + i) > *largest)
            largest = arr + i;

    printf("Largest element : %d\n", *largest);
    return 0;
}