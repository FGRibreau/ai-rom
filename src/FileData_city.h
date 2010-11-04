/*
 *  File_city.h
 *  TP1
 *
 *  Created by Francois-Guillaume Ribreau on 04/11/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef _FILEDATA_city_h
#define _FILEDATA_city_h

#include "City.h"
#include "env.h"

typedef struct FileData_city* pFileData_city;

struct FileData_city{
	pFileData_city parent;
	pCity	city;					//ville actuelle
	int		dist;					//cout chemin
	int		depth;					//profondeur
}FileData_city;


pFileData_city FileData_city_create(pFileData_city parent, pCity city, int dist, int depth);//Constructeur

//Ajout une ville à la suite d'une route de ville et retourne l'en-tête
pFileData_city FileData_city_append(pFileData_city route, pBranch branch);

bool FileData_cityAlreadyExist(pFileData_city route, pCity city);

void FileData_printRoute(pFileData_city route);
#endif