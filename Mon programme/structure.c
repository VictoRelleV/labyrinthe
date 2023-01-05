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
			printf ("\n") ;
		}
		printf ("%d", lab[i]) ;
	}	
	printf ("\n") ;
}

/*
La fonction "remplir_tableau_tuile" remplie la tableau "tableau_tuile" par les tuiles du labyrinthe
*/
void remplir_tableau_tuile ( int sizeX, int sizeY, t_tuile tableau_tuile[sizeX*sizeY], int lab[sizeX*sizeY*5] ) 
{
	for (int j=0; j<sizeX*sizeY; j++)
	{
		tableau_tuile[j].North = lab[0+5*j] ;
		tableau_tuile[j].East = lab[1+5*j] ;
		tableau_tuile[j].South = lab[2+5*j] ;
		tableau_tuile[j].West = lab[3+5*j] ;
		tableau_tuile[j].Item = lab[4+5*j] ;
	}
}
