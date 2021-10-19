// Q5. Write a C program to input any character and check whether it is alphabet, digit or special character.

#include <stdio.h>

int main(int argc, char const *argv[])
{
    char character;

    printf("Enter a character: ");
    scanf("%c", &character);

    if ((character<=90 && character>=65) ||  (character<=122 && character>=97))
        printf("%c is a character\n", character);
    else if (character<=57 && character>=48)
        printf("%c is a digit\n", character);
    else
        printf("%c is a special character\n", character);
    return 0;
}