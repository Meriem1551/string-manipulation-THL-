#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 20
#define NMots 200;
char M[N] = "";
int i, nm, NmMots = NMots;
void A(char M[])
{
    char M1[N] = "";
    int n, r;
    n = strlen(M);
    r = rand() % 2; // nombre aléatoire entre 0 et 1 inclus
    strcpy(M1, M);  // on recopie M dans M1
    switch (r)
    {
    case 0:          // application de la 1ère règle A  bA :
        M1[n] = 'b'; // on concatène M1 avec 'a'
        M1[n + 1] = '\0';
        A(M1); // appel de A
        break;
    case 1:
        if (i < nm)
        {                // application de la 2ième règle A  cA :
            M1[n] = 'c'; // on concatène M1 avec 'a'
            M1[n + 1] = '\0';
            A(M1); // appel de A
            break;
        }
    default:
        if (i < nm)
        {
            M1[n] = 'd'; // on concatène M1 avec 'd'
            M1[n + 1] = '\0';
            printf(" %s \n", M1); // affichage du mot formé
        }
        break;
    }
}
void S(char M[])
{ // Fonction S associée au non terminal S
    char M1[N] = "";
    int n;
    n = strlen(M);
    M1[n] = 'a'; // on concatène M1 avec 'a'
    M1[n + 1] = '\0';
    A(M1);
}

// definition of A

int main()
{
    do
    {
        printf(" nombre de mots a generer : ");
        scanf("%d", &nm);
    } while ((nm < 1) || (nm > NmMots));
    printf("mots du langage : \n");
    i = 0;
    while (i < nm)
    {
        strcpy(M, "");
        S(M);
        i++;
    }
    printf("\n");
    return 0;
}