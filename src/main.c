#include "City.h"
#include "Misc.h"
#include "Search/SearchWidth_withAllReachedRoad.h"
#include "Search/SearchWidth.h"
#include "Search/SearchDepth.h"

int main (int argc, const char * argv[]) {
	
	//Instanciation des villes
	pCity Arad = City_create("Arad");
	pCity Zerind = City_create("Zerind");
	pCity Oradea = City_create("Oradea");
	pCity Siblu = City_create("Siblu");
	pCity Timisoara = City_create("Timisoara");
	pCity Lugoj = City_create("Lugoj");
	pCity Mehadia = City_create("Mehadia");
	pCity Dobreta = City_create("Dobreta");
	pCity Craiova = City_create("Craiova");
	pCity Pitesti = City_create("Pitesti");
	pCity Fagaras = City_create("Fagaras");
	pCity RimnicuViclea = City_create("RimnicuViclea");
	pCity Bucarest = City_create("Bucarest");
	pCity Giurgiu = City_create("Giurgiu");
	pCity Urziceni = City_create("Urziceni");
	pCity Hirsova = City_create("Hirsova");
	pCity Eforie = City_create("Eforie");
	pCity Vaslui = City_create("Vaslui");
	pCity Lasi = City_create("Lasi");
	pCity Neamt = City_create("Neamt");
	
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
	printf("\nRecherche en largeur:\n");
	FileData_printRoute(SearchWidth(Arad, Bucarest));
	
	printf("\nRecherche en profondeur:\n");
	FileData_printRoute(SearchDepth(Arad, Bucarest));
	
	//Erase all pCity
	//City_destroy();
	
	return 0;
}
