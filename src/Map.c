
#include "Map.h"

pHash _Map;
inline	void Map_init(){
	_Map = Hash_create();
}

pCity Map_get(char* index){
	return (pCity)Hash_get((pHash)&_Map, index);
}

void Map_set(char* index, pCity city){
	Hash_set(&_Map, index, city);
}

void Map_free(){
	void __callback(char* index, void* data, pHash hash){
		_free(((pCity)data)->name);
	}
	
	Hash_forEach(_Map, __callback);
	Hash_free(_Map);
}