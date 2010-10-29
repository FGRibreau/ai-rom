/*
 *  plan.h
 *  TP1
 *
 *  Created by Francois-Guillaume Ribreau on 22/10/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct City* pCity;
typedef struct BranchNode* pBranchNode;

struct BranchNode{
	pCity city;			/* Pointeur sur City */
	unsigned int dist;	/* Distance */
	/* Ajouter le next */
} BranchNode;

struct City{
    char* name;
	pBranchNode branch; /*
	branchAdd(pCity city, unsigned int dist);
*/
} City;

/* Methodes */
pCity cityCreate(char* name);
void cityDestroy(pCity city);