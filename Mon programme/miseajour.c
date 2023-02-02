#include <stdio.h>
#include <stdlib.h>
#include "miseajour.h"
#include "structure.h"
#include "labyrinthAPI.h"

/*
La fonction "initialisation" initialise les données de départ.
*/
void initialisation ( t_labyrinth* laby, t_position2* joueur, int indicejoueur, int TileN, int TileE, int TileS, int TileW, int TileItem, t_move* mouvement)
{
	laby->TuileSup.North = TileN ;
	laby->TuileSup.East = TileE ;
	laby->TuileSup.South = TileS ;
	laby->TuileSup.West = TileW ;
	laby->TuileSup.Item = TileItem ;
	
	mouvement->tileN = TileN ;
	mouvement->tileE = TileE ;
	mouvement->tileS = TileS ;
	mouvement->tileW = TileW ;
	mouvement->tileItem = TileItem ;
	
	if ( indicejoueur == 1 )
	{ 
		joueur->joueur1.positionx = 0 ;
		joueur->joueur1.positiony = 0 ;
		mouvement->nextItem = 1 ;
		joueur->joueur2.positionx = laby->sizeX -1 ;
		joueur->joueur2.positiony = laby->sizeY -1 ;
	}
	
	else if ( indicejoueur == 2 )
	{
		joueur->joueur1.positionx = laby->sizeX -1 ;
		joueur->joueur1.positiony = laby->sizeY -1 ;
		mouvement->nextItem = 24 ;
		joueur->joueur2.positionx = 0 ;
		joueur->joueur2.positiony = 0 ;
	}
}

/*
La fonction "maj" met à jour les données du jeu.
*/
void maj ( t_labyrinth* laby, t_position2* joueur, t_move* mouvement, int indicejoueur )
{
	laby->TuileSup.North = mouvement->tileN ;
	laby->TuileSup.East = mouvement->tileE ;
	laby->TuileSup.South = mouvement->tileS ;
	laby->TuileSup.West = mouvement->tileW ;
	laby->TuileSup.Item = mouvement->tileItem ;
	
	if ( indicejoueur == 1 )
	{ 
		joueur->joueur1.positionx = mouvement->x ;
		joueur->joueur1.positiony = mouvement->y ;
	}
	
	else if ( indicejoueur == 2 )
	{
		joueur->joueur2.positionx = mouvement->x ;
		joueur->joueur2.positiony = mouvement->y ;
	}
}
