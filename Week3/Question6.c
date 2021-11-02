// Count Total Number of occurrences of a given element in an array.
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int size;
    scanf("%d", &size);

    int arr[size], element, occurrence = 0;
    for (int i = 0; i < size; i++) scanf("%d", &arr[i]);
    scanf("%d", &element);

    for (int i = 0; i < size; i++) if (arr[i] == element) occurrence++;

    printf("%d\n", occurrence);
    return 0;
}