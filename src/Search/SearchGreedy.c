#include "SearchGreedy.h"

pFileData_city SearchGreedy(pCity from, pCity to){

	//Longueur minimun trouvé dans les fils
	float lengthMin = 0;
	//Meilleure route
	pFileData_city bestRoad = NULL; // Pas forcement optimal
	FileData_city cursor =  FileData_city_create(NULL, from, 0, 0);
	do{
		pBranch nextCity = cursor->city->branch
		,		bestCity = cursor->city->branch;
		if(nextCity!=NULL){
			do{
				if(nextCity->dist < nextCity->next->dist){

				}
			}while(nextCity = nextCity->next);
			cursor = FileData_city_append(cursor,bestCity);
		}
	}while(cursor->city != to);



	return bestRoad;
}
