/*Q9. Write a C program to input marks of five subjects Physics, Chemistry, Biology, Mathematics and Computer. Calculate percentage and grade according to
following:
Percentage >= 90% : Grade A
Percentage >= 80% : Grade B
Percentage >= 70% : Grade C
Percentage >= 60% : Grade D
Percentage >= 40% : Grade E
Percentage < 40% : Grade F */

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int marks[5];

    
    // Take marks of subjects
    printf("Enter Physics marks: ");
    scanf("%d", &marks[0]);

    printf("Enter Chemistry marks: ");
    scanf("%d", &marks[1]);

    printf("Enter Biology marks: ");
    scanf("%d", &marks[2]);

    printf("Enter MAthematics marks: ");
    scanf("%d", &marks[3]);

    printf("Enter Computer marks: ");
    scanf("%d", &marks[4]);

    // calculate average
    float average_marks = 0;
    for (int i = 0; i < 5; i++)
        average_marks += marks[i];
    average_marks /= 5;

    
    if (average_marks >= 90)
        printf("Grade A\n");
    else if (average_marks >= 80)
        printf("Grade B\n");
    else if (average_marks >= 70)
        printf("Grade C\n");
    else if (average_marks >= 60)
        printf("Grade D\n");
    else if (average_marks >= 40)
        printf("Grade E\n");
    else
        printf("Grade F\n");
        
    return 0;
}