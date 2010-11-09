#include "Hash.h"


pHash Hash_create(){
	return NULL;
}

/*
 * Return NULL if not found
 * Return data* if "index" found in hash
 */
void* Hash_get(pHash hash, char* index){
	if(hash == NULL){
		return NULL;
	}
	
	//Boucle sur la liste chainée + comparaison de index
	do{	
		//Comparaison des index
		if(hash->index != NULL && strcmp(hash->index, index) == 0){
			return hash->data;
		}
	}while((hash = hash->prev));
	
	return NULL;
}

void Hash_set(pHash* hash, char* index, void* pData){
	if(Hash_get(*hash, index) != NULL){
		return;
	}
	
	//Creation de la nouvelle node
	pHash nHash = malloc(sizeof(Hash));
	
	nHash->data = pData;
	
	nHash->index = malloc(sizeof(char) * strlen(index));
	strcpy(nHash->index, index);
	
	if(*(hash) != NULL){
		(*hash)->next = nHash;
		nHash->prev = *hash;
	}
	nHash->next = NULL;
	
	*hash = nHash;
}