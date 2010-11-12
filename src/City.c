#include "City.h"


pCity City_create(char* name, float lat, float lon){
	pCity tmpCity = _malloc(sizeof(City));
	
	tmpCity->name = _malloc(sizeof(char) * strlen(name));
	
	strcpy(tmpCity->name, name);
	tmpCity->branch = NULL; // Ne pointe vers rien
	
	tmpCity->lat = lat;
	tmpCity->lon = lon;
	
	return tmpCity;
}
	
void City_destroy(pCity city){
	//TODO Parcourir l'arbre et désalloué
}


//Todo: mettre en place un cache
float City_distBtw(pCity cityA, pCity cityB){
	return 1.852 * 60 * acos(sin(cityA->lat)* sin(cityB->lat) + cos(cityA->lat) * cos(cityB->lat) * cos(cityB->lon - cityB->lon));
}

bool City_branchLink(pCity cityA, pCity cityB, unsigned int dist){
	//Vérifier que cityA n'est pas dans cityB (et inversement)
	if(City_branchExist(cityA, cityB) || City_branchExist(cityB, cityA)){
		printf("Un chemin existe déjà entre %s et %s.", cityA->name, cityB->name);
		return false;
	}

	pBranch Branch1 = Branch_create()	//CityA.branch
	,		Branch2 = Branch_create();	//CityB.branch
	
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
		pBranch cursor = Branch_walkToEnd(city->branch);
		cursor->next = branch;
	}
	
	return true;
}

//Vérifie que cityInner n'est pas dans la liste chainée de city.branch
bool City_branchExist(pCity city, pCity cityInner){
	
	if(city->branch == NULL){//Aucun noeud dans city.branch
		return false;
	}
	
	return Branch_walkToCity(city->branch, cityInner) != NULL;
}


pBranch Branch_create(){
	//TODO: Enregistrer tous les pointeurs créé
	return _malloc(sizeof(Branch));
}

//Parcoure une liste chainée Branch jusqu'à trouvé City
//return NULL si non trouvé
//return pBranch si city trouvé à cet endroit précis
pBranch Branch_walkToCity(pBranch branch, pCity city){
	pBranch cursor = branch;
	
	do {
		if(cursor->city == city){
			return cursor;
		}
	} while ((cursor = cursor->next));

	return NULL;
}

//Parcoure une liste chainée Branch jusqu'à la fin
pBranch Branch_walkToEnd(pBranch branch){
	pBranch cursor = branch;
	
	while(cursor->next){
		cursor = cursor->next;
	}
	
	return cursor;
}

//
void Branch_free(){
	//Boucler sur le tableau de pointeur pBranch
}






