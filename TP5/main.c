#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct
{
    int etats[4];
} ens_etats;
ens_etats trans[4][3] = {
    {{-1, 1, 2, -1}, {-1, -1, -1, -1}, {-1, -1, -1, -1}},
    {{-1, -1, -1, -1}, {0, 1, 3, -1}, {-1, -1, -1, -1}},
    {{-1, -1, -1, -1}, {-1, -1, -1, -1}, {1, 3, -1, -1}},
    {{-1, -1, -1, -1}, {-1, -1, -1, -1}, {2, -1, -1, -1}},
};
char ch[50];
bool F[7] = {false, true, true, true, false, true, true};

bool is_final(int s)
{
    if (F[s] == true)
        return true;
    if (F[s] == false)
        return false;
}

bool reconnaitRec(char ch[50], int q, int k)
{
    bool bl, arret;
    char c;
    int st;
    if (k >= strlen(ch))
    {
        bl = is_final(q);
    }
    else
    {
        c = ch[k];
        st = 0;
        arret = false;
        while (st < 4 && !arret)
        {
            if (trans[q][c - 'a'].etats[st] != -1)
            {
                st = trans[q][c - 'a'].etats[st];
                if (reconnaitRec(ch, k + 1, st))
                {
                    bl = true;
                    arret = true;
                }
            }
            st++;
        }
        if (!arret)
            bl = false;
    }
    return bl;
}

int main()
{
    char choice;
    do
    {
        printf("Enter a word ");
        scanf("%s", &ch);
        if (reconnaitRec(ch, 0, 0))
        {
            printf("Le mot qppartient :D\n");
        }
        else
        {
            printf("le mot n'appartient pas :(\n");
        }
        printf("Do you want to test another word? [y/n] ");
        scanf("%s", &choice);
    } while (choice != 'n');
    return 0;
}