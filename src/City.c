
#include "City.h"


pCity City_create(char* name){
	pCity tmpCity = malloc(sizeof(City));
	
	tmpCity->name = malloc(sizeof(char) * strlen(name));
	
	strcpy(tmpCity->name, name);
	tmpCity->branch = NULL; // Ne pointe vers rien
	
	return tmpCity;
}
	
void City_destroy(pCity city){
	//TODO Parcourir l'arbre et désalloué
}

bool City_branchLink(pCity cityA, pCity cityB, unsigned int dist){
	//Vérifier que cityA n'est pas dans cityB (et inversement)
	if(City_branchExist(cityA, cityB) || City_branchExist(cityB, cityA)){
		printf("Un chemin existe déjà entre %s et %s.", cityA->name, cityB->name);
		return false;
	}

	pBranch Branch1 = malloc(sizeof(Branch))	//CityA.branch
	,		Branch2 = malloc(sizeof(Branch));	//CityB.branch
	
	//Configure les branches
	Branch1->city = cityB;
	Branch2->city = cityA;
	Branch1->dist = Branch2->dist = dist;

	//Ajout réellement les branches
	return City_branchAdd(cityA, Branch1) && City_branchAdd(cityB, Branch2);
}


//Ajoute une branch dans la liste chainée de city.branch
bool City_branchAdd(pCity city, pBranch branch){
	//Vérifie si city.branch est vide
	if(city->branch == NULL){
		city->branch = branch;	
	} else {
		pBranch cursor = branch_walkToEnd(city->branch);
		cursor->next = branch;
	}
	
	return true;
}

//Vérifie que cityInner n'est pas dans la liste chainée de city.branch
bool City_branchExist(pCity city, pCity cityInner){
	
	if(city->branch == NULL){//Aucun noeud dans city.branch
		return false;
	}
	
	return branch_walkToCity(city->branch, cityInner) != NULL;
}

//Parcoure une liste chainée Branch jusqu'à trouvé City
//return NULL si non trouvé
//return pBranch si city trouvé à cet endroit précis
pBranch branch_walkToCity(pBranch branch, pCity city){
	pBranch cursor = branch;
	
	do {
		if(cursor->city == city){
			return cursor;
		}
	} while ((cursor = cursor->next));

	return NULL;
}

//Parcoure une liste chainée Branch jusqu'à la fin
pBranch branch_walkToEnd(pBranch branch){
	pBranch cursor = branch;
	
	while(cursor->next){
		cursor = cursor->next;
	}
	
	return cursor;
}










