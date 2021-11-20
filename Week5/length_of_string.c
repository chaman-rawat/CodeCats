// Find length of a string using pointer
#include <stdio.h>

int main()
{
    char str[] = "My length is twenty.";
    char *ptr = str;
    int len = 0;
    while (*(ptr + len++));
    printf("Length: %d\n", --len);
    return 0;
}