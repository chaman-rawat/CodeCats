// Create star triangle pattern in C by using nested for loop
#include <stdio.h>

void print_pattern(int);

int main(int argc, char const *argv[])
{
    print_pattern(5);
    return 0;
}

void print_pattern(int num) {
    for (int row = 0; row < num; row++) {
        for (int col = 0; col <= row; col++)
            printf("*");
        printf("\n");
    }
}