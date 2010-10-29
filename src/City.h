/*
 *  plan.h
 *  TP1
 *
 *  Created by Francois-Guillaume Ribreau on 22/10/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

typedef struct City* pCity;
typedef struct BranchNode* pBranchNode;

struct BranchNode{
	pCity city;			/* Pointeur sur City */
	unsigned int dist;	/* Distance */
};

struct City{
    char cityName[250];
	pBranchNode branch; /*
						 branchAdd(pCity city, unsigned int dist);
						 
						 */
};

/*
 cityCreate(char* cityName);
 
 */