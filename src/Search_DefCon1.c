/*
 *  Search_DefCon1.c
 *  TP1
 *
 *  Created by Francois-Guillaume Ribreau on 04/11/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "Search_DefCon1.h"

void Search_defCon1(pCity from, pCity to){
	//Liste ouverte (route non trouvée)
	pFile fileOpen = File_create();
	
	

	
	//Liste fermée (route trouvée, terminée)
	pFile fileReached = File_create();
	
	
	File_push(&fileOpen, FileData_branch_create(null, 0, 0));
	
	while(true){
		printf("%");
	}
};