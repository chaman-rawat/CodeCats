// Two Sum (find indices of the two numbers such that they add up to target)
#include <stdio.h>

int main()
{
    int size;
    printf("Size of Array: ");
    scanf("%d", &size);

    int arr[size], target;
    printf("Array: ");
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    printf("Target: ");
    scanf("%d", &target);

    for (int i = 0; i < size; i++)
        for (int j = i + 1; j < size; j++)
            if (arr[i] + arr[j] == target)
            {
                printf("Output: [%d, %d]\n", i, j);
                return 0;
            }

    printf("No solution!\n");
    return 1;
}