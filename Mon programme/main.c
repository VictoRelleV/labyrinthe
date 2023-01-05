#include "clientAPI.h"
#include "labyrinthAPI.h"
#include "structure.h"
#include <stdio.h>
#include <stdlib.h>

int main ()
{

connectToServer( "172.105.76.204", 1234, "Vivi93300") ;

char labyrinthName[50] ;
t_labyrinth laby ;

int TileN, TileE, TileS, TileW, TileItem ;

waitForLabyrinth( "TRAINING DONTMOVE timeout=1000 display=debug", labyrinthName, &laby.sizeX, &laby.sizeY) ;

printf ("Le labyrinthe est de taille %d * %d \n", laby.sizeX, laby.sizeY ) ;

printf ("Le nom dy Labyrinthe est : %s \n", labyrinthName ) ;

int etat ; // si l'état est 0 alors je commence, si l'état est 1 alors l'adversaire commence
int* lab = malloc ( laby.sizeX*laby.sizeY*sizeof(int)*5 ) ;

etat = getLabyrinth(lab, &TileN, &TileE, &TileS, &TileW, &TileItem) ;
printf ("L'état est de : %d \n", etat ) ;
if ( etat == 0 ) printf ("Vous commencez la partie \n") ;
else printf ("L'adversaire commence \n") ;

t_move mouvement ;
t_position2 joueur ;

t_tuile tableau_tuile[laby.sizeX*laby.sizeY] ;

affiche_labyrinthe ( laby.sizeX, laby.sizeY, lab ) ;
remplir_tableau_tuile ( laby.sizeX, laby.sizeY, tableau_tuile, lab ) ;

if ( etat == 0 ) initialisation ( &laby, &joueur, mouvement, 1 ) ;
else initialisation ( &laby, &joueur, mouvement, 2 ) ;

while(1)
{
	if ( etat == 0 )
	{
		printLabyrinth() ;
		
		coup ( &mouvement ) ;
		sendMove(&mouvement) ;
		maj( &laby, &joueur, mouvement, 1 ) ;
		
		getMove(&mouvement) ;
		maj( &laby, &joueur, mouvement, 2 ) ;
	}
	else
	{
		getMove(&mouvement) ;
		maj( &laby, &joueur, mouvement, 2 ) ;
		
		printLabyrinth() ;
		
		coup ( &mouvement ) ;
		sendMove(&mouvement) ;
		maj( &laby, &joueur, mouvement, 1 ) ;
	}
}

closeConnection() ;

}



