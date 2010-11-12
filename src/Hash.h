
#ifndef _HASH_H
#define _HASH_H

#include "env.h"

typedef struct Hash* pHash;
typedef void (*Hash_forEachCallback)(char*, void*);     

struct Hash{
	pHash prev; /* Liste simplement chainée */
	pHash next;
	char* index;
	void* data;
} Hash;

pHash	Hash_create();
void*	Hash_get(pHash hash, char* index);													// arr["index"]
void	Hash_set(pHash* hash, char* index, void* pData);									// arr["index"] = pData;
void	Hash_forEach(pHash hash, void (*forEachCallback)(char*, void*, pHash hash));				// arr.forEach(callback(index, value){});
void	Hash_free(pHash hash);																// delete arr;
#endif