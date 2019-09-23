#include <stdio.h>

#include "../header/constant.h"
#include "../header/function.h"

int main()
{
    //DECLARATION

    int grid[nbl][nbc];
    int player;
    char replay='o';
    int over=1;

    int move;

    //DEBUT

        while(replay == 'o' || replay == 'O')
        {
            //INITIALISATION

            initGrid(grid);
            player=0;
            printGrid(grid);

            //DEBUT DE PARTIE
            while(over)
            {
                //TANT QUE LE COUP EST INVALIDE
                do
                {
                    //LE JOUEUR CHOISIS UN COUP
                    move = chooseMove(player);
                }
                while( !isValidMove(grid, move) );

                //PLACE LE JETON DANS LA GRILLE
                putToken(grid, move, player);

                //VERFICATION ALIGNEMENT
                over = verifAlign(grid, player);

                //AFFICHAGE DE LA GRILLE
                printGrid(grid);

                //CHANGEMENT DE JOUEUR
                player = nextPlayer(player);
            }

            //AFFICHAGE DU RESULTAT
            printRes(player);

            //LE JOUEUR VEUX T'IL REJOUER ?
            replay = wantReplay();

        }

        //ARRET DU JEU
        printf("Jeu Terminé");

    return 0;
}