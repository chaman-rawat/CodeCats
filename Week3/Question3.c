// Create star triangle pattern (Isosceles) in C by using nested for loop
#include <stdio.h>

void print_pattern(int);

int main(int argc, char const *argv[])
{
    print_pattern(5);
    return 0;
}

void print_pattern(int num)
{
    for (int row = 1; row <= num; row++)
    {
        for (int space = 0; space < (num - row); space++)
            printf(" ");
        for (int star = 0; star < (2 * row - 1); star++)
            printf("*");
        printf("\n");
    }
}