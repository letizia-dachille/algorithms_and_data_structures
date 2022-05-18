using namespace std;

void exchange(int heap[][2], int posheap[], int i, int j){
	int aux;

	aux = heap[i][0];
	heap[i][0] = heap[j][0];
	heap[j][0] = aux;

	aux = heap[i][1];
	heap[i][1] = heap[j][1];
	heap[j][1] = aux;

	posheap[heap[i][0]] = i;
	posheap[heap[j][0]] = j;

	return;
}

int father(int node){
	int f = (node - 1)/2;
	return f;
}

int left(int node){
	int l = 2 * node + 1;
	return l;
}

int right(int node){
	int r = 2 * node + 2;
	return r;
}

int worst(int heap[][2], int size, int place){
	if (heap[place][1] < heap[left(place)][1]){
		if (right(place) < size){
			if (heap[place][1] < heap[right(place)][1]){
				return place;
			}
			else{
				return right(place);
			}
		}
		else{
			return place;
		}
	}
	else{
		if (right(place) < size){
			if (heap[left(place)][1] < heap[right(place)][1]){
				return left(place);
			}
			else{
				return right(place);
			}
		}
		else{
			return left(place);
		}
	}
}

void organize_heap(int heap[][2], int posheap[], int place, int size){
	
	while (place > 0 && heap[place][1] < heap[father(place)][1]){
		exchange(heap, posheap, place, father(place));
		place = father(place);
	}

	int w;
	while (left(place) < size && place != worst(heap, size, place)){
		w = worst(heap, size, place);
		exchange(heap, posheap, place, w);
		place = w;
	}
}

void decrease_key(int heap[][2], int posheap[], int size, int place, int time){
	int place_position = posheap[place];
	heap[place_position][1] = time;
	organize_heap(heap, posheap, place_position, size);
	return;
}

int dequeue(int heap[][2], int posheap[], int size){
	if (size > 0){
		int min = heap[0][0];
		heap[0][1] = heap[size - 1][1];
		heap[0][0] = heap[size - 1][0];
		size--;
		posheap[heap[0][0]] = 0;
		organize_heap(heap, posheap, 0, size);
		return min;
	}
	return 0;
}

int enqueue(int heap[][2], int posheap[], int size, int time, int i){
	heap[size][0] = i;
	heap[size][1] = time;
	posheap[i] = size;
	organize_heap(heap, posheap, size, size + 1);
	return size + 1;
}

void weight_computation(routes* r, int arrival_time, int* weight){
	if (!(*r).arr_time.empty()){
		
		int c = -1;

		for (int i : (*r).dep_time){
			c++;
			if (arrival_time <= i){
				break;
			}
		}

		weight[0] = (*r).arr_time[c] - arrival_time;
		weight[1] = (*r).dep_time[c];
		weight[2] = (*r).mean_type;
		weight[3] = (*r).mean_number[c];
		if (weight[0] < 0){
			weight[0] = max_time;
		}
	}
	else{
		//distanza va moltiplicata per 0.8 per tempo di percorrenza a piedi in secondi
		weight[0] = (*r).distance * 0.8;
		weight[1] = arrival_time;
		weight[2] = -1;
		weight[3] = -1;
	}

	return;
}