#include "City.h"
#include "Branch.h"
#include "Search/SearchWidth.h"
#include "Search/SearchDepth.h"

#include "Search/SearchWidth_withAllReachedRoad.h"
#include <stdio.h>


int main (int argc, const char * argv[]) {
	
	/*Instanciation des villes*/
	
	//417 KM
	pCity Arad = City_create("Arad", 46.180260, 21.323219); //CityName, x, y
	pCity Zerind = City_create("Zerind", 46.623699, 21.516701);
	pCity Oradea = City_create("Oradea", 47.052059, 21.938730);
	pCity Siblu = City_create("Siblu", 44.416698, 44.416698);
	pCity Timisoara = City_create("Timisoara", 45.753422, 21.223270);
	pCity Lugoj = City_create("Lugoj", 45.684818, 21.905741);
	pCity Mehadia = City_create("Mehadia", 44.900002, 22.366699);
	pCity Dobreta = City_create("Dobreta", 44.474201, 23.957600);
	pCity Craiova = City_create("Craiova", 44.318871, 23.801720);
	pCity Pitesti = City_create("Pitesti", 44.850979, 24.879770);
	pCity Fagaras = City_create("Fagaras", 45.842991, 24.976259);
	pCity RimnicuViclea = City_create("RimnicuViclea", 45.946949, 24.980400);
	pCity Bucarest = City_create("Bucarest", 44.434200, 26.102970);
	pCity Giurgiu = City_create("Giurgiu", 43.895939, 25.966650);
	pCity Urziceni = City_create("Urziceni", 44.718102, 26.645300);
	pCity Hirsova = City_create("Hirsova", 44.694881, 27.956369);
	pCity Eforie = City_create("Eforie", 44.066700, 28.633301);
	pCity Vaslui = City_create("Vaslui", 46.638069, 27.732821);
	pCity Lasi = City_create("Lasi", 45.946949, 24.980400);
	pCity Neamt = City_create("Neamt", 46.989780, 26.450090);
	
	//sqrt( (x1 - x0)^2 + (y1 - y2)^2))
	
	printf("-- %f --\n", City_distBtw(Arad, Bucarest));
	printf("-- %f --\n", City_distBtw(Zerind, Bucarest));
	
	//TODO: Insérer toutes les villes dans une collection de ville
	//CityCollection_push(&CityCollection, City_create("Neamt"));
	//CityCollection_getCityByName(&CityCollection,"Neamt");
	
	//Création des liens entre les villes
	City_branchLink(Arad, Zerind, 75);
	City_branchLink(Arad, Siblu, 140);
	City_branchLink(Arad, Timisoara, 118);
	
	City_branchLink(Zerind, Oradea, 71);
	
	City_branchLink(Oradea, Siblu, 151);
	
	City_branchLink(Timisoara, Lugoj, 111);
	
	City_branchLink(Lugoj, Mehadia, 70);
	
	City_branchLink(Mehadia, Dobreta, 75);
	
	City_branchLink(Dobreta, Craiova, 120);
	
	City_branchLink(Craiova, Pitesti, 138);
	City_branchLink(Craiova, RimnicuViclea, 146);
	
	City_branchLink(RimnicuViclea, Siblu, 80);
	City_branchLink(RimnicuViclea, Pitesti, 97);
	
	//City_branchLink(Siblu, Oradea, 151);//Cette ligne génère une erreur car ce lien existe déjà
	
	City_branchLink(Siblu, Fagaras, 99);
	
	City_branchLink(Fagaras, Bucarest, 211);
	City_branchLink(Pitesti, Bucarest, 101);
	
	City_branchLink(Bucarest, Giurgiu, 90);
	
	City_branchLink(Bucarest, Urziceni, 85);
	
	City_branchLink(Urziceni, Hirsova, 98);
	City_branchLink(Urziceni, Vaslui, 142);
	
	City_branchLink(Hirsova, Eforie, 86);
	
	City_branchLink(Vaslui, Lasi, 92);
	
	City_branchLink(Lasi, Neamt, 87);
	
	
	//Lancement des algorithmes de recherche
	//printf("\nRecherche en largeur:\n");
	//FileData_printRoute(SearchWidth(Bucarest, Arad));
	
	//printf("\nRecherche en profondeur:\n");
	//FileData_printRoute(SearchDepth(Arad, Bucarest));
	
	printf("\nRecherche en AStar:\n");
	FileData_printRoute(SearchDepth(Arad, Bucarest));
	
	Search_defCon1(Arad,Bucarest);
	
	//Free all pCity
	//City_destroy();
	
	return 0;
}
