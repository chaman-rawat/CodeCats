// Concatenate two strings using pointers.
#include <stdio.h>

int main()
{
    char str1[50] = "Hello, ";
    char str2[] = "World!";
    char *ptr1 = str1,
         *ptr2 = str2;

    while (*++ptr1);
    while (*ptr2)
        *ptr1++ = *ptr2++;

    printf("After concatenate: %s\n", str1);
    return 0;
}