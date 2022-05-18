using namespace std;

//Definizioni classi per la costruzione del grafo

class routes{
	public:
		int arrival;
		int mean_type;
		int distance;
		vector<int> dep_time;
		vector<int> arr_time;
		vector<int> mean_number;
};

class graph{
	public:
		vector<routes> adj[nnode];
};

//Funzioni

int intsubstring(string line){
	string semicolon = ";";
	return(atoi((line.substr(0, line.find(semicolon))).c_str()));
}

string nextinline(string line){
	string semicolon = ";";
	return(line.substr(line.find(semicolon) + 1));
}

//Caricamento network_combined

void load_file_1(graph* g){
	string line;
	int start, arrival, type, distance; 
	routes r;

	ifstream file_1("../../paris/ordered/network_combined_sorted.csv");

    getline (file_1, line);

    for (int i=2; i <= routes_combined ; i++){
		getline (file_1, line);

		start = intsubstring(line);
		line = nextinline(line);
		arrival = intsubstring(line);
		line = nextinline(line);
		distance = intsubstring(line);

		for (int j=1; j <= 4 ; j++){
			line = nextinline(line);
		}
		type = intsubstring(line);

		r.arrival = arrival;
		r.mean_type = type;
		r.distance = distance;

		(*g).adj[start].push_back(r);
	}

	file_1.close();
}

//Caricamento network_walk 

void load_file_2(graph* g){
	string line;
	int start, arrival, distance;
	routes r;

	ifstream file_2("../../paris/ordered/network_walk_sorted.csv");

	getline (file_2, line);

    for (int i=2; i <= routes_walk ; i++){
		getline (file_2, line);

		start = intsubstring(line);
		line = nextinline(line);
		arrival = intsubstring(line);
		line = nextinline(nextinline(line));
		distance = intsubstring(line);

		r.arrival = arrival;
		r.mean_type = -1;		
		r.distance = distance;

		(*g).adj[start].push_back(r);

		r.arrival = start;

		(*g).adj[arrival].push_back(r);
	}

	file_2.close();
}

//Caricamento network_temporal_day

void load_file_3(graph* g){
	string line;
	int start, arrival, type, departure_time, arrival_time, mean_number, new_start, new_arrival, new_type;

	ifstream file_3("../../paris/ordered/network_temporal_day_sorted.csv");

	getline (file_3, line);
    getline (file_3, line);
	start = intsubstring(line);
	line = nextinline(line);
	arrival = intsubstring(line);
	line = nextinline(line);
	departure_time = intsubstring(line);
	line = nextinline(line);
	arrival_time = intsubstring(line);
	line = nextinline(line);
	type = intsubstring(line);
	line = nextinline(nextinline(nextinline(line)));
	mean_number = intsubstring(line);

	int c = 0;

    for (int i=2; i <= trips_count ; i++){
    	((*g).adj[start])[c].dep_time.push_back(departure_time); 
    	((*g).adj[start])[c].arr_time.push_back(arrival_time);
    	((*g).adj[start])[c].mean_number.push_back(mean_number);

    	getline (file_3, line);
    	new_start = intsubstring(line);
		line = nextinline(line);
		new_arrival = intsubstring(line);
		line = nextinline(line);
		departure_time = intsubstring(line);
		line = nextinline(line);
		arrival_time = intsubstring(line);
		line = nextinline(line);
		new_type = intsubstring(line);
		line = nextinline(nextinline(nextinline(line)));
		mean_number = intsubstring(line);

		if (new_arrival != arrival || new_type != type){ 
			c++;
			arrival = new_arrival;
			type = new_type;
		}

		if (new_start > start){
			c=0;
			start = new_start;
		}

    }

    file_3.close();
}

//Costruzione grafo

void build_graph(graph* g){
	load_file_1(g);
	load_file_2(g);
	load_file_3(g);
	return;
}