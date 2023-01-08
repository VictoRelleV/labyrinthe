#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "labyrinthAPI.h"

#ifndef __COUP_AUTOMATIQUE__
#define __COUP_AUTOMATIQUE__

void cherche_tresor ( int x, int y, t_tuile laby[x][y], int depart[2], int arrivee[2], t_move mouvement, t_position2* joueur, int tableauTresor[24][2] ) ;
void tableau_tresor ( int x, int y, t_tuile laby[x][y], int tableauTresor[24][2] ) ;

#endif
