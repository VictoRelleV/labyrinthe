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
	
	
// void coup_auto ( )
