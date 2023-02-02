#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "labyrinthAPI.h"
#include "demande_coup.h"

int insert ;
int numero_ligne_colonne ;
int rotation ;
int x, y ;

/*
La fonction "coup" demande à l'utilisateur de rentrer un coup manuellement.
*/
void coup ( t_move* mouvement )
{
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
}





