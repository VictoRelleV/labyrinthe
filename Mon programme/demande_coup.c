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

int expension ( int x, int y, t_tuile laby[x][y], int depart[2], int arrivee[2], t_move* mouvement, t_position2* joueur, int tableauTresor[24][2] )
{
	depart[0] = joueur->joueur1.positionx ;
	depart[1] = joueur->joueur1.positiony ;
	
	arrivee[0] = tableauTresor[mouvement->nextItem-1][0] ;
	arrivee[1] = tableauTresor[mouvement->nextItem-1][1] ;
	
	int r = 1 ;
	int parcours = 0 ;
	
	for ( int i=0; i<x; i++ )
	{
		for ( int j=0; j<y; j++ )
		{
			laby[i][j].distance = 0 ;
		}
	}
	
	laby[depart[0]][depart[1]].distance = r ;
	
	while ( laby[arrivee[0]][arrivee[1]].distance == 0 )
	{
		for ( int i=0; i<x; i++ )
		{
			for ( int j=0; j<y; j++ )
			{
				if ( (i == depart[0]) && (j == depart[1]) )
				{
					continue ;
				}
				if ( (laby[i-1][j].distance == r) && (laby[i][j].distance == 0) && (laby[i-1][j].East == 0) && (laby[i][j].West == 0) && (i>0) )
				{
					laby[i][j].distance = r+1 ;
					parcours ++ ;
				}
				if ( (laby[i][j-1].distance == r) && (laby[i][j].distance == 0) && (laby[i][j-1].South == 0) && (laby[i][j].North == 0) && (j>0) )
				{
					laby[i][j].distance = r+1 ;
					parcours ++ ;
				}
				if ( (laby[i][j+1].distance == r) && (laby[i][j].distance == 0) && (laby[i][j+1].North == 0) && (laby[i][j].South == 0) && (j<y-1) )
				{
					laby[i][j].distance = r+1 ;
					parcours ++ ;
				}
				if ( (laby[i+1][j].distance == r) && (laby[i][j].distance == 0) && (laby[i+1][j].West == 0) && (laby[i][j].East == 0) && (i<x-1) )
				{
					laby[i][j].distance = r+1 ;
					parcours ++ ;
				}
			}
		}
	
		if ( parcours == 0 )
		{
			return 9999 ; // pas de chemin possible
		}
		
		else 
		{
			parcours = 0 ;
			r = r+1 ;
		}	
	}
	
	return 1111 ; // il y a un chemin
}





