

#ifndef _HASHCITY_H
#define _HASHCITY_H
#include "env.h"
#include "City.h"
#include "Hash.h"


pHash _Map;
void	Map_init();
pCity	Map_get(char* index);
void	Map_set(char* index, pCity city);

#endif