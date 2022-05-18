using namespace std;

string unix_minutes(int time){
	int minutes = (((time - time % 60) / 60) % 60);
	if (minutes >= 10){
		return to_string(minutes);
	}
	else{
		return ('0' + to_string(minutes));
	}
}

string unix_hours(int time){
	int hour = (((time - time % 3600) / 3600));
	if (hour >= 10){
		return to_string(hour);
	}
	else{
		return ('0' + to_string(hour));
	}
}

//utilizzata per non dover specificare il numero del mezzo nel caso di un percorso a piedi
string check_mean(int mean_number){
	if (mean_number == -1){
		return("---");
	} 
	else{
		return(to_string(mean_number));
	}
}

//template per output
void print_element(string s, int width){
	cout << left << setw(width) << setfill(' ') << s;
}

void output(graph* g, int* prec, int* time, int* arrival_time, int* departure_time, int* mean_type, int* mean_number){
	if (prec[arrival] == -1){
		cout << "Nessuna strada disponibile" << endl; 
	}
	else {
		cout << "Tempo totale di percorrenza: " << unix_hours(time[arrival]) << " h " << unix_minutes(time[arrival]) << " min" << endl;
		cout << endl;
		
		int c = 0;
		vector<int> list_nodes, list_arr_time, list_dep_time, list_mean_type, list_mean_number;

		while (arrival != start){
			list_nodes.insert(list_nodes.begin(), arrival);
			list_arr_time.insert(list_arr_time.begin(), arrival_time[arrival]);
			list_dep_time.insert(list_dep_time.begin(), departure_time[arrival]);
			list_mean_type.insert(list_mean_type.begin(), mean_type[arrival]);
			list_mean_number.insert(list_mean_number.begin(), mean_number[arrival]);

			arrival = prec[arrival];
			c++;
		}	

		list_nodes.insert(list_nodes.begin(), start);
		list_arr_time.insert(list_arr_time.begin(), start_time);

		//Costruzione tabella di output

		//lunghezza massima nomi delle fermate, trovato 61, e aggiunto 8 per inserire il numero
		int w1 = 69;
		int w2 = 20, w3 = 20, w4 = 20, w5 = 20;

		print_element("Stop", w1);
		print_element("| Arrival time", w2);
		print_element("| Departure time", w3);
		print_element("| Mean type", w4);
		print_element("| Mean number", w5);
		cout << endl;

		cout << left << setw(w1) << setfill('-') << "-";
		cout << left << setw(w2) << setfill('-') << "|";
		cout << left << setw(w3) << setfill('-') << "|";
		cout << left << setw(w4) << setfill('-') << "|";
		cout << left << setw(w5) << setfill('-') << "|";
		cout << endl;

		print_element(search_stop_output(list_nodes[0]), w1);
		print_element("| ---", w2);
		print_element("| " + unix_hours(list_dep_time[0] - zero_day) + ":" + unix_minutes(list_dep_time[0] - zero_day), w3);
		print_element("| " + mean_search(list_mean_type[0]), w4);
		print_element("| " + check_mean(list_mean_number[0]), w5);
		cout << endl;

		for(int i=1; i < c; i++){
			print_element(search_stop_output(list_nodes[i]), w1);
			print_element("| " + unix_hours(list_arr_time[i] - zero_day) + ":" + unix_minutes(list_arr_time[i] - zero_day), w2);
			print_element("| " + unix_hours(list_dep_time[i] - zero_day) + ":" + unix_minutes(list_dep_time[i] - zero_day), w3);
			print_element("| " + mean_search(list_mean_type[i]), w4);
			print_element("| " + check_mean(list_mean_number[i]), w5);
			cout << endl;
		}

		print_element(search_stop_output(list_nodes[c]), w1);
		print_element("| " + unix_hours(list_arr_time[c] - zero_day) + ":" + unix_minutes(list_arr_time[c] - zero_day), w2);
		print_element("| ---", w3);
		print_element("| ---", w4);
		print_element("| ---", w5);
		cout << endl;

		cout << endl;		
	}
	return;
}