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
        if (hash[i])
            printf("%d - %d times\n", i, hash[i]);

    // ----------
    // Addon Part
    // ----------
    int num;
    printf("\n\t(Check Existence of a number)\nEnter Number : ");
    scanf("%d", &num);

    // Linear Search method
    int is_exist = 0;
    for (int i = 0; i < size; i++)
        if (arr[i] == num)
            is_exist++;

    printf("Using Linear Search: Element ");
    printf((is_exist) ? "Exist\n" : "Not Exist\n");

    // Array Hashing mathod
    printf("Using Array Hashing: Element ");
    printf((hash[num]) ? "Exist\n" : "Not Exist\n");
    return 0;
}