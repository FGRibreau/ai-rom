#include "env.h"

int _env_malloc = 0, _env_free = 0;

void* _malloc(size_t t){
	_env_malloc++;
	void* m = malloc(t);
	if(m == NULL){
		printf("Not enough memory");
		exit(0);
	}
	
	return m;
}

void _printMalloc(){
	printf("----------------------------\n");
	printf("Malloc:______________%-3d \n", _env_malloc);
	printf("Free:________________%-3d \n", _env_free);
	printf("Total:_______________%.2f%%\n", ((float)_env_free/(float)_env_malloc)*100);
	
	printf("----------------------------\n\n");
}

void _free(void* t){
	if(t == NULL){
		printf("\n\nNULL !\n\n");
	} else {
		_env_free++;
		free(t);
	}
	
}

/*
 mémo:
 
 Couleur		Texte	Fond
 Noir			30		40
 Rouge			31		41
 Vert			32		42
 Jaune			33		43
 Bleu			34		44
 Magenta		35		45  
 Cyan			36		46
 Blanc			37		47
 
 */
//AXXX : effet
//BXXX : texte
//CXXX : fond
