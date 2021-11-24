// Read and print data of student structure using pointer
#include <stdio.h>

struct student
{
    char name[50];
    int rollno;
    int percentage;
};


int main(int argc, char const *argv[])
{
    struct student s1;
    struct student *s_ptr;

    s_ptr = &s1;

    printf("Enter student details:\n");
    printf("Name: ");
    fgets(s_ptr->name, sizeof(s_ptr->name), stdin);
    printf("Roll no.: ");
    scanf("%d", &s_ptr->rollno);
    printf("Percentage: ");
    scanf("%d", &s_ptr->percentage);

    printf("\nStudent details:\n");
    printf("\tName: %s\tRoll no.: %d\n\tPercentage: %d\n", s_ptr->name, s_ptr->rollno, s_ptr->percentage);
    return 0;
}