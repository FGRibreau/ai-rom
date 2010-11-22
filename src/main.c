#include <stdio.h>
#include "env.h"
#include "Map.h"
#include "City.h"
#include "Branch.h"
#include "Search/SearchWidth.h"
#include "Search/SearchWidth_withAllReachedRoad.h"
#include "Search/SearchDepth.h"
#include "Search/SearchGreedy.h"
#include "Search/SearchAStar.h"


int main (int argc, const char * argv[]) {
	
	Map_init();//Initialise le Hash (une carte des villes accessibles via leurs noms)

	//Création des villes, et ajout dans la carte
	Map_set("Arad",			City_create("Arad", 46.180260, 21.323219));
	Map_set("Zerind",		City_create("Zerind", 46.623699, 21.516701));
	Map_set("Oradea",		City_create("Oradea", 47.052059, 21.938730));
	Map_set("Sibiu",		City_create("Sibiu", 44.416698, 44.416698));
	Map_set("Timisoara",	City_create("Timisoara", 45.753422, 21.223270));
	Map_set("Lugoj",		City_create("Lugoj", 45.684818, 21.905741));
	Map_set("Mehadia",		City_create("Mehadia", 44.900002, 22.366699));
	Map_set("Dobreta",		City_create("Dobreta", 44.474201, 23.957600));
	Map_set("Craiova",		City_create("Craiova", 44.318871, 23.801720));
	Map_set("Pitesti",		City_create("Pitesti", 44.850979, 24.879770));
	Map_set("Fagaras",		City_create("Fagaras", 45.842991, 24.976259));
	Map_set("RimnicuViclea", City_create("RimnicuViclea", 45.946949, 24.980400));
	Map_set("Bucarest",		City_create("Bucarest", 44.434200, 26.102970));
	Map_set("Giurgiu",		City_create("Giurgiu", 43.895939, 25.966650));
	Map_set("Urziceni",		City_create("Urziceni", 44.718102, 26.645300));
	Map_set("Hirsova",		City_create("Hirsova", 44.694881, 27.956369));
	Map_set("Eforie",		City_create("Eforie", 44.066700, 28.633301));
	Map_set("Vaslui",		City_create("Vaslui", 46.638069, 27.732821));
	Map_set("Lasi",			City_create("Lasi", 45.946949, 24.980400));
	Map_set("Neamt",		City_create("Neamt", 46.989780, 26.450090));
	
	/*
	 Donnée "prof":
	Map_set("Arad",			City_create("Arad", 366));
	Map_set("Zerind",		City_create("Zerind", 374));
	Map_set("Oradea",		City_create("Oradea", 380));
	Map_set("Sibiu",		City_create("Sibiu", 253));
	Map_set("Timisoara",	City_create("Timisoara", 329));
	Map_set("Lugoj",		City_create("Lugoj", 244));
	Map_set("Mehadia",		City_create("Mehadia", 241));
	Map_set("Dobreta",		City_create("Dobreta", 242));
	Map_set("Craiova",		City_create("Craiova", 160));
	Map_set("Pitesti",		City_create("Pitesti", 100));
	Map_set("Fagaras",		City_create("Fagaras", 176));
	Map_set("RimnicuViclea", City_create("RimnicuViclea", 193));
	Map_set("Bucarest",		City_create("Bucarest", 0));
	Map_set("Giurgiu",		City_create("Giurgiu", 77));
	Map_set("Urziceni",		City_create("Urziceni", 80));
	Map_set("Hirsova",		City_create("Hirsova", 151));
	Map_set("Eforie",		City_create("Eforie", 161));
	Map_set("Vaslui",		City_create("Vaslui", 199));
	Map_set("Lasi",			City_create("Lasi", 226));
	Map_set("Neamt",		City_create("Neamt", 234));
	*/
	
	
	//Création des liens entre les villes
	City_branchLink(Map_get("Arad"), Map_get("Zerind"), 75);
	City_branchLink(Map_get("Arad"), Map_get("Sibiu"), 140);
	City_branchLink(Map_get("Arad"), Map_get("Timisoara"), 118);
	
	City_branchLink(Map_get("Zerind"), Map_get("Oradea"), 71);
	
	City_branchLink(Map_get("Oradea"), Map_get("Sibiu"), 151);
	
	City_branchLink(Map_get("Timisoara"), Map_get("Lugoj"), 111);
	
	City_branchLink(Map_get("Lugoj"), Map_get("Mehadia"), 70);
	
	City_branchLink(Map_get("Mehadia"), Map_get("Dobreta"), 75);
	
	City_branchLink(Map_get("Dobreta"), Map_get("Craiova"), 120);
	
	City_branchLink(Map_get("Craiova"), Map_get("Pitesti"), 138);
	City_branchLink(Map_get("Craiova"), Map_get("RimnicuViclea"), 146);
	
	City_branchLink(Map_get("RimnicuViclea"), Map_get("Sibiu"), 80);
	City_branchLink(Map_get("RimnicuViclea"), Map_get("Pitesti"), 97);
	
	//City_branchLink(Map_get("Sibiu"), Map_get("Oradea"), 151);//Cette ligne génère une erreur car ce lien existe déjà
	
	City_branchLink(Map_get("Sibiu"), Map_get("Fagaras"), 99);
	
	City_branchLink(Map_get("Fagaras"), Map_get("Bucarest"), 211);
	City_branchLink(Map_get("Pitesti"), Map_get("Bucarest"), 101);
	
	City_branchLink(Map_get("Bucarest"), Map_get("Giurgiu"), 90);
	
	City_branchLink(Map_get("Bucarest"), Map_get("Urziceni"), 85);
	
	City_branchLink(Map_get("Urziceni"), Map_get("Hirsova"), 98);
	City_branchLink(Map_get("Urziceni"), Map_get("Vaslui"), 142);
	
	City_branchLink(Map_get("Hirsova"), Map_get("Eforie"), 86);
	
	City_branchLink(Map_get("Vaslui"), Map_get("Lasi"), 92);
	
	City_branchLink(Map_get("Lasi"), Map_get("Neamt"), 87);
	
	
	//Lancement des algorithmes de recherche
	printf("\nRecherche en largeur:\n");
	FileData_printRoute(SearchWidth(Map_get("Arad"), Map_get("Bucarest")));
	
	printf("\nRecherche en profondeur:\n");
	FileData_printRoute(SearchDepth(Map_get("Arad"), Map_get("Bucarest")));
	
	printf("\nRecherche via Greedy:\n");
	FileData_printRoute(SearchGreedy(Map_get("Arad"), Map_get("Bucarest")));
	
	printf("\nRecherche en AStar: (Affichage des routes arrivant à destination)\n");
	FileData_printRoute(SearchAStar(Map_get("Arad"), Map_get("Bucarest")));
	printf("\t ---> Chemin retenu <---\n");

	
	//Search_defCon1(Map_get("Arad"), Map_get("Bucarest"));
	
	
	//Branch_free();		//Libères les branchs
	Map_free();			//Libères les villes
	FileData_cityFree();//Libères les routes (trouvées par les algorithmes)

	//Affiche le résultat des mallocs/frees
	_printMalloc();
	
	return 0;
}
