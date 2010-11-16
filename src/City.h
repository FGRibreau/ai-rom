
#ifndef _CITY_h
#define _CITY_h
#include "env.h"
#include "Stack.h"

typedef struct City* pCity;

typedef struct Branch* pBranch;

struct Branch{
	pCity city;				/* Pointeur sur City */
	float dist;		/* Distance */
	pBranch next;			/* Next */
} Branch;


struct City{
    char*		name;
	float lat;				// Localisation en "x" sur le plan
	float lon;				// Localisation en "y" sur le plan
	pBranch branch; 
/*
	pCity		City_create();
	void		City_destroy();
	void		City_branchLink(pCity cityA, pCity cityB, unsigned int dist);
	bool		City_branchAdd(pCity city, pBranch branch);
	bool		City_branchIsEmpty(pCity);
	bool		City_branchExist(pCity city, pCity cityInner);
	float		City_distBtw(pCity cityA, pCity B);
 
	pBranch		branch_walkToCity(pBranch branch, pCity city);
	pBranch		branch_walkToEnd(pBranch branch);
*/
} City;

//extern



/* Methodes City */
pCity	City_create(char* name, float lat, float lon);
void	City_destroy();
bool	City_branchLink(pCity cityA, pCity cityB, unsigned int dist);
bool	City_branchAdd(pCity city, pBranch branch);
bool	City_branchExist(pCity city, pCity cityInner);
float	City_distBtw(pCity cityA, pCity B);
/* Méthodes Branch */

pStack	__Branch_malloc;
pBranch Branch_create();
pBranch Branch_walkToCity(pBranch branch, pCity city);
pBranch Branch_walkToEnd(pBranch branch);
void	Branch_free();


#endif
