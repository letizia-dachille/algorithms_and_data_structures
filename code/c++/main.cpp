#include <iostream>
#include <fstream> 		
#include <vector>
#include <string>	
#include <algorithm>
#include <iomanip>

//numero corrispondente ad ultimo nodo + 1																		
const int nnode = 27560;

//numero di righe dei rispettivi documenti
const int routes_walk = 252588; 
const int routes_combined = 14782;
const int trips_count = 1823873;
const int nodes_count = 11951; 

//mezzanotte del giorno considerato (Lunedì 12/12/2016)
const int zero_day = 1481500800;																								 			

//inizializzazione variabili globali
int start, arrival, start_time, max_time;	

#include "graph.cpp"
#include "inverse_search.cpp"
#include "input.cpp"
#include "dijkstra_functions.cpp"
#include "dijkstra.cpp"
#include "output.cpp"

using namespace std;

int main(){

	//costruzione grafo
	graph g;
	build_graph(&g);

	//inizializzazione array utilizzati in dijkstra
	int prec[nnode];			//nodo precedente nel percorso più breve
	int time[nnode];			//tempo impiegato per arrivare al nodo considerato
	int arrival_time[nnode];	//orario di arrivo al nodo considerato
	int departure_time[nnode];	//orario di partenza dal nodo precedente
	int mean_type[nnode];		//tipo di mezzo utilizzato per arrivare dal nodo precedente
	int mean_number[nnode];		//numero del mezzo utilizzato (come sopra)

	//input
	input();

	//dijkstra
	dijkstra(&g, prec, time, arrival_time, departure_time, mean_type, mean_number);

	//output
	output(&g, prec, time, arrival_time, departure_time, mean_type, mean_number);
	
	return 0;
}