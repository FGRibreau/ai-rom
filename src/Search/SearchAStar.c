
#include "SearchAStar.h"

pFileData_city SearchAStar(pCity from, pCity to){
	
	//Liste ouverte (route non trouvée)
	pFile fileOpen = File_create();
	
	//Meilleure route
	pFileData_city bestRoad = NULL;
	
	File_push(&fileOpen, FileData_city_create(NULL, from, 0, 0));
	
	do {	
		pFileData_city curCity = File_get(&fileOpen);
		
		if(curCity->city->branch == NULL){
			_free(curCity);
		} else {
			pBranch cursor = curCity->city->branch;
			
			//Parcours des enfants
			do {
				if(cursor->city == to){
					
					bestRoad = FileData_city_append(curCity, cursor);
					
				} else if(!FileData_cityAlreadyExist(curCity, cursor->city)){
					pFileData_city d =  FileData_city_appendASC(curCity, cursor, City_distBtw(cursor->city, to));
					
					FileData_city_pushASC(&fileOpen, d);
					
					//FileData_printRoute(d);
				}
			} while (cursor = cursor->next);
		}
		
	} while (!File_isEmpty(fileOpen));
	
	
	return bestRoad;
}
