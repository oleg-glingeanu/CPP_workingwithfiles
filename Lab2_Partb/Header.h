#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int textfileTask(string names[5], int goal_int[5]) {

	//open file for writing
	fstream f("scores.txt", ios::in);
	string line;
	string goals[5];

	if (f.is_open()) {
		string name;
		string goal;

		// Names assigned into an array
		int name_index = 0;
		for (int i = 0; i < 10; i ++) {
			if (i % 2 == 0) {
				getline(f, name);
				names[name_index] = name;
				name_index++;
			}else {
				getline(f, name);
			}
		}
		f.close();

		// Goals assigned in an array
		fstream f("scores.txt", ios::in);
		int goal_index = 0;
		for (int i = 0; i < 10; i++) {
			if (i % 2 != 0) {
				int x;
				getline(f, goal);
				goals[goal_index] = goal;
				istringstream(goals[goal_index]) >> x;
				goal_int[goal_index] = x;
				goal_index++;

			}else {
				getline(f, goal);
			}
		}
	}

	// Outputting the Names and Goals
	cout << "NAMES: ";
	for (int i = 0; i < 5; i++) {
		cout << names[i] << ", ";
		if (i == 4) {
			cout << names[i] << " ";
		}
	}
	cout << endl;
	cout << "GOALS: ";
	for (int i = 0; i < 5; i++) {
		cout << goal_int[i] << ", ";
		if (i == 4) {
			cout << goal_int[i] << " ";
		}
	}
	
	cout << endl;
	cout << endl;

	// Making goals and names into a descending order array
	int desc_order[5];
	string name_desc_order[5];
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 5; j++) {
			if (goal_int[i] < goal_int[j]) {
				desc_order[i] = goal_int[i];
				name_desc_order[i] = names[i];
				goal_int[i] = goal_int[j];
				names[i] = names[j];
				goal_int[j] = desc_order[i];
				names[j] = name_desc_order[i];
			}
		}
	}
	
	// Outputting the names and goals
	cout << "==TOP 3 PLAYERS==" << endl;
	for (int i = 0; i < 3; i++) {
		cout << "NUMBER " << i + 1 << " Player is : " << names[i] << " With " << goal_int[i] << " Goals" << endl;
	}
	
	return 0;
}