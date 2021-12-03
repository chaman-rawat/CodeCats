// Goal Parser Interpretation
#include <stdio.h>
#include <string.h>

void goal_parser(char *);

int main()
{
    char command[50];
    printf("Command: ");
    scanf("%s", command);
    goal_parser(command);
    return 0;
}

void goal_parser(char *command)
{
    char result[50];

    for (int i = 0; command[i] != '\0'; i++)
    {
        if (command[i] == 'G')
        {
            strcat(result, "G");
        }
        else if (command[i + 1] == ')')
        {
            strcat(result, "o");
            i += 1;
        }
        else
        {
            strcat(result, "al");
            i += 3;
        }
    }

    printf("Output: %s\n", result);
}