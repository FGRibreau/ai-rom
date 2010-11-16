
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

//Release all "FileData_city_append"
/*
 pFileData_city road = FileData_city_create(NULL, from, 0, 0); // Pas forcement optimal
 
 pFileData_city curCity = road;
 
 do {	
 
 pBranch neighbour = curCity->city->branch
 ,		bestCity = neighbour;//Ville voisine
 
 float	distBest = 99999999999
 ,		distToDest = 0;
 
 //printf("[ ");
 do {//Parcours les enfants de curCity->city
 
 distToDest = City_distBtw(neighbour->city, to);
 
 if((distToDest + neighbour->dist) < distBest
 && !FileData_cityAlreadyExist(road,neighbour->city)){
 bestCity = neighbour;
 distBest = distToDest+ neighbour->dist;
 }
 
 
 //printf("%s %.4f\t\t", neighbour->city->name, distToDest+ neighbour->dist);
 
 } while (neighbour = neighbour->next);//Parcour la liste chainée des villes voisines de City
 //printf("]\n");
 curCity = road = FileData_city_append(road, bestCity);
 
 } while (curCity->city != to);
 */
