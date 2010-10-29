/*
 *  plan.c
 *  TP1
 *
 *  Created by Francois-Guillaume Ribreau on 22/10/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "Noeud.h"

typedef struct Noeud* Arbre;
typedef struct cell* list;

struct cell{
	Arbre son;
	list next;
};

struct Noeud{
    char nomVille[250];
	list fils; // 1 ou plusieurs fils
};