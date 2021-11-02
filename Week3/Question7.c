// Find Largest, Second Largest, Smallest and Second Smallest Element in an Array
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int size;
    scanf("%d", &size);

    int arr[size];
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    int largest = arr[0],
        smallest = arr[0],
        sec_largest = arr[0],
        sec_smallest = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] > sec_largest)
        {
            if (arr[i] > largest)
            {
                sec_largest = largest;
                largest = arr[i];
            }
            else
                sec_largest = arr[i];
        }

        if (arr[i] < sec_smallest)
        {
            if (arr[i] < smallest)
            {
                sec_smallest = smallest;
                smallest = arr[i];
            }
            else
                sec_smallest = arr[i];
        }

        if (sec_largest == largest)
            sec_largest = arr[i];
        if (sec_smallest == smallest)
            sec_smallest = arr[i];
    }

    printf("The largest element is: %d\n", largest);
    printf("The smallest element is: %d\n", smallest);
    printf("The second largest is: %d\n", sec_largest);
    printf("The second smallest is: %d\n", sec_smallest);
    return 0;
}