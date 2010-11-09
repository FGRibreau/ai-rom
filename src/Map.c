
#include "Map.h"

pHash _Map;
void Map_init(){
	_Map = Hash_create();
}

pCity Map_get(char* index){
	return (pCity)Hash_get(&_Map, index);
}

void Map_set(char* index, pCity city){
	Hash_set(&_Map, index, city);
}
