

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
void* File_get(pFile* file);
void* File_getASC(pFile* file);
int File_size(pFile file);
#endif
