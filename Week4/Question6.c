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
        mid,
        end = size - 1,
        is_found = 0;

    while (start <= end)
    {
        mid = (start + end) / 2;
        if (arr[mid] == target)
        {
            is_found++;
            break;
        }
        else if (arr[mid] < target)
            start = mid + 1;
        else
            end = mid - 1;
    }

    if (is_found)
        printf("Output: %d\n", mid);
    else
        printf("Output: %d\n", mid + ((arr[mid] > target) ? 0 :  1));
    return 0;
}