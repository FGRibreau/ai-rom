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

/*typedef struct FileBranch_node* pFileBranch_node;
struct FileBranch_node{
	pCity		city;
	int			dist;		//Distance depuis le début de la route
	int			depth;		// Profondeur
	pFileBranch_node parent;		//Pointeur vers le noeuds parent
} FileBranch_node;*/

typedef struct File* pFile;
struct File{
	void* data;			//Pointe vers une route dans la file
	pFile next;			//Pointe vers le prochain élément dans la file
	pFile prev;
} FileBranch;

/*
 (FileBranch)maFile = {
	
	(FileBranche_node)[
		[city:Arad*, dist:0, depth:0, parent:null]
			[city:Siblu*, dist:140, depth:1, parent: (pointeur vers ligne du dessus)]
				[city:Fagaras*, dist:239, depth:2, parent: (pointeur vers ligne du dessus)]
				...]
	
	(FileBranche_node)[
		[city:Arad*, dist:0, depth:0, parent:null]
			[city:Siblu*, dist:140, depth:1, parent: (pointeur vers ligne du dessus)]
				[city:Fagaras*, dist:239, depth:2, parent: (pointeur vers ligne du dessus)]
				...]
 };
 
 */

//File de Branch
pFile File_create();
void File_push(pFile* file, void* data);
void file_first(pFile* file);
void file_prev(pFile* file);
#endif
