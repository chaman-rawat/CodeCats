// Search Insert Position (Binary Search)
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

    int start = 0,
        middle,
        end = size - 1,
        is_found = 0;

    while (start <= end)
    {
        middle = (start + end) / 2;
        if (arr[middle] == target)
        {
            is_found++;
            break;
        }
        else if (arr[middle] < target)
            start = middle + 1;
        else
            end = middle - 1;
    }

    if (is_found)
        printf("Output: %d\n", middle);
    else
        printf("Output: %d\n", middle + ((arr[middle > target]) ? 1 : - 1));
    return 0;
}