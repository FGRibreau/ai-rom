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
	void City_branchLink(pCity cityA, pCity cityB, unsigned int dist);
	bool City_branchIsEmpty(pCity);
*/
} City;

/*
 
 CityFG --- *BranchNode1 -> CityPhilou
 CityFG <-- *BranchNode2 -- CityPhilou
 CityFG --- *BranchNode3 -> CityBricaud
 CityFG <-- *BranchNode4 -- CityBricaud
 
 
 CityFG
	name: "FG"
	branch: *BranchNode1(CityPhilou) :next *BrancheNode3(CityBricaud)
 
 */

/* Methodes */
pCity cityCreate(char* name);
void cityDestroy(pCity city);