#include <stdio.h>
#include <stdlib.h>

#ifndef __STRUCTURE__
#define __STRUCTURE__

typedef struct {
	int North, East, South, West ;
	int Item ;
} t_tuile ;

typedef struct {
	int sizeX ;
	int sizeY ;
	t_tuile TuileSup ;
} t_labyrinth ;

typedef struct {
	int positionx ;
	int positiony ;
} t_position ;

typedef struct {
	t_position joueur1 ;
	t_position joueur2 ;
} t_position2 ;
	
void affiche_labyrinthe ( int sizeX, int sizeY, int lab[sizeX*sizeY*5] ) ;

void remplir_tableau_tuile ( int sizeX, int sizeY, t_tuile tableau_tuile[sizeX*sizeY], int lab[sizeX*sizeY*5] ) ;

#endif
