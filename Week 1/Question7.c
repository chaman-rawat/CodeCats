// Q7. Write a C program to count the total number of notes in a given amount.

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int amount;

    printf("Enter total amount: ");
    scanf("%d", &amount);

    int total_notes = 0,
    notes[10] = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};

    for (int i = 0; i < 10; i++) {
        total_notes += amount/notes[i];
        amount -= amount/notes[i] * notes[i];
    }

    printf("Total notes in %d amount is: %d\n", amount, total_notes);

    return 0;
}