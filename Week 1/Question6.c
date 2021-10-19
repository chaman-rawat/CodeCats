// Q6. Write a C program to input week number and print week day.

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int week_number;

    printf("Enter a week number: ");
    scanf("%d", &week_number);

    switch (week_number)
    {
    case 1:
        printf("It's Sunday\n");
        break;
    
    case 2:
        printf("It's Monday\n");
        break;
    
    case 3:
        printf("It's Tuesday\n");
        break;
    
    case 4:
        printf("It's Wednesday\n");
        break;
    
    case 5:
        printf("It's Thursday\n");
        break;
    
    case 6:
        printf("It's Friday\n");
        break;
    
    case 7:
        printf("It's Saturday\n");
        break;

    default:
        printf("Enter a valid week number!!\n");
        break;
    }

    return 0;
}