using namespace std;

void dijkstra(graph* g, int* prec, int* time, int* arrival_time, int* departure_time, int* mean_type, int* mean_number){

	//la prima colonna contiene il numero del nodo, la seconda la distanza dalla sorgente
	int heap[nnode][2]; 

	int posheap[nnode];

	//weight[0]=arrival_time al nodo
	//weight[1]=departure_time dal nodo precedente
	//weight[2]=mean_type utilizzato per arrivare dal nodo precedente
	//weight[3]=mean_number utilizzato per arrivare dal nodo precedente
	//usato insieme ai relativi array per salvare informazioni utili per ricostruire il percorso al momento dell'output
	int weight[4];

	int pop, v, size = 0;

	for (int i=1; i < nnode; i++){
		prec[i] = -1; 
		arrival_time[i] = -1; 
		time[i] = max_time;
	}

	prec[start] = start;
	arrival_time[start] = start_time;
	time[start] = 0;

	for (int i=1; i < nnode; i++){
		size = enqueue(heap, posheap, size, time[i], i);
	}

	while (size > 0){
		pop = dequeue(heap, posheap, size);
		size--;

		if (pop == arrival){

			//break quando il nodo di arrivo viene tolto dalla coda (percorso per tale nodo
			//non può più migliorare dopo questo punto dell'algoritmo)
			break;
		}

		for(routes r : (*g).adj[pop]){
			v = r.arrival;
			weight_computation(&r, arrival_time[pop], weight);

			if (time[v] > time[pop] + weight[0]){
				time[v] = time[pop] + weight[0];
				prec[v] = pop;
				arrival_time[v] = start_time + time[v];
				departure_time[v] = weight[1];
				mean_type[v] = weight[2];
				mean_number[v] = weight[3];

				if (v == arrival && time[arrival] < max_time){ 

					//break quando trova un percorso che rispetta il tempo massimo
					//di percorrenza
					break;
				}
				
				decrease_key(heap, posheap, size, v, time[v]);
			}
		}

		if (v == arrival && time[arrival] < max_time){ 

			//break quando trova un percorso che rispetta il tempo massimo
			//di percorrenza
			break;
		}
	}
	return;
}