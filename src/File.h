/*
 *  File.h
 *  TP1
 *
 *  Created by Francois-Guillaume Ribreau on 03/11/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
	FILE: FIFO (First In First out) //Profondeur
	PILE: LIFO (Last In First Out)	//Largeur
 */

#ifndef _FILE_h
#define _FILE_h

#include "env.h"

typedef struct File* pFile;
struct File{
	void* data;			//Pointe vers une route dans la file
	pFile next;			//Pointe vers le prochain élément dans la file
	pFile prev;
} File;


pFile File_create();
void File_push(pFile* file, void* data);
bool File_isEmpty(pFile file);
void File_first(pFile* file);
void File_prev(pFile* file);
void File_last(pFile* file);
void File_next(pFile* file);
void* File_get(pFile* file);
int File_size(pFile file);
#endif
