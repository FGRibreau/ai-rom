
#ifndef _FILEDATA_city_h
#define _FILEDATA_city_h

#include "File.h"
#include "City.h"
#include "env.h"

typedef struct FileData_city* pFileData_city;

struct FileData_city{
	pFileData_city parent;
	pCity	city;					//ville actuelle
	int		dist;					//cout chemin
	int		heuristic;				//heuristic (cout à vol d'oiseau)
	int		depth;					//profondeur
} FileData_city;

pStack	__FileData_city_malloc;		//Stack qui contient l'intégralité des pointeurs générés


//pFileData_city FileData_city_create(pFileData_city parent, pCity city, int dist, int depth);//Constructeur
pFileData_city FileData_city_create(pFileData_city parent, pCity city, int dist, int heuristic, int depth);

//Ajout une ville à la suite d'une route de ville et retourne l'en-tête
pFileData_city FileData_city_append(pFileData_city route, pBranch branch);
pFileData_city FileData_city_appendASC(pFileData_city route, pBranch branch, float dist);

void FileData_city_pushASC(pFile* file, pFileData_city data);
void FileData_city_list(pFile file);

bool FileData_cityAlreadyExist(pFileData_city route, pCity city);
void FileData_cityFree();
void FileData_printRoute(pFileData_city route);


#endif