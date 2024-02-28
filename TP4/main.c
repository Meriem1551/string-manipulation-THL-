#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int trans[4][2] = {{-1, 1},
                   {2, 1},
                   {2, 3},
                   {-1, 1}};
char c[50];
bool F[4] = {false, true, true, true};
bool is_final(int s)
{
    if (F[s] == true)
        return true;
    if (F[s] == false)
        return false;
}
void test_det()
{
    int i = 0, s = 0, car;
    int b = 1;

    while (i < strlen(c) && b == true)
    {

        car = c[i] - '0';
        if (car != 0 && car != 1)
            b = 0;
        else
        {
            s = trans[s][car];
            if (s == -1)
                b = 0;
        }
        i++;
    }
    if (b && is_final(s))
    {
        printf("oui");
    }
    else
        printf("non");
}

int main()
{
    printf("Enter a word ");
    scanf("%s", &c);
    test_det();
    return 0;
}