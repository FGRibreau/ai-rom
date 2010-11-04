/*
 *  File_branch.h
 *  TP1
 *
 *  Created by Francois-Guillaume Ribreau on 04/11/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef _FILEDATA_BRANCH_h
#define _FILEDATA_BRANCH_h

#include "env.h"

typedef struct FileData_branch* pFileData_branch;

struct FileData_branch{
	pFileData_branch parent;
	pCity	city;					//ville actuelle
	int		dist;					//cout chemin
	int		depth;					//profondeur
}FileData_branch;

pFileData_branch FileData_branch_create(pFileData_branch parent, pCity city, int dist, int depth);//Constructeur

#endif