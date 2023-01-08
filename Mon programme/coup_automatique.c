#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "labyrinthAPI.h"
#include "coup_automatique.h"
#include "demande_coup.h"

/*
La fonction "tableau_tresor" remplie tableauTresor avec les coordonnées de chaque trésor.
*/
void tableau_tresor ( int x, int y, t_tuile laby[x][y], int tableauTresor[24][2] )
{
	for ( int i=0; i<x; i++ )
	{
		for ( int j=0; j<y; j++ )
		{
			if ( laby[i][j].Item != 0 )
			{
				tableauTresor[laby[i][j].Item-1][0] = i ;
				tableauTresor[laby[i][j].Item-1][1] = j ;
			}
		}
	}
		
	for ( int k=0; k<24; k++ )
	{
		printf("%d%d ", tableauTresor[k][0], tableauTresor[k][1] ) ;
	}
	printf("\n") ;
}

void cherche_tresor ( int x, int y, t_tuile laby[x][y], int depart[2], int arrivee[2], t_move mouvement, t_position2* joueur, int tableauTresor[24][2] )
{
	depart[0] = joueur->joueur1.positionx ;
	depart[1] = joueur->joueur1.positiony ;
	
	arrivee[0] = tableauTresor[mouvement.nextItem-1][0] ;
	arrivee[1] = tableauTresor[mouvement.nextItem-1][1] ;
	
	int parcours = expension ( x, y, laby, depart, arrivee ) ;
	
	printf("%d\n", parcours) ;
}
	
	
/*
void coup_automatique ( int x, int y, t_tuile laby[x][y], t_move* mouvement )
{
	for ( int a=0; a<4; a++ )
	{
		if ( (a == 0) || (a == 1) )
		{
			for ( int ligne=0; ligne<x; ligne++ )
			{
				for ( int clock=0; clock<4; clock++ )
				{
					//expension
				}
			}
		}
		if ( (a == 2) || (a == 3) )
		{
			for ( int colonne=0; colonne<y; colonne++ )
			{
				for ( int clock=0; clock<4; clock++ )
				{
					//expension
				}
			}
		}
	}
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
*/

