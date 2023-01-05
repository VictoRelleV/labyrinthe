#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "labyrinthAPI.h"

#ifndef __DEMANDE_COUP__
#define __DEMANDE_COUP__

void coup ( t_move* mouvement ) ;
int expension ( int x, int y, t_tuile laby[x][y], int depart[2], int arrivee[2] ) ;

#endif
