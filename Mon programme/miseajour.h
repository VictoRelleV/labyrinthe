#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "labyrinthAPI.h"

#ifndef __MISEAJOUR__
#define __MISEAJOUR__

void initialisation ( t_labyrinth* laby, t_position2* joueur, int indicejoueur, int TileN, int TileE, int TileS, int TileW, int TileItem, t_move* mouvement) ;

void maj ( t_labyrinth* laby, t_position2* joueur, t_move* mouvement, int indicejoeur ) ;

#endif
