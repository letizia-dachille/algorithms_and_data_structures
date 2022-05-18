using namespace std;

void input(){
	int hour, minutes, flag = 0;
	char colon;

	cout << endl;

	while (flag == 0){
		cout << "- Insert start point: ";
		cin >> start;
		flag = search_stop_input(start);
		if (flag == 1){
			cout << "  Confirm? [0 - no, 1 - yes] - ";
			cin >> flag;
		}
		else{
			cout << "  Node not found" << endl;
		}
	}

	cout << endl;
	flag = 0;

	while (flag == 0){
		cout << "- Insert arrival point: ";
		cin >> arrival;
		flag = search_stop_input(arrival);
		if (flag == 1){
			cout << "  Confirm? [0 - no, 1 - yes] - ";
			cin >> flag;
		}
		else{
			cout << "  Node not found" << endl;
		}
	}

	cout << endl;

	cout << "- Insert start time (hh:mm): ";
	cin >> hour >> colon >> minutes;
	start_time = hour * 3600 + minutes * 60 + zero_day;

	cout << "- Insert max duration (hh:mm - max 24:00): ";
	cin >> hour >> colon >> minutes;
	max_time = hour * 3600 + minutes * 60;

	cout << endl << endl;
}