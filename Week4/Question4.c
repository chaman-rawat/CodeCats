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

    // Two Pointer Algorithm
    int start = 0,
        end = size - 1,
        sum;

    while (start < end)
    {
        sum = arr[start] + arr[end];
        if (sum < target)
            start++;
        else if (sum > target)
            end--;
        else
        {
            printf("Output: [%d, %d]\n", start, end);
            return 0;
        }
    }

    printf("No solution!\n");
    return 1;
}