
#include "SearchAStar.h"

pFileData_city SearchAStar(pCity from, pCity to){
	
	pFileData_city road = FileData_city_create(NULL, from, 0, 0); // Pas forcement optimal
	
	pFileData_city curCity = road;
	
	do {	
		
		pBranch neighbour = curCity->city->branch
		,		bestCity = neighbour;//Ville voisine
		
		float	distBest = 99999999999
		,		distToDest = 0;
		
		do {//Parcours les enfants de curCity->city
			
			distToDest = City_distBtw(neighbour->city, to);
		
			if((distToDest + neighbour->dist)  < distBest){
				bestCity = neighbour;
				distBest = distToDest+ neighbour->dist;
			}
			
		} while (neighbour = neighbour->next);//Parcour la liste chainée des villes voisines de City
		
		curCity = road = FileData_city_append(road, bestCity);
		
	} while (curCity->city != to);
	
	return road;
}
