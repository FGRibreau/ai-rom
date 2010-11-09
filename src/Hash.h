
#ifndef _HASH_H
#define _HASH_H

#include "env.h"

typedef struct Hash* pHash;

struct Hash{
	pHash prev; /* Liste simplement chainée */
	pHash next;
	char* index;
	void* data;
} Hash;

pHash	Hash_create();
void*	Hash_get(pHash hash, char* index);					// arr["index"]
void	Hash_set(pHash* hash, char* index, void* pData);	// arr["index"] = pData;

#endif