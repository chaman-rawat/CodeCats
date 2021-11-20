// Swap the values of two numbers
#include <stdio.h>

void swap(int *,int *);

int main()
{
    int x = 10, y = 20;
    printf("Before swapping\n\t num1: %d, num2: %d\n", x, y);
    swap(&x, &y);
    printf("After swapping\n\t num1: %d, num2: %d\n", x, y);
    return 0;
}

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}