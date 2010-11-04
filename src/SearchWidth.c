#include "SearchWidth.h"

pFileData_city SearchWidth(pCity from, pCity to){
	//Liste ouverte (route non trouvée)
	pFile fileOpen = File_create();
	
	//Liste fermée (route trouvée, terminée)
	pFileData_city bestRoad = NULL;
	
	File_push(&fileOpen, FileData_city_create(NULL, from, 0, 0));
	
	do {	
		pFileData_city curCity = File_get(&fileOpen);

		if(curCity->city->branch == NULL){
			free(curCity);
		} else {
			pBranch cursor = curCity->city->branch;
			
			do {
				if(	cursor->city == to && (bestRoad == NULL || (bestRoad != NULL && (curCity->dist + cursor->dist) < bestRoad->dist))){
						bestRoad = FileData_city_append(curCity, cursor);

				} else if(!FileData_cityAlreadyExist(curCity, cursor->city)){
					
					File_push(&fileOpen, FileData_city_append(curCity, cursor));
					
				}// else // Nous sommes déjà passé par là

			} while (cursor = cursor->next);
		}
		
	} while (!File_isEmpty(fileOpen));
	

	free(fileOpen);
	
	return bestRoad;
}
