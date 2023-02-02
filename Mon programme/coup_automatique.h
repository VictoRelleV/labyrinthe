#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "labyrinthAPI.h"

#ifndef __COUP_AUTOMATIQUE__
#define __COUP_AUTOMATIQUE__

void tableau_tresor ( int x, int y, t_tuile laby[x][y], int tableauTresor[24][2] ) ;
void rotation_tuile ( t_tuile tuile_sup, int rotation, t_move* mouvement ) ;
void inserer_tuile ( int x, int y, t_tuile laby[x][y], t_move* mouvement, t_tuile tuile_sup, int insert, int num_ligne, int num_colonne ) ;
int coup_automatique ( int x, int y, t_tuile laby[x][y], t_move* mouvement, int depart[2], int arrivee[2], t_position2* joueur, int tableauTresor[24][2], t_tuile tuile_sup ) ;
void maj_laby_intermédiaire ( int x, int y, t_tuile laby_intermédiaire[x][y], t_tuile laby[x][y] ) ;

#endif
