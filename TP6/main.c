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
    {{-1, -1, -1, -1}, {0, 1, -1, 3}, {-1, -1, -1, -1}},
    {{-1, -1, -1, -1}, {-1, -1, -1, -1}, {1, -1, -1, 3}},
    {{-1, -1, -1, -1}, {-1, -1, -1, -1}, {-1, -1, 2, -1}},
};
char ch[50];
bool F[7] = {false, true, true, true, false, true, true};
typedef struct
{
    int index;
    int etat;
} etat;

bool reconnaitIter(char ch[50])
{
    int len = strlen(ch);
    int sommet = -1;
    etat etat_tab[50];
    etat newEtat;
    newEtat.etat = 0;
    newEtat.index = 0;
    sommet++;
    etat_tab[sommet] = newEtat;
    while (sommet != -1)
    {
        etat current = etat_tab[sommet--];
        int currentEtat = current.etat;
        int currentIndex = current.index;
        if (currentIndex == len)
        {
            if (F[currentEtat])
            {
                return true;
            }
            continue;
        }
        char c = ch[currentIndex];
        int charIndex = c - 'a';
        for (int i = 0; i < 4; i++)
        {
            int next = trans[currentEtat][charIndex].etats[i];
            if (next != -1)
            {
                newEtat.etat = next;
                newEtat.index = currentIndex++;
                sommet++;
                etat_tab[sommet] = newEtat;
            }
        }
    }
    return false;
}

int main()
{
    char choice;
    do
    {
        printf("Enter a word ");
        scanf("%s", &ch);
        if (reconnaitIter(ch))
        {
            printf("Le mot appartient :D\n");
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