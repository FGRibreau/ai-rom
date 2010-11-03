/*
 *  File.h
 *  TP1
 *
 *  Created by Francois-Guillaume Ribreau on 03/11/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _FILE_h
#define _FILE_h

#include "City.h"

typedef struct File* pFile;

struct File{
	pBranch branch;
	pBranch next;	/* Next */
} File;



//File de Branch
pFile	File_create();
bool	File_push(pFile head, pBranch branch);
pBranch File_pop(pFile head);

#endif