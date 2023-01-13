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

int coup_automatique ( int x, int y, t_tuile laby[x][y], t_move* mouvement, int depart[2], int arrivee[2], t_position2 joueur, int tableauTresor[24][2] )
{
	t_tuile laby_intermédiaire[x][y] ;
	for ( int i=0; i<x; i++ )
	{
		for ( int j=0; j<y; j++ )
		{
			laby_intermédiaire[x][y] = laby[x][y] ;
		}
	}
	
	int cheminPossible ;
	
	for ( int a=0; a<4; a++ )
	{
		if ( (a == 0) || (a == 1) )
		{
			for ( int ligne=1; ligne<x; ligne = ligne+2 )
			{
				for ( int clock=0; clock<4; clock++ )
				{
					if ( a == 0 )
					{
						if ( clock == 0 )
						{
							laby_intermédiaire[0][ligne].North = mouvement->tileN ;
							laby_intermédiaire[0][ligne].East = mouvement->tileE ;
							laby_intermédiaire[0][ligne].South = mouvement->tileS ;
							laby_intermédiaire[0][ligne].West = mouvement->tileW ;
							laby_intermédiaire[0][ligne].Item = mouvement->tileItem ;
						}
						if ( clock == 1 )
						{
							laby_intermédiaire[0][ligne].North = mouvement->tileW ;
							laby_intermédiaire[0][ligne].East = mouvement->tileN ;
							laby_intermédiaire[0][ligne].South = mouvement->tileE ;
							laby_intermédiaire[0][ligne].West = mouvement->tileS ;
							laby_intermédiaire[0][ligne].Item = mouvement->tileItem ;
						}
						if ( clock == 2 )
						{
							laby_intermédiaire[0][ligne].North = mouvement->tileS ;
							laby_intermédiaire[0][ligne].East = mouvement->tileW ;
							laby_intermédiaire[0][ligne].South = mouvement->tileN ;
							laby_intermédiaire[0][ligne].West = mouvement->tileE ;
							laby_intermédiaire[0][ligne].Item = mouvement->tileItem ;
						}
						if ( clock == 3 )
						{
							laby_intermédiaire[0][ligne].North = mouvement->tileE ;
							laby_intermédiaire[0][ligne].East = mouvement->tileS ;
							laby_intermédiaire[0][ligne].South = mouvement->tileW ;
							laby_intermédiaire[0][ligne].West = mouvement->tileN ;
							laby_intermédiaire[0][ligne].Item = mouvement->tileItem ;
						}
						
						cheminPossible = expension ( x, y, laby, depart[2], arrivee[2], &mouvement, joueur, tableauTresor ) ;
						if ( cheminPossible = 1111 )
						{
								mouvement->insert = a ;
								mouvement->number = ligne ;
								mouvement->rotation = clock ;
								mouvement->x = arrivee[0] ;
								mouvement->y = arrivee[1] ;
								sendMove(&mouvement) ;
								return 0 ;
						}
						if ( cheminPossible = 9999 )
						{
							// move legal
						}
						
						
					}
					
					if ( a == 1 )
					{
						if ( clock == 0 )
						{
							laby_intermédiaire[x-1][ligne].North = mouvement->tileN ;
							laby_intermédiaire[x-1][ligne].East = mouvement->tileE ;
							laby_intermédiaire[x-1][ligne].South = mouvement->tileS ;
							laby_intermédiaire[x-1][ligne].West = mouvement->tileW ;
							laby_intermédiaire[x-1][ligne].Item = mouvement->tileItem ;
						}
						if ( clock == 1 )
						{
							laby_intermédiaire[x-1][ligne].North = mouvement->tileW ;
							laby_intermédiaire[x-1][ligne].East = mouvement->tileN ;
							laby_intermédiaire[x-1][ligne].South = mouvement->tileE ;
							laby_intermédiaire[x-1][ligne].West = mouvement->tileS ;
							laby_intermédiaire[x-1][ligne].Item = mouvement->tileItem ;
						}
						if ( clock == 2 )
						{
							laby_intermédiaire[x-1][ligne].North = mouvement->tileS ;
							laby_intermédiaire[x-1][ligne].East = mouvement->tileW ;
							laby_intermédiaire[x-1][ligne].South = mouvement->tileN ;
							laby_intermédiaire[x-1][ligne].West = mouvement->tileE ;
							laby_intermédiaire[x-1][ligne].Item = mouvement->tileItem ;
						}
						if ( clock == 3 )
						{
							laby_intermédiaire[x-1][ligne].North = mouvement->tileE ;
							laby_intermédiaire[x-1][ligne].East = mouvement->tileS ;
							laby_intermédiaire[x-1][ligne].South = mouvement->tileW ;
							laby_intermédiaire[x-1][ligne].West = mouvement->tileN ;
							laby_intermédiaire[x-1][ligne].Item = mouvement->tileItem ;
						}
						
						cheminPossible = expension ( x, y, laby, depart[2], arrivee[2], &mouvement, joueur, tableauTresor ) ;
						if ( cheminPossible = 1111 )
						{
								mouvement->insert = a ;
								mouvement->number = ligne ;
								mouvement->rotation = clock ;
								mouvement->x = arrivee[0] ;
								mouvement->y = arrivee[1] ;
								sendMove(&mouvement) ;
								return 0 ;
						}
						if ( cheminPossible = 9999 )
						{
							// move legal
						}
					}
				}
			}
		}
		
		
		if ( (a == 2) || (a == 3) )
		{
			for ( int colonne=1; colonne<y; colonne = colonne+2 )
			{
				for ( int clock=0; clock<4; clock++ )
				{
					if ( a == 2 )
					{
						if ( clock == 0 )
						{
							laby_intermédiaire[colonne][0].North = mouvement->tileN ;
							laby_intermédiaire[colonne][0].East = mouvement->tileE ;
							laby_intermédiaire[colonne][0].South = mouvement->tileS ;
							laby_intermédiaire[colonne][0].West = mouvement->tileW ;
							laby_intermédiaire[colonne][0].Item = mouvement->tileItem ;
						}
						if ( clock == 1 )
						{
							laby_intermédiaire[colonne][0].North = mouvement->tileW ;
							laby_intermédiaire[colonne][0].East = mouvement->tileN ;
							laby_intermédiaire[colonne][0].South = mouvement->tileE ;
							laby_intermédiaire[colonne][0].West = mouvement->tileS ;
							laby_intermédiaire[colonne][0].Item = mouvement->tileItem ;
						}
						if ( clock == 2 )
						{
							laby_intermédiaire[colonne][0].North = mouvement->tileS ;
							laby_intermédiaire[colonne][0].East = mouvement->tileW ;
							laby_intermédiaire[colonne][0].South = mouvement->tileN ;
							laby_intermédiaire[colonne][0].West = mouvement->tileE ;
							laby_intermédiaire[colonne][0].Item = mouvement->tileItem ;
						}
						if ( clock == 3 )
						{
							laby_intermédiaire[colonne][0].North = mouvement->tileE ;
							laby_intermédiaire[colonne][0].East = mouvement->tileS ;
							laby_intermédiaire[colonne][0].South = mouvement->tileW ;
							laby_intermédiaire[colonne][0].West = mouvement->tileN ;
							laby_intermédiaire[colonne][0].Item = mouvement->tileItem ;
						}
						
						cheminPossible = expension ( x, y, laby, depart[2], arrivee[2], &mouvement, joueur, tableauTresor ) ;
						if ( cheminPossible = 1111 )
						{
								mouvement->insert = a ;
								mouvement->number = colonne ;
								mouvement->rotation = clock ;
								mouvement->x = arrivee[0] ;
								mouvement->y = arrivee[1] ;
								sendMove(&mouvement) ;
								return 0 ;								
						}
						if ( cheminPossible = 9999 )
						{
							// move legal
						}
						
						
					}
					
					if ( a == 1 )
					{
						if ( clock == 0 )
						{
							laby_intermédiaire[colonne][y-1].North = mouvement->tileN ;
							laby_intermédiaire[colonne][y-1].East = mouvement->tileE ;
							laby_intermédiaire[colonne][y-1].South = mouvement->tileS ;
							laby_intermédiaire[colonne][y-1].West = mouvement->tileW ;
							laby_intermédiaire[colonne][y-1].Item = mouvement->tileItem ;
						}
						if ( clock == 1 )
						{
							laby_intermédiaire[colonne][y-1].North = mouvement->tileW ;
							laby_intermédiaire[colonne][y-1].East = mouvement->tileN ;
							laby_intermédiaire[colonne][y-1].South = mouvement->tileE ;
							laby_intermédiaire[colonne][y-1].West = mouvement->tileS ;
							laby_intermédiaire[colonne][y-1].Item = mouvement->tileItem ;
						}
						if ( clock == 2 )
						{
							laby_intermédiaire[colonne][y-1].North = mouvement->tileS ;
							laby_intermédiaire[colonne][y-1].East = mouvement->tileW ;
							laby_intermédiaire[colonne][y-1].South = mouvement->tileN ;
							laby_intermédiaire[colonne][y-1].West = mouvement->tileE ;
							laby_intermédiaire[colonne][y-1].Item = mouvement->tileItem ;
						}
						if ( clock == 3 )
						{
							laby_intermédiaire[colonne][y-1].North = mouvement->tileE ;
							laby_intermédiaire[colonne][y-1].East = mouvement->tileS ;
							laby_intermédiaire[colonne][y-1].South = mouvement->tileW ;
							laby_intermédiaire[colonne][y-1].West = mouvement->tileN ;
							laby_intermédiaire[colonne][y-1].Item = mouvement->tileItem ;
						}
						
						cheminPossible = expension ( x, y, laby, depart[2], arrivee[2], &mouvement, joueur, tableauTresor ) ;
						if ( cheminPossible = 1111 )
						{
								mouvement->insert = a ;
								mouvement->number = colonne ;
								mouvement->rotation = clock ;
								mouvement->x = arrivee[0] ;
								mouvement->y = arrivee[1] ;
								sendMove(&mouvement) ;
								return 0 ;								
						}
						if ( cheminPossible = 9999 )
						{
							// move legal
						}
					}
				}
			}
		}
	}
}


