#include "SearchDepth.h"

pFileData_city SearchDepth(pCity from, pCity to){
	//Liste ouverte (route non trouvée)
	pStack stackOpen = Stack_create();
	
	//Meilleure route
	pFileData_city bestRoad = NULL;
	
	Stack_push(&stackOpen, FileData_city_create(NULL, from, 0, 0));
	
	do {	
		pFileData_city curCity = Stack_pop(&stackOpen);

		if(curCity->city->branch == NULL){
			_free(curCity);
		} else {
			pBranch cursor = curCity->city->branch;
			
			do {
				if(bestRoad == NULL || (bestRoad != NULL && (curCity->dist + cursor->dist) < bestRoad->dist)){
					
					if(cursor->city == to){
						
						bestRoad = FileData_city_append(curCity, cursor);

					} else if(!FileData_cityAlreadyExist(curCity, cursor->city)){
						
						Stack_push(&stackOpen, FileData_city_append(curCity, cursor));
						
					}
					
				}
			} while (cursor = cursor->next);
		}
		
	} while (!Stack_isEmpty(stackOpen));
	

	
	//Release all "FileData_city_append"
	
	return bestRoad;
}
