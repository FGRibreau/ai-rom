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

#ifndef _CITY_h
#define _CITY_h

typedef enum{false,true}bool;

typedef struct City* pCity;
typedef struct Branch* pBranch;

struct Branch{
	pCity city;				/* Pointeur sur City */
	unsigned int dist;		/* Distance */
	pBranch next;			/* Next */
} Branch;

struct City{
    char*		name;
	pBranch branch; 
/*
	pCity		City_create();
	void		City_destroy();
	void		City_branchLink(pCity cityA, pCity cityB, unsigned int dist);
	bool		City_branchAdd(pCity city, pBranch branch);
	bool		City_branchIsEmpty(pCity);
	bool		City_branchExist(pCity city, pCity cityInner);
 
	pBranch		branch_walkToCity(pBranch branch, pCity city);
	pBranch		branch_walkToEnd(pBranch branch);
*/
} City;


/* Methodes City */
pCity	City_create(char* name);
void	City_destroy();
bool	City_branchLink(pCity cityA, pCity cityB, unsigned int dist);
bool	City_branchAdd(pCity city, pBranch branch);
bool	City_branchExist(pCity city, pCity cityInner);

/* Méthodes Branch */
pBranch branch_walkToCity(pBranch branch, pCity city);
pBranch branch_walkToEnd(pBranch branch);


#endif