/*
 *  plan.c
 *  TP1
 *
 *  Created by Francois-Guillaume Ribreau on 22/10/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "City.h"


pCity cityCreate(char* name){
	pCity tmpCity = malloc(sizeof(City));
	
	tmpCity->name = malloc(sizeof(char) * strlen(name));
	
	strcpy(tmpCity->name, name);
	tmpCity->branch = NULL; // Ne pointe vers rien
	
	return tmpCity;
}
	
void cityDestroy(pCity city){
	
	free(city->name);
	
	//TODO Parcourir l'arbre et désalloué
	
	free(city);
}
