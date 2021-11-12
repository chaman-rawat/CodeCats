// SET 0,1,2 in an array
#include <stdio.h>

int main()
{
    int size;
    printf("Size of Array: ");
    scanf("%d", &size);

    int arr[size],
        count[3] = {0};
    printf("Array: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
        count[arr[i]]++;
    }

    int result[size];
    for (int i = 0; i < size; i++)
    {
        if (count[0])
        {
            result[i] = 0;
            count[0]--;
        }
        else if (count[1])
        {
            result[i] = 1;
            count[1]--;
        }
        else
            result[i] = 2;
    }

    printf("Output: ");
    for (int i = 0; i < size; i++)
        printf("%d ", result[i]);
    return 0;
}