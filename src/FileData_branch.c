/*
 *  File_branch.c
 *  TP1
 *
 *  Created by Francois-Guillaume Ribreau on 04/11/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "FileData_branch.h"

pFileData_branch FileData_branch_create(pFileData_branch parent, int dist, int depth){
	pFileData_branch obj = malloc(sizeof(FileData_branch));
	obj->parent = parent;
	obj->dist = dist;
	obj->depth = depth;
	return obj;
}