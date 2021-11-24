// Reverse a string using pointers
#include <stdio.h>
#include <stdlib.h>

char *reverse_str(char[]);

int main()
{
    char str[] = "!gnirts a si sihT";
    printf("String : %s\n", str);

    char *rev = reverse_str(str);
    printf("Result : %s\n", rev);
    free(rev);
    return 0;
}

char *reverse_str(char str[])
{
    int str_len;
    for (str_len = 0; str[str_len]; str_len++);

    char *rev_str  = (char *) calloc(str_len, sizeof(char));

    if (rev_str == NULL) {
        printf("Memory not allocated!\n");
        exit(0);
    }

    for (int i = 0; i < str_len; i++)
        rev_str[i] = str[str_len - i - 1];

    rev_str[str_len] = '\0';
    return rev_str;
}