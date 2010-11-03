#include "City.h"
typedef enum{false,true}bool;

int main (int argc, const char * argv[]) {
	 	
	/*---------INITIALISATION----------*/
	pCity Arad = cityCreate("Arad");
	pCity Zerind = cityCreate("Zerind");
	pCity Oradea = cityCreate("Oradea");
	pCity Siblu = cityCreate("Siblu");
	pCity Timisoara = cityCreate("Timisoara");
	pCity Lugoj = cityCreate("Lugoj");
	pCity Mehadia = cityCreate("Mehadia");
	pCity Dobreta = cityCreate("Dobreta");
	pCity Craiova = cityCreate("Craiova");
	pCity Pitesti = cityCreate("Pitesti");
	pCity Fagaras = cityCreate("Fagaras");
	pCity Bucarest = cityCreate("Bucarest");
	/*-------------------------------------*/

	city_branchLink(Arad, Zerind, 75);
	city_branchLink(Arad, Siblu, 140);
	city_branchLink(Arad, Timisoara, 118);
	
	
	
	printf("Hello %s \n", Arad->name);
	/*--------------DESTRUCTION------------*/
	
	cityDestroy(Arad);
	
	return 0;
}
