/*
 *  env.c
 *  TP1
 *
 *  Created by Francois-Guillaume Ribreau on 12/11/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "env.h"

int _env_malloc = 0, _env_free = 0;

void* _malloc(size_t t){
	_env_malloc++;
	return malloc(t);
}

void _printMalloc(){
	printf("-- M(%-3d) F(%-3d) :: %.2f%% --\n", _env_malloc, _env_free, ((float)_env_free/(float)_env_malloc)*100);

	/*
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
	
	if(_env_malloc == _env_free){
		printf("\nSUCCESS !");
	} else {
		printf("\033[32mFAIL: Tout n'est pas libéré !\033[0m");
	}
	
	printf("\n\n");
}

void _free(void* t){
	_env_free++;
	free(t);
}