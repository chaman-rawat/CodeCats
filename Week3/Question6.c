// Count Total Number of occurrences of a given element in an array.
#include <stdio.h>

const int hash_size = 1e+7; // 1e+7 = 10000000
int hash[hash_size]; // No need to intialise with 0

int main(int argc, char const *argv[])
{
    int size;
    scanf("%d", &size);

    int arr[size], element;
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
        hash[arr[i]]++;
    }
    scanf("%d", &element);

    printf("%d\n", hash[element]);
    return 0;
}