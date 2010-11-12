#include "SearchGreedy.h"

pFileData_city SearchGreedy(pCity from, pCity to){

	//La route est une liste chainée de pFileData_city
	pFileData_city road = FileData_city_create(NULL, from, 0, 0); // Pas forcement optimal
	
	pFileData_city curCity = road;
	
	do {	
		
		pBranch neighbour = curCity->city->branch
		,		bestCity = neighbour;//Ville voisine
		
		float	distBest = 99999999999
		,		distToDest = 0;
		
		do {//Parcours les enfants
			
			distToDest = City_distBtw(neighbour->city, to);
			if(distToDest < distBest){//bestNextCity
				bestCity = neighbour;
				distBest = distToDest;
			}

		} while (neighbour = neighbour->next);//Parcour la liste chainée des villes voisines de City

		road = FileData_city_append(road, bestCity);
		
		curCity = road;
	} while (curCity->city != to);


	return road;
}
