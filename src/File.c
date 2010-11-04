/*
 *  File.c
 *  TP1
 *
 *  Created by Francois-Guillaume Ribreau on 03/11/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "File.h"

pFile File_create(){
	return NULL;
}




//Ajout un élément dans la file
void File_push(pFile* file, void* data){
	if (file == NULL){
		return;
	}
	
	pFile p_l = NULL;
	pFile p_p = NULL;
	file_first(file);
	/* (2) */
	p_l = *file;
	/* (3) */
	p_p = malloc (sizeof (*p_p)); 
	
	if (p_p != NULL){
		p_p->data = data;
		/* (4) */
		p_p->next = p_l; 
		p_p->prev = NULL; 
		
		if (p_l != NULL){
			p_l->prev = p_p;
			//5
			*file = p_p;
		} else {
			fprintf (stderr, "Memoire insuffisante\n");
			exit (EXIT_FAILURE);
		}
	}
}

void file_first(pFile* file){
	if (file != NULL && *file != NULL){
		while ((*file)->prev != NULL)
			file_prev(file);
	}
	return; 
}

void file_prev(pFile* file){
	if (file != NULL && *file != NULL) 
		*file = (*file)->prev;
	return;
}
