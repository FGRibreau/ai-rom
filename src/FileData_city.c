/*
 *  File_branch.c
 *  TP1
 *
 *  Created by Francois-Guillaume Ribreau on 04/11/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "FileData_city.h"

pFileData_city FileData_city_create(pFileData_city parent, pCity city, int dist, int depth){
	pFileData_city obj = malloc(sizeof(FileData_city));
	obj->parent = parent;
	obj->dist = dist;
	obj->city = city;
	obj->depth = depth;
	return obj;
}

pFileData_city FileData_city_append(pFileData_city route, pBranch branch){
	pFileData_city obj = malloc(sizeof(FileData_city));
	
	obj->parent = route;
	obj->dist = route->dist + branch->dist;
	obj->city = branch->city;
	obj->depth = route->depth+1;
	return obj;
}

bool FileData_cityAlreadyExist(pFileData_city route, pCity city){
	
	do {
		if(route->city == city){
			return true;
		}
	} while (route = route->parent);
		   
	return false;
}

void FileData_printRoute(pFileData_city route){
	if(route == NULL){
		printf("Aucune route trouvée");
		return;
	}
	
	bstring b = bformat("(%dkm, %d étapes) ", route->dist, route->depth);
	
	
	do {
		bconcat(b, bformat("%s", route->city->name));
		
		if(route->parent != NULL){
			bconcat(b, bfromcstr(" <- "));
		}
	} while (route = route->parent);
	
	
	printf("%s\n", bstr2cstr(b, '\0'));
	
	bdestroy(b);
}