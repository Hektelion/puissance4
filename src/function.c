#include <stdio.h>

#include "../header/constant.h"
#include "../header/function.h"

//initialise la grille du jeu a 0
void initGrid(int g[6][7])
{
    for(int i=0 ; i<nbl ; i++)
    {
        for(int j=0 ; j<nbc ; j++)
        {
            g[i][j] = BLANK;
        }
    }
}

//affiche la grille à l'écran d'apres le cahier des charges
void printGrid(int g[6][7])
{
    for(int i=0 ; i<nbl ; i++)
    {
        for(int j=0 ; j<nbc ; j++)
        {
            switch(g[i][j])
            {
                case BLANK:
                    putchar('.');
                break;
                case YELLOW:
                    putchar('O');
                break;
                case RED:
                    putchar('X');
                break;
            }
            putchar(' ');
        }
        putchar('\n');
    }
    putchar('\n');
    printf("-------------  ");
    putchar('\n');
    printf("1 2 3 4 5 6 7  ");
    putchar('\n');
}

//demande a l'utilisateur de choisir un coup
int chooseMove(int player)
{
    int move;

    //Ajouter un message pour le joueur rouge ou jaune
    printf("\nChoisissez un coup : ");
    scanf("%d", &move);

    return move;
}

//verifie si le coup est valide
int isValidMove(int g[6][7], int col)
{
    //Cas coup entre 1 et 7
    if( col > 7 || col < 1 )
    {
        printf("\nERREUR : colone invalide\n");
        return 0;
    }

    //Cas colonne pleine
    if( g[0][col] != 0 )
    {
        printf("\nERREUR : colone pleine\n");
        return 0;
    }

    return 1;
}

//place le jeton dans la grille
void putToken(int g[6][7], int col, int player)
{
    printf("putToken non implémentée\n");
}

//verifie si il existe un alignement
int verifAlign(int g[6][7], int player)
{
    printf("verifAlign non implémentée\n");

    return 0;
}

//revoi 1 si le coup est dans la grille sinon 0
int isInGrid()
{
    printf("isInGrid non implémentée\n");

    return 0;
}

//affiche un message de resultat
void printRes(int player)
{
    switch(player)
    {
        case 1:
            printf("\nLe joueur JAUNE a gagner\n");
        break;

        case 0:
            printf("\nLe joueur ROUGE a gagner\n");
        break;
        default:
            printf("\nERREUR : numero de joueur invalide\n");
    }
}

//joueur suivant
int nextPlayer(int player)
{
    return (player + 1) % 2;
}

char wantReplay()
{
    char choice;

    printf("Vous voulez rejouez ? (o/n)");

    scanf("%c", &choice);

    return choice;
}