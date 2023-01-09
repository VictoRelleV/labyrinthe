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

void cherche_tresor ( int x, int y, t_tuile laby[x][y], int depart[2], int arrivee[2], t_move mouvement, t_position2 joueur, int tableauTresor[24][2] )
{
	depart[0] = joueur.joueur1.positionx ;
	depart[1] = joueur.joueur1.positiony ;
	
	arrivee[0] = tableauTresor[mouvement.nextItem-1][0] ;
	arrivee[1] = tableauTresor[mouvement.nextItem-1][1] ;
	
	int parcours = expension ( x, y, laby, depart, arrivee ) ;
	
	printf("%d\n", parcours) ;
}

void coup_automatique ( int x, int y, t_tuile laby[x][y], t_move* mouvement )
{
	t_tuile laby_intermédiaire[x][y] = laby[x][y] ;
	int depart[2], arrivee[2] ;
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
							laby_intermédiaire[0][ligne].North = mouvement->TileN ;
							laby_intermédiaire[0][ligne].East = mouvement->TileE ;
							laby_intermédiaire[0][ligne].South = mouvement->TileS ;
							laby_intermédiaire[0][ligne].West = mouvement->TileW ;
							laby_intermédiaire[0][ligne].Item = mouvement->TileItem ;
						}
						if ( clock == 1 )
						{
							laby_intermédiaire[0][ligne].North = mouvement->TileW ;
							laby_intermédiaire[0][ligne].East = mouvement->TileN ;
							laby_intermédiaire[0][ligne].South = mouvement->TileE ;
							laby_intermédiaire[0][ligne].West = mouvement->TileS ;
							laby_intermédiaire[0][ligne].Item = mouvement->TileItem ;
						}
						if ( clock == 2 )
						{
							laby_intermédiaire[0][ligne].North = mouvement->TileS ;
							laby_intermédiaire[0][ligne].East = mouvement->TileW ;
							laby_intermédiaire[0][ligne].South = mouvement->TileN ;
							laby_intermédiaire[0][ligne].West = mouvement->TileE ;
							laby_intermédiaire[0][ligne].Item = mouvement->TileItem ;
						}
						if ( clock == 3 )
						{
							laby_intermédiaire[0][ligne].North = mouvement->TileE ;
							laby_intermédiaire[0][ligne].East = mouvement->TileS ;
							laby_intermédiaire[0][ligne].South = mouvement->TileW ;
							laby_intermédiaire[0][ligne].West = mouvement->TileN ;
							laby_intermédiaire[0][ligne].Item = mouvement->TileItem ;
						}
						
						cheminPossible = expension ( x, y, laby_intermédiaire, depart, arrivee ) ;
						if ( cheminPossible = 1907 )
						{
								mouvement->insert = a ;
								mouvement->number = ligne ;
								mouvement->rotation = clock ;
								mouvement->x = arrivee[0] ;
								mouvement->y = arrivee[1] ;
								sendMove(&mouvement) ;
						}
						if ( cheminPossible = 1607 )
						{
							// move legal
						}
						
						
					}
					
					if ( a == 1 )
					{
						if ( clock == 0 )
						{
							laby_intermédiaire[x-1][ligne].North = mouvement->TileN ;
							laby_intermédiaire[x-1][ligne].East = mouvement->TileE ;
							laby_intermédiaire[x-1][ligne].South = mouvement->TileS ;
							laby_intermédiaire[x-1][ligne].West = mouvement->TileW ;
							laby_intermédiaire[x-1][ligne].Item = mouvement->TileItem ;
						}
						if ( clock == 1 )
						{
							laby_intermédiaire[x-1][ligne].North = mouvement->TileW ;
							laby_intermédiaire[x-1][ligne].East = mouvement->TileN ;
							laby_intermédiaire[x-1][ligne].South = mouvement->TileE ;
							laby_intermédiaire[x-1][ligne].West = mouvement->TileS ;
							laby_intermédiaire[x-1][ligne].Item = mouvement->TileItem ;
						}
						if ( clock == 2 )
						{
							laby_intermédiaire[x-1][ligne].North = mouvement->TileS ;
							laby_intermédiaire[x-1][ligne].East = mouvement->TileW ;
							laby_intermédiaire[x-1][ligne].South = mouvement->TileN ;
							laby_intermédiaire[x-1][ligne].West = mouvement->TileE ;
							laby_intermédiaire[x-1][ligne].Item = mouvement->TileItem ;
						}
						if ( clock == 3 )
						{
							laby_intermédiaire[x-1][ligne].North = mouvement->TileE ;
							laby_intermédiaire[x-1][ligne].East = mouvement->TileS ;
							laby_intermédiaire[x-1][ligne].South = mouvement->TileW ;
							laby_intermédiaire[x-1][ligne].West = mouvement->TileN ;
							laby_intermédiaire[x-1][ligne].Item = mouvement->TileItem ;
						}
						
						cheminPossible = expension ( x, y, laby_intermédiaire, depart, arrivee ) ;
						if ( cheminPossible = 1907 )
						{
								mouvement->insert = a ;
								mouvement->number = ligne ;
								mouvement->rotation = clock ;
								mouvement->x = arrivee[0] ;
								mouvement->y = arrivee[1] ;
								sendMove(&mouvement) ;
						}
						if ( cheminPossible = 1607 )
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
							laby_intermédiaire[colonne][0].North = mouvement.TileN ;
							laby_intermédiaire[colonne][0].East = mouvement.TileE ;
							laby_intermédiaire[colonne][0].South = mouvement.TileS ;
							laby_intermédiaire[colonne][0].West = mouvement.TileW ;
							laby_intermédiaire[colonne][0].Item = mouvement.TileItem ;
						}
						if ( clock == 1 )
						{
							laby_intermédiaire[colonne][0].North = mouvement.TileW ;
							laby_intermédiaire[colonne][0].East = mouvement.TileN ;
							laby_intermédiaire[colonne][0].South = mouvement.TileE ;
							laby_intermédiaire[colonne][0].West = mouvement.TileS ;
							laby_intermédiaire[colonne][0].Item = mouvement.TileItem ;
						}
						if ( clock == 2 )
						{
							laby_intermédiaire[colonne][0].North = mouvement.TileS ;
							laby_intermédiaire[colonne][0].East = mouvement.TileW ;
							laby_intermédiaire[colonne][0].South = mouvement.TileN ;
							laby_intermédiaire[colonne][0].West = mouvement.TileE ;
							laby_intermédiaire[colonne][0].Item = mouvement.TileItem ;
						}
						if ( clock == 3 )
						{
							laby_intermédiaire[colonne][0].North = mouvement.TileE ;
							laby_intermédiaire[colonne][0].East = mouvement.TileS ;
							laby_intermédiaire[colonne][0].South = mouvement.TileW ;
							laby_intermédiaire[colonne][0].West = mouvement.TileN ;
							laby_intermédiaire[colonne][0].Item = mouvement.TileItem ;
						}
						
						cheminPossible = expension ( x, y, laby_intermédiaire, depart, arrivee ) ;
						if ( cheminPossible = 1907 )
						{
								mouvement->insert = a ;
								mouvement->number = ligne ;
								mouvement->rotation = clock ;
								mouvement->x = arrivee[0] ;
								mouvement->y = arrivee[1] ;
								sendMove(&mouvement) ;
						}
						if ( cheminPossible = 1607 )
						{
							// move legal
						}
						
						
					}
					
					if ( a == 1 )
					{
						if ( clock == 0 )
						{
							laby_intermédiaire[colonne][y-1].North = mouvement.TileN ;
							laby_intermédiaire[colonne][y-1].East = mouvement.TileE ;
							laby_intermédiaire[colonne][y-1].South = mouvement.TileS ;
							laby_intermédiaire[colonne][y-1].West = mouvement.TileW ;
							laby_intermédiaire[colonne][y-1].Item = mouvement.TileItem ;
						}
						if ( clock == 1 )
						{
							laby_intermédiaire[colonne][y-1].North = mouvement.TileW ;
							laby_intermédiaire[colonne][y-1].East = mouvement.TileN ;
							laby_intermédiaire[colonne][y-1].South = mouvement.TileE ;
							laby_intermédiaire[colonne][y-1].West = mouvement.TileS ;
							laby_intermédiaire[colonne][y-1].Item = mouvement.TileItem ;
						}
						if ( clock == 2 )
						{
							laby_intermédiaire[colonne][y-1].North = mouvement.TileS ;
							laby_intermédiaire[colonne][y-1].East = mouvement.TileW ;
							laby_intermédiaire[colonne][y-1].South = mouvement.TileN ;
							laby_intermédiaire[colonne][y-1].West = mouvement.TileE ;
							laby_intermédiaire[colonne][y-1].Item = mouvement.TileItem ;
						}
						if ( clock == 3 )
						{
							laby_intermédiaire[colonne][y-1].North = mouvement.TileE ;
							laby_intermédiaire[colonne][y-1].East = mouvement.TileS ;
							laby_intermédiaire[colonne][y-1].South = mouvement.TileW ;
							laby_intermédiaire[colonne][y-1].West = mouvement.TileN ;
							laby_intermédiaire[colonne][y-1].Item = mouvement.TileItem ;
						}
						
						cheminPossible = expension ( x, y, laby_intermédiaire, depart, arrivee ) ;
						if ( cheminPossible = 1907 )
						{
								mouvement->insert = a ;
								mouvement->number = ligne ;
								mouvement->rotation = clock ;
								mouvement->x = arrivee[0] ;
								mouvement->y = arrivee[1] ;
								sendMove(&mouvement) ;
						}
						if ( cheminPossible = 1607 )
						{
							// move legal
						}
					}
				}
			}
		}
	}
}


