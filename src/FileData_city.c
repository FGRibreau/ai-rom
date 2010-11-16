
#include "FileData_city.h"


pFileData_city FileData_city_create(pFileData_city parent, pCity city, int dist, int depth){
	pFileData_city obj = Stack_push(&__FileData_city_malloc, _malloc(sizeof(FileData_city)));
	obj->parent = parent;
	obj->dist = dist;
	obj->city = city;
	obj->depth = depth;
	return obj;
}

void FileData_cityFree(){
	Stack_free(__FileData_city_malloc);
}

pFileData_city FileData_city_append(pFileData_city route, pBranch branch){
	return FileData_city_create(route, branch->city, route->dist + branch->dist, route->depth+1);
}

pFileData_city FileData_city_appendASC(pFileData_city route, pBranch branch, float dist){
	return FileData_city_create(route, branch->city, route->dist + branch->dist + dist, route->depth+1);
}

bool FileData_cityAlreadyExist(pFileData_city route, pCity city){
	
	do {
		if(route->city == city){
			return true;
		}
	} while (route = route->parent);
		   
	return false;
}

void FileData_printRoute(pFileData_city route){
	if(route == NULL){
		printf("Aucune route trouvée");
		return;
	}
	
	pFileData_city h = route;
	
	bstring b = bfromcstr("");
	bstring a;
	do {
		a = bformat("%s", route->city->name);
		bconcat(a, b);
		b = a;
		
		if(route->parent != NULL){
			a = bfromcstr(" -> ");
			bconcat(a, b);
			b = a;
		}
	} while (route = route->parent);
	
	
	printf("(%dkm, %d étapes) %s\n", h->dist, h->depth, bstr2cstr(b, '\0'));
	
	bdestroy(b);
	bdestroy(a);
}

//Ajoute un élément à la file (et trie la file du plus petit au plus grand
//Ajout un élément dans la file
void FileData_city_pushASC(pFile* file, pFileData_city data){
	
	pFile node = _malloc (sizeof (File))
		, cursor = *file;
	
	node->data = data;
	node->prev = NULL;
	node->next = NULL;
	

	if(File_isEmpty(*file)){//file vide
		*file = node;
	} else {
		
		pFile t = NULL;
		
		while(cursor != NULL 
		&&	((pFileData_city)cursor->data)->dist > data->dist){
			t = cursor;
			cursor = cursor->next;
		}
		
		if(t != NULL){
            node->next = t->next;
            t->next = node;
        } else {
            node->next = *file;
            *file = node;
        }
		
	}
	
	return;
}

/*void FileData_city_pushASC(pFile* file, void* data){
    if(file == NULL) {
        file = malloc(sizeof(TNoeud));
        f->debut->elem = e;
        f->debut->nextElem = NULL;
		File_push(file, <#void *data#>)
    } else {
        TNoeud* nPrec = NULL;
        TNoeud* n = f->debut;
        while(n != NULL && n->elem.coutChemin < e.coutChemin){
            nPrec = n;
            n = (TNoeud*)n->nextElem;
        }
        TNoeud* new = malloc(sizeof(TNoeud));
        new->elem = e;
		
        if(nPrec!=NULL){
            new->nextElem = nPrec->nextElem;
            nPrec->nextElem = (pTNoeud)new;
        } else {
            new->nextElem = f->debut;
            f->debut = (pTNoeud)new;
        }
    }
}*/
