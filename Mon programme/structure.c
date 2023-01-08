#include "clientAPI.h"
#include "labyrinthAPI.h"
#include "structure.h"
#include <stdio.h>
#include <stdlib.h>

/*
La fonction "affiche_labyrinthe" affiche le labyrinthe
*/
void affiche_labyrinthe ( int sizeX, int sizeY, int lab[sizeX*sizeY*5] )
{	
	for (int i=0; i<sizeX*sizeY*5; i++)
	{
		if ( i%5 == 0 )
		{
			printf (" ") ;
		}
		if ( i%(sizeX*5) == 0 )
		{
			printf ("\n") ;
		}
		printf ("%d", lab[i]) ;
	}	
	printf ("\n") ;
}

/*
La fonction "remplir_tableau_tuile" remplie la tableau "tableau_tuile" par les tuiles du labyrinthe
*/
void remplir_tableau_tuile ( int sizeX, int sizeY, t_tuile tableau_tuile[sizeX][sizeY], int lab[sizeX*sizeY*5] ) 
{
	int cpt=0 ;
	
	for (int j=0; j<sizeY; j++)
	{
		for ( int i=0; i<sizeX; i++ )
		{
			tableau_tuile[i][j].North = lab[cpt] ;
			cpt ++ ;
			tableau_tuile[i][j].East = lab[cpt] ;
			cpt ++ ;
			tableau_tuile[i][j].South = lab[cpt] ;
			cpt ++ ;
			tableau_tuile[i][j].West = lab[cpt] ;
			cpt ++ ;
			tableau_tuile[i][j].Item = lab[cpt] ;
			cpt ++ ;
		}
	}
}
