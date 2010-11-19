#include "SearchWidth_withAllReachedRoad.h"

void Search_defCon1(pCity from, pCity to){
	//Liste ouverte (route non trouvée)
	pFile fileOpen = File_create();
	
	//Liste fermée (route trouvée, terminée)
	pFile fileReached = File_create();
	
	File_push(&fileOpen, FileData_city_create(NULL, from, 0, 0, 0));
	
	do {	
		pFileData_city curCity = File_get(&fileOpen);

		if(curCity->city->branch == NULL){
			_free(curCity);
		} else {
			pBranch cursor = curCity->city->branch;
			
			do {
				if(cursor->city == to){
					
					File_push(&fileReached, FileData_city_append(curCity, cursor));
					
				} else if(!FileData_cityAlreadyExist(curCity, cursor->city)){
					
					File_push(&fileOpen, FileData_city_append(curCity, cursor));
					
				}// else // Nous sommes déjà passé par là

			} while (cursor = cursor->next);
		}
		
	} while (!File_isEmpty(fileOpen));
	
	Search_showFileReached(fileReached);
	
	_free(fileOpen);
	_free(fileReached);
}

void Search_showFileReached(pFile fileReached){
	if(fileReached == NULL){
		return;
	}
	
	do {
		printf("Dist: %d Depth: %d ",	((pFileData_city)fileReached->data)->dist,
										((pFileData_city)fileReached->data)->depth);
		
		FileData_printRoute(fileReached->data);
	} while (fileReached = fileReached->next);
	
	
}