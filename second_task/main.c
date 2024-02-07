#include <stdio.h>
#include <string.h>
int isValid(char s[], int size)
{
    int i = 0, j = 0;

    while (s[i] != '\0')
    {
        if (s[i] == '(')
            j++;
        else if (s[i] == ')')
            j--;
        i++;
    }

    return 1 ? j == 0 : 0;
}
int main(void)
{
    char s[50];
    printf("Enter a string ");
    fgets(s, sizeof(s), stdin);

    int is_valid = isValid(s, sizeof(s));
    printf("%d", is_valid);
    return 0;
}