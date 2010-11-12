
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