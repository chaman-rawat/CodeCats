// Q4. Write a C program to check whether a year is a leap year or not.

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int year;

    printf("Enter a year: ");
    scanf("%d", &year);

    if (year%400 == 0 || (year%100 != 0 && year%4==0))
        printf("%d is a leap year\n", year);
    else
        printf("%d is a not leap year\n", year);

    return 0;
}