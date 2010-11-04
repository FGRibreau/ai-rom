/*
 *  Search_DefCon1.c
 *  TP1
 *
 *  Created by Francois-Guillaume Ribreau on 04/11/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "Search_DefCon1.h"

void Search_defCon1(pCity from, pCity to){
	//Liste ouverte (route non trouvée)
	pFile fileOpen = File_create();
	
	//Liste fermée (route trouvée, terminée)
	pFile fileReached = File_create();
	
	
	File_push(&fileOpen, FileData_city_create(NULL, from, 0, 0));
	do {	
		pFileData_city curCity = File_get(&fileOpen);
		
		printf("\nPar de %s", curCity->city->name);
		
		//Si pas d'enfant, arrêter là (cette route ne mène pas vers "to" c'est pas bon
		if(curCity->city->branch == NULL){
			
			//Désallouer toute la route (l'ensemble de pFileData_city //Boucler sur curCity->parent //Désalouer l'élément précédent
		} else {
			//Boucler sur les villes voisines
			
			pBranch cursor = curCity->city->branch;
			
			do {
				printf("\n...   vers %s", cursor->city->name);
				//Si enfants == to
				//Ajouter la route dans fileReached
				if(cursor->city == to){
					printf(" BIP BIP!");
					
					//Ajout après curCity l'enfant "cursor->city"
					File_push(&fileReached, FileData_city_append(curCity, cursor));
				
				} else if(!FileData_cityAlreadyExist(curCity, cursor->city)){
					//Ajouter cette route + enfant dans fileOpen
					File_push(&fileOpen, FileData_city_append(curCity, cursor));
				} else {
					printf(" We were already there.");
				}
				
				//Si l'enfant n'est pas déjà dans la route
				//Ajouter cette route + enfant dans fileOpen
				//Sinon (l'enfant est déjà dans la route), ne rien faire.
				
			} while (cursor = cursor->next);
		}

	} while (!File_isEmpty(fileOpen));
	
	
	printf("\n%d route(s) trouvée(s)", File_size(fileReached));
	
	Search_showFileReached(fileReached);

}

void Search_showFileReached(pFile fileReached){
	do {
		FileData_printRoute(fileReached->data);
	} while (fileReached = fileReached->next);
	
	
}