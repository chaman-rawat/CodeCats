// Count Frequency of every element of the array
#include <stdio.h>

const int hash_size = 1e+7;
int hash[hash_size];

int main()
{
    int size;
    printf("Size of Array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Array: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
        hash[arr[i]]++;
    }

    printf("Output: \n");
    for (int i = 0; i < hash_size; i++)
    {
        if (hash[i])
            printf("%d - %d times\n", i, hash[i]);
    }
    return 0;
}