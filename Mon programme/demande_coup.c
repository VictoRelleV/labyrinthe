#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "labyrinthAPI.h"
#include "demande_coup.h"

int insert ;
int numero_ligne_colonne ;
int rotation ;
int x, y ;

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

int expension ( int x, int y, t_tuile laby[x][y], int depart[2], int arrivee[2] )
{
	int r = 1 ;
	int parcours = 0 ;
		
	for ( int i=0; i<x; i++ )
	{
		for ( int j=0; j<y; j++ )
		{
			laby[i][j].Item = 0 ;
		}
	}
	
	laby[depart[0]][depart[1]].Item = r ;
	
	while ( laby[arrivee[0]][arrivee[1]].Item == 0 )
	{
		for ( int i=0; i<x; i++ )
		{
			for ( int j=0; j<y; j++ )
			{
				if ( (i == depart[0]) && (j == depart[1]) )
				{
					continue ;
				}
				if ( (laby[i-1][j].Item == r) && (laby[i][j].Item == 0) && (laby[i-1][j].South == 0) && (laby[i][j].North == 0))
				{
					laby[i][j].Item = r+1 ;
					parcours ++ ;
				}
				if ( (laby[i][j-1].Item == r) && (laby[i][j].Item == 0) && (laby[i][j-1].East == 0) && (laby[i][j].West == 0))
				{
					laby[i][j].Item = r+1 ;
					parcours ++ ;
				}
				if ( (laby[i][j+1].Item == r) && (laby[i][j].Item == 0) && (laby[i][j+1].West == 0) && (laby[i][j].East == 0))
				{
					laby[i][j].Item = r+1 ;
					parcours ++ ;
				}
				if ( (laby[i+1][j].Item == r) && (laby[i][j].Item == 0) && (laby[i+1][j].North == 0) && (laby[i][j].South == 0))
				{
					laby[i][j].Item = r+1 ;
					parcours ++ ;
				}
			}
		}
		
		if ( parcours == 0 )
		{
			printf("pas atteignable") ;
			return parcours ;
		}
		
		else 
		{
			parcours = 0 ;
			r = r+1 ;
		}
			
	}
	
	return parcours ;
}





