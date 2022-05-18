using namespace std;

int search_stop_input(int node){
	string line, semicolon = ";";
	int id;

	ifstream file("../../paris/original/network_nodes.csv");
	getline (file, line);

    for (int i=2; i <= nodes_count ; i++){
		getline (file, line);

		id = intsubstring(line);

		if (id == node){
			break;
		}
		if (id > node || node > 27560){
			return 0;
		}
	}

	line = nextinline(nextinline(nextinline(line)));

	string stop((line.substr(0, line.find(semicolon))).c_str()); 	//da stringa c a stringa c++
	transform(stop.begin(), stop.end(), stop.begin(), ::tolower);	//per lower case 
	stop[0] = toupper(stop[0]);										//e prima lettera upper case

	cout << "  The chosen stop is: " << stop << endl;

	file.close();
	return 1;
}

string search_stop_output(int node){
	string line, semicolon = ";";
	int id;

	ifstream file("../../paris/original/network_nodes.csv");
	getline (file, line);

    for (int i=2; i <= nodes_count ; i++){
		getline (file, line);

		id = intsubstring(line);

		if (id == node){
			break;
		}
	}

	line = nextinline(nextinline(nextinline(line)));

	string stop((line.substr(0, line.find(semicolon))).c_str()); 	//da stringa c a stringa c++
	transform(stop.begin(), stop.end(), stop.begin(), ::tolower);	//per lower case 
	stop[0] = toupper(stop[0]);										//e prima lettera upper case

	stop = stop + " (" + to_string(id) + ")";						//inserisce numero fermata per output

	file.close();
	return stop;
}

string mean_search(int type){
	string mean;
	switch (type){
		case -1:
		mean = "Walk";
		break;
		case 0:
		mean = "Tram";
		break;
		case 1:
		mean = "Underground";
		break;
		case 2:
		mean = "Train";
		break;
		case 3:
		mean = "Bus";
		break;
		case 4:
		mean = "Ferry";
		break;
		case 5:
		mean = "Cablecar";
		break;
		case 6:
		mean = "Gondola";
		break;
		case 7:
		mean = "Funicular";
		break;
	}
	return mean;
}