#include <stdio.h>
#include <string.h>
int main(void)
{
    int n, i;
    char s[50];
    printf("enter a string ");
    fgets(s, sizeof(s), stdin);
    // print a string n times
    printf("how many times you want to print this string ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        printf("%s\n", s);
    // print prefixes of a string
    i = 0;
    while (i != strlen(s))
    {
        for (int j = 0; j <= i; j++)
            printf("%c", s[j]);
        printf("\n");
        i++;
    }
    // print a string vertically
    for (i = 0; i < strlen(s); i++)
    {
        printf("%c\n", s[i]);
    }

    for (i = 0; i < strlen(s); i++)
    {
        if (s[i] == ' ')
        {
            printf("\n");
        }
        printf("%c", s[i]);
    }
}