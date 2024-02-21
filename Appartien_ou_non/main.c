#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 20
char M[N] = "", symb_cour;
int i, n, accepte, stop;
void A()
{
    if (symb_cour == 'b')
    {
        if (i < n)
        {
            symb_cour = M[i++];
            A(); // appel récursif de la fonction A
        }
        else
            accepte = 0;
    }
    else if (symb_cour == 'c')
    {
        if (i < n)
        {
            symb_cour = M[i++];
            A(); // appel récursif de la fonction A
        }
        else
            accepte = 0;
    }
    else if (symb_cour == 'd')
    {
        if (i == n)
            accepte = 1; // VRAI
        else
            accepte = 0; // FAUX
    }
    else
        accepte = 0;
} // Fin de la  fonction A
void S()
{ // Fonction S associée au non terminal S
    if (symb_cour == 'a')
    {
        symb_cour = M[i++];
        A(); // appel récursif de la fonction S
    }
    else
        accepte = 0; // FAUX
}
int main()
{
    do
    {
        printf("\n");
        printf("donner un mot pour le tester (/ pour terminer) : ");
        scanf("%s", &M);
        stop = strcmp(M, "/");
        if (stop != 0)
        {
            n = strlen(M);
            i = 0;
            symb_cour = M[i++];
            S();
            if (accepte)
                printf("le mot appartient au langage \n");
            else
                printf("le mot n appartient pas au langage \n");
        }
    } while (stop != 0);
    return 0;
}