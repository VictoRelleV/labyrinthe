#include "clientAPI.h"
#include "labyrinthAPI.h"
#include "structure.h"
#include <stdio.h>
#include <stdlib.h>

int main ()
{

connectToServer( "172.105.76.204", 1234, "Vivi") ;

char labyrinthName[50] ;
int sizeX ;
int sizeY ;

int TileN, TileE, TileS, TileW, TileItem ;

waitForLabyrinth( "TRAINING DONTMOVE timeout=1000", labyrinthName, &sizeX, &sizeY) ;

printf ("Le labyrinthe est de taille %d * %d \n", sizeX, sizeY ) ;

printf ("Le nom dy Labyrinthe est : %s \n", labyrinthName ) ;

int etat ; // si l'état est 0 alors je commence, si l'état est 1 alors l'adversaire commence
int* lab = malloc ( sizeX*sizeY*sizeof(int)*5 ) ;

etat = getLabyrinth(lab, &TileN, &TileE, &TileS, &TileW, &TileItem) ;
printf ("L'état est de : %d \n", etat ) ;
if ( etat == 0 ) printf ("Vous commencez la partie \n") ;
else printf ("L'adversaire commence \n") ;

t_move* mouvement ;
int insert ;
int numero_ligne_colonne ;
int rotation ;
int x, y ;

/*
while(1)
{
	if ( etat == 0 )
	{
		printLabyrinth() ;
		printf ("Choisissez le type d'insertion ( 0 : INSERT_LINE_LEFT, 1 : INSERT_LINE_RIGHT, 2 : INSERT_COLUMN_TOP, 3 : INSERT_COLUMN_BOTTOM )\n" ) ;
		scanf ("%d", &insert ) ;
		mouvement->insert = insert ;
		printf ("Choisissez le numéro de colonne ou de ligne\n" ) ;
		scanf ("%d", &numero_ligne_colonne ) ;
		mouvement->number = numero_ligne_colonne ;
		printf ("Choisissez la rotation (from 0 to 3 clockwise quarters)\n" ) ;
		scanf ("%d", &rotation ) ;
		mouvement->rotation = rotation ;
		printf ("Choisissez les coordonnées de la case où vous voulez vous déplacer\n" ) ;
		scanf ("%d %d", &x, &y ) ;
		mouvement->x = x ;
		mouvement->y = y ;
		sendMove(mouvement) ;
		getMove(mouvement) ;
	}
	else
	{
		getMove(mouvement) ;
		printLabyrinth() ;
		printf ("Choisissez le type d'insertion ( 0 : INSERT_LINE_LEFT, 1 : INSERT_LINE_RIGHT, 2 : INSERT_COLUMN_TOP, 3 : INSERT_COLUMN_BOTTOM )\n" ) ;
		scanf ("%d", &insert ) ;
		mouvement->insert = insert ;
		printf ("Choisissez le numéro de colonne ou de ligne\n" ) ;
		scanf ("%d", &numero_ligne_colonne ) ;
		mouvement->number = numero_ligne_colonne ;
		printf ("Choisissez la rotation (from 0 to 3 clockwise quarters)\n" ) ;
		scanf ("%d", &rotation ) ;
		mouvement->rotation = rotation ;
		printf ("Choisissez les coordonnées de la case où vous voulez vous déplacer\n" ) ;
		scanf ("%d %d", &x, &y ) ;
		mouvement->x = x ;
		mouvement->y = y ;
		sendMove(mouvement) ;
	}
}
*/



//permet de visualiser le labyrinth
for (int i=0; i<sizeX*sizeY*5; i++)
{
	if ( i%5 == 0 )
	{
		printf ("\n") ;
	}
	printf ("%d", lab[i]) ;
}	
printf ("\n") ;

t_tuile tableau_tuile[sizeX*sizeY] ;
for (int j=0; j<sizeX*sizeY; j++)
{
	tableau_tuile[j].North = lab[0+5*j] ;
	tableau_tuile[j].East = lab[1+5*j] ;
	tableau_tuile[j].South = lab[2+5*j] ;
	tableau_tuile[j].West = lab[3+5*j] ;
	tableau_tuile[j].Item = lab[4+5*j] ;
}

closeConnection() ;

}



