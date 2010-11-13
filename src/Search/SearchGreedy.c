#include "SearchGreedy.h"

pFileData_city SearchGreedy(pCity from, pCity to){

	pFileData_city road = FileData_city_create(NULL, from, 0, 0); // Pas forcement optimal
	
	pFileData_city curCity = road;
	
	do {	
		
		pBranch neighbour = curCity->city->branch
		,		bestCity = neighbour;//Ville voisine
		
		float	distBest = 99999999999
		,		distToDest = 0;
		
		do {//Parcours les enfants de curCity->city
			
			if((distToDest = City_distBtw(neighbour->city, to)) < distBest){
				bestCity = neighbour;
				distBest = distToDest;
			}

		} while (neighbour = neighbour->next);//Parcour la liste chainée des villes voisines de City
		
		//printf("%s\n", bestCity->city->name);
		curCity = road = FileData_city_append(road, bestCity);

	} while (curCity->city != to);

	return road;
}
