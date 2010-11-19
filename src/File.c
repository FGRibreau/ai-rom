

#include "File.h"

pFile File_create(){
	return NULL;
}


//Ajout un élément dans la file
void File_push(pFile* file, void* data){
	
	pFile node = _malloc (sizeof (File))
		, OldFirstEl = *file;
	
	node->data = data;
	node->prev = NULL;
	node->next = NULL;
	
	if(OldFirstEl != NULL){
		OldFirstEl->prev = node;
		node->next = OldFirstEl;
	}
	
	*file = node;
	return;
}

bool File_isEmpty(pFile file){
	return file == NULL;
}

int File_size(pFile file){
	if(file == NULL)
		return 0;
	
	int i = 0;
	
	//pFile cursor = file;
	
	while(file){
		i++;
		file = file->next;
	}
	
	return i;
}

/* Retourne un élment de la file */
void* File_get(pFile* file){
	pFile cursor = *file
		, newLastEl = NULL;
	
	void* ret = NULL;
	
	while(cursor->next != NULL){
		cursor = cursor->next;
	}
	
	if(cursor != NULL && cursor->prev != NULL){
		newLastEl = cursor->prev;
	}
	
	ret = cursor->data;
	_free(cursor);
	cursor = NULL;
	
	if(newLastEl != NULL){
		newLastEl->next = NULL;
	} else {
		*file = NULL;
	}

	return ret;
}


void* File_getASC(pFile* file){
	pFile cursor = *file
	, newFirstEl = NULL;
	
	void* ret = NULL;
	
	if(cursor->next != NULL){
		newFirstEl = cursor->next;
	}
	
	ret = cursor->data;
	_free(cursor);
	cursor = NULL;
	
	if(newFirstEl != NULL){
		newFirstEl->prev = NULL;
		*file = newFirstEl;
	} else {
		*file = NULL;
	}
	
	return ret;
}

