
#include "SearchAStar.h"

pFileData_city SearchAStar(pCity from, pCity to){
	
	//Liste ouverte (route non trouvée)
	pFile fileOpen = File_create();
	
	File_push(&fileOpen, FileData_city_create(NULL, from, 0, 0, City_distBtw(from, to)));
	
	do {	
		pFileData_city curCity = File_getASC(&fileOpen);
		
		if(curCity->city->branch == NULL){
			_free(curCity);
		} else {
			pBranch cursor = curCity->city->branch;
			
			//Parcours des enfants
			do {
				
				pFileData_city d =  FileData_city_appendASC(curCity, cursor, City_distBtw(cursor->city, to));//
				
				if(cursor->city == to){
					printf("%s Dist( %d ) + Heuristic( %f )\n", cursor->city->name, curCity->dist,  City_distBtw(cursor->city, to));
					FileData_printRoute(d);//Affiche la route
				}
				
				FileData_city_pushASC(&fileOpen, d);

			} while (cursor = cursor->next);
		}
		
	} while (!File_isEmpty(fileOpen) && ((pFileData_city)fileOpen->data)->city != to);
	
	
	return File_getASC(&fileOpen);
}
