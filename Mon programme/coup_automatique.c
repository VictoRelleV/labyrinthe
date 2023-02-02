#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "labyrinthAPI.h"
#include "coup_automatique.h"
#include "demande_coup.h"

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
	/*	
	for ( int k=0; k<24; k++ )
	{
		printf("%d%d ", tableauTresor[k][0], tableauTresor[k][1] ) ;
	}
	printf("\n") ;
	*/
}

/*
La fonction "rotation_tuile" prend une tuile en argument et la tourne en fonction de rotation
*/
void rotation_tuile ( t_tuile tuile_sup, int rotation, t_move* mouvement )
{
	tuile_sup.North = mouvement->tileN ;
	tuile_sup.East = mouvement->tileE ;
	tuile_sup.South = mouvement->tileS ;
	tuile_sup.West = mouvement->tileW ;
	tuile_sup.Item = mouvement->tileItem ;
	
	printf("%d,%d,%d,%d,%d\n", tuile_sup.North, tuile_sup.East, tuile_sup.South, tuile_sup.West, tuile_sup.Item ) ;
	
	t_tuile tuile_intermediaire = tuile_sup ;
	
	if ( rotation == 0 )
	{ 
		tuile_sup.North = tuile_intermediaire.North ;
		tuile_sup.East = tuile_intermediaire.East ;
		tuile_sup.South = tuile_intermediaire.South ;
		tuile_sup.West = tuile_intermediaire.West ;
	}
	
	if ( rotation == 1 )
	{ 
		tuile_sup.North = tuile_intermediaire.West ;
		tuile_sup.East = tuile_intermediaire.North ;
		tuile_sup.South = tuile_intermediaire.East ;
		tuile_sup.West = tuile_intermediaire.South ;
	}
	
	if ( rotation == 2 )
	{ 
		tuile_sup.North = tuile_intermediaire.South ;
		tuile_sup.East = tuile_intermediaire.West ;
		tuile_sup.South = tuile_intermediaire.North ;
		tuile_sup.West = tuile_intermediaire.East ;
	}
	
	if ( rotation == 3 )
	{ 
		tuile_sup.North = tuile_intermediaire.East ;
		tuile_sup.East = tuile_intermediaire.South ;
		tuile_sup.South = tuile_intermediaire.West ;
		tuile_sup.West = tuile_intermediaire.North ;
	}
	
	printf("%d,%d,%d,%d,%d\n", tuile_sup.North, tuile_sup.East, tuile_sup.South, tuile_sup.West, tuile_sup.Item ) ;
}

/*
La fonction "inserer_tuile" insère une tuile dans le tableau de tuile
*/
void inserer_tuile ( int x, int y, t_tuile laby[x][y], t_move* mouvement, t_tuile tuile_sup, int insert, int num_ligne, int num_colonne )
{
	t_tuile nv_tuile ; 
	
	if ( insert == 0 ) // lignes de gauche
	{
		//On met la tuile de la dernière colonne de la ligne en tant que nv tuile sup
		nv_tuile = laby[x-1][num_ligne] ;
		
		//On décale les tuiles de la ligne de 1
		for ( int colonne = x-1; colonne>0; colonne-- )
		{
			laby[colonne][num_ligne] = laby[colonne-1][num_ligne] ;
		}
		
		//On écrase la tuile sup sur la première tuile de la ligne
		laby[0][num_ligne] = tuile_sup ;
		
		//On met à jour la tuile sup
		mouvement->tileN = nv_tuile.North ;
		mouvement->tileE = nv_tuile.East ;
		mouvement->tileS = nv_tuile.South ;
		mouvement->tileW = nv_tuile.West ;
		mouvement->tileItem = nv_tuile.Item ;
	}
	
	if ( insert == 1 ) // lignes de droite
	{
		//On met la tuile de la dernière colonne de la ligne en tant que nv tuile sup
		nv_tuile = laby[0][num_ligne] ;
		
		for ( int colonne=0; colonne<x-1; colonne++ )
		{
			laby[colonne][num_ligne] = laby[colonne+1][num_ligne] ;
		}
		
		laby[x-1][num_ligne] = tuile_sup ;
		
		mouvement->tileN = nv_tuile.North ;
		mouvement->tileE = nv_tuile.East ;
		mouvement->tileS = nv_tuile.South ;
		mouvement->tileW = nv_tuile.West ;
		mouvement->tileItem = nv_tuile.Item ;
	}
	
	if ( insert == 2 ) // colonnes du haut
	{
		nv_tuile = laby[num_colonne][y-1] ;
		
		for ( int ligne=y-1; ligne>0; ligne-- )
		{
			laby[num_colonne][ligne] = laby[num_colonne][ligne-1] ;
		}
		
		laby[num_colonne][0] = tuile_sup ;
	
		mouvement->tileN = nv_tuile.North ;
		mouvement->tileE = nv_tuile.East ;
		mouvement->tileS = nv_tuile.South ;
		mouvement->tileW = nv_tuile.West ;
		mouvement->tileItem = nv_tuile.Item ;
	}
	
	if ( insert == 3 ) // colonnes du bas
	{
		nv_tuile = laby[num_colonne][0] ;
		
		for ( int ligne=0; ligne<y-1; ligne++ )
		{
			laby[num_colonne][ligne] = laby[num_colonne][ligne+1] ;
		}
		
		laby[num_colonne][y-1] = tuile_sup ;
	
		mouvement->tileN = nv_tuile.North ;
		mouvement->tileE = nv_tuile.East ;
		mouvement->tileS = nv_tuile.South ;
		mouvement->tileW = nv_tuile.West ;
		mouvement->tileItem = nv_tuile.Item ;
	}
}

/*
La fonction "maj_laby_intermédiaire" remplie laby_intermédiaire comme laby.
*/
void maj_laby_intermédiaire ( int x, int y, t_tuile laby_intermédiaire[x][y], t_tuile laby[x][y] )
{	
	for ( int i=0; i<x; i++ )
	{
		for ( int j=0; j<y; j++ )
		{
			laby_intermédiaire[x][y] = laby[x][y] ;
		}
	}
}

/*
La fonction "coup_automatique" essaie toutes les possibilitées possibles puis joue un coup si il y a possibilitée de trouver le procahin trésor, sinon demande un coup.
Pour toutes les possibilitées, on insère la tuile suplémentaire puis on test si il y a un chemin possible.
*/
int coup_automatique ( int x, int y, t_tuile laby[x][y], t_move* mouvement, int depart[2], int arrivee[2], t_position2* joueur, int tableauTresor[24][2], t_tuile tuile_sup )
{	
	t_tuile laby_intermédiaire[x][y] ;
	
	int cheminPossible = 0 ;
	
	for ( int insert=0; insert<4; insert++ )
	{
		if ( (insert == 0) || (insert == 1) )
		{
			for ( int ligne=1; ligne<y; ligne = ligne+2 )
			{
				for ( int clock=0; clock<4; clock++ )
				{
					maj_laby_intermédiaire ( x, y, laby_intermédiaire, laby ) ;
						
					if ( insert == 0 )
					{
						if ( clock == 0 )
						{
							printf("1\n") ;
							rotation_tuile ( tuile_sup, 0, mouvement ) ;
							printf("2\n") ;
							inserer_tuile ( x, y, laby_intermédiaire, mouvement, tuile_sup, insert, ligne, 1 ) ;
							printf("3\n") ;
						}
						if ( clock == 1 )
						{
							rotation_tuile ( tuile_sup, 1, mouvement ) ;
							inserer_tuile ( x, y, laby_intermédiaire, mouvement, tuile_sup, insert, ligne, 1 ) ;
						}
						if ( clock == 2 )
						{
							rotation_tuile ( tuile_sup, 2, mouvement ) ;
							inserer_tuile ( x, y, laby_intermédiaire, mouvement, tuile_sup, insert, ligne, 1 ) ;
						}
						if ( clock == 3 )
						{
							rotation_tuile ( tuile_sup, 3, mouvement ) ;
							inserer_tuile ( x, y, laby_intermédiaire, mouvement, tuile_sup, insert, ligne, 1 ) ;
						}
						printf("4\n") ;
						cheminPossible = expension ( x, y, laby_intermédiaire, depart, arrivee, mouvement, joueur, tableauTresor ) ;
						printf("5\n") ;
						if ( cheminPossible == 1111 )
						{
								mouvement->insert = insert ;
								mouvement->number = ligne ;
								mouvement->rotation = clock ;
								mouvement->x = arrivee[0] ;
								mouvement->y = arrivee[1] ;
								printf("Votre coup est [%d,%d,%d,%d,%d]", insert, ligne, clock, arrivee[0], arrivee[1] ) ;
								//sendMove(&mouvement) ;
								return 0 ;
						}											
					}
					
					if ( insert == 1 )
					{
						if ( clock == 0 )
						{
							rotation_tuile ( tuile_sup, 0, mouvement ) ;
							inserer_tuile ( x, y, laby_intermédiaire, mouvement, tuile_sup, insert, ligne, 1 ) ;
						}
						if ( clock == 1 )
						{
							rotation_tuile ( tuile_sup, 1, mouvement ) ;
							inserer_tuile ( x, y, laby_intermédiaire, mouvement, tuile_sup, insert, ligne, 1 ) ;
						}
						if ( clock == 2 )
						{
							rotation_tuile ( tuile_sup, 2, mouvement ) ;
							inserer_tuile ( x, y, laby_intermédiaire, mouvement, tuile_sup, insert, ligne, 1 ) ;
						}
						if ( clock == 3 )
						{
							rotation_tuile ( tuile_sup, 3, mouvement ) ;
							inserer_tuile ( x, y, laby_intermédiaire, mouvement, tuile_sup, insert, ligne, 1 ) ;
						}
						
						cheminPossible = expension ( x, y, laby_intermédiaire, depart, arrivee, mouvement, joueur, tableauTresor ) ;
						if ( cheminPossible == 1111 )
						{
								mouvement->insert = insert ;
								mouvement->number = ligne ;
								mouvement->rotation = clock ;
								mouvement->x = arrivee[0] ;
								mouvement->y = arrivee[1] ;
								printf("Votre coup est [%d,%d,%d,%d,%d]", insert, ligne, clock, arrivee[0], arrivee[1] ) ;
								//sendMove(&mouvement) ;
								return 0 ;
						}
					}
				}
			}
		}
		
		
		if ( (insert == 2) || (insert == 3) )
		{
			for ( int colonne=1; colonne<x; colonne = colonne+2 )
			{
				for ( int clock=0; clock<4; clock++ )
				{
					maj_laby_intermédiaire ( x, y, laby_intermédiaire, laby ) ;
					
					if ( insert == 2 )
					{
						if ( clock == 0 )
						{
							rotation_tuile ( tuile_sup, 0, mouvement ) ;
							inserer_tuile ( x, y, laby_intermédiaire, mouvement, tuile_sup, insert, 1, colonne ) ;
						}
						if ( clock == 1 )
						{
							rotation_tuile ( tuile_sup, 1, mouvement ) ;
							inserer_tuile ( x, y, laby_intermédiaire, mouvement, tuile_sup, insert, 1, colonne ) ;
						}
						if ( clock == 2 )
						{
							rotation_tuile ( tuile_sup, 2, mouvement ) ;
							inserer_tuile ( x, y, laby_intermédiaire, mouvement, tuile_sup, insert, 1, colonne ) ;
						}
						if ( clock == 3 )
						{
							rotation_tuile ( tuile_sup, 3, mouvement ) ;
							inserer_tuile ( x, y, laby_intermédiaire, mouvement, tuile_sup, insert, 1, colonne ) ;
						}
						
						cheminPossible = expension ( x, y, laby, depart, arrivee, mouvement, joueur, tableauTresor ) ;
						if ( cheminPossible == 1111 )
						{
								mouvement->insert = insert ;
								mouvement->number = colonne ;
								mouvement->rotation = clock ;
								mouvement->x = arrivee[0] ;
								mouvement->y = arrivee[1] ;
								printf("Votre coup est [%d,%d,%d,%d,%d]", insert, colonne, clock, arrivee[0], arrivee[1] ) ;
								//sendMove(&mouvement) ;
								return 0 ;								
						}		
					}
					
					if ( insert == 1 )
					{
						if ( clock == 0 )
						{
							rotation_tuile ( tuile_sup, 0, mouvement ) ;
							inserer_tuile ( x, y, laby_intermédiaire, mouvement, tuile_sup, insert, 1, colonne ) ;
						}
						if ( clock == 1 )
						{
							rotation_tuile ( tuile_sup, 1, mouvement ) ;
							inserer_tuile ( x, y, laby_intermédiaire, mouvement, tuile_sup, insert, 1, colonne ) ;
						}
						if ( clock == 2 )
						{
							rotation_tuile ( tuile_sup, 2, mouvement ) ;
							inserer_tuile ( x, y, laby_intermédiaire, mouvement, tuile_sup, insert, 1, colonne ) ;
						}
						if ( clock == 3 )
						{
							rotation_tuile ( tuile_sup, 3, mouvement ) ;
							inserer_tuile ( x, y, laby_intermédiaire, mouvement, tuile_sup, insert, 1, colonne ) ;
						}
						
						cheminPossible = expension ( x, y, laby, depart, arrivee, mouvement, joueur, tableauTresor ) ;
						if ( cheminPossible == 1111 )
						{
								mouvement->insert = insert ;
								mouvement->number = colonne ;
								mouvement->rotation = clock ;
								mouvement->x = arrivee[0] ;
								mouvement->y = arrivee[1] ;
								printf("Votre coup est [%d,%d,%d,%d,%d]", insert, colonne, clock, arrivee[0], arrivee[1] ) ;
								//sendMove(&mouvement) ;
								return 0 ;								
						}
					}
				}
			}
		}
	}
	
	if ( cheminPossible == 9999 )
	{
		coup ( &mouvement ) ;
		//sendMove(&mouvement) ;
		return 0 ;
	}
}


