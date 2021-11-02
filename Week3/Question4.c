// Create star triangle pattern (X) in C by using nested for loop
#include <stdio.h>

void print_pattern(int);

int main(int argc, char const *argv[])
{
    print_pattern(5);
    return 0;
}

void print_pattern(int num)
{
    int starting_spaces, middle_spaces;

    for (int row = 1; row < (2 * num); row++)
    {
        starting_spaces = (row <= num) ? (row - 1) : ((2 * num) - row - 1);
        for (int space = 0; space < starting_spaces; space++) printf(" ");

        if (row != num) printf("*");

        middle_spaces = (row <= num) ? ((2 * num) - (2 * row + 1)) : (2 * (row - num) - 1);
        for (int space = 0; space < middle_spaces; space++) printf(" ");

        printf("*\n");
    }
}