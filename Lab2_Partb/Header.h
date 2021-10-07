#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void textfileTask(int a[], int b[]) {

	//open file for writing
	fstream f("scores.txt", ios::in);
	string line;
	string names[5];
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

				getline(f, goal);
				goals[goal_index] = goal;
				goal_index++;
			}else {
				getline(f, goal);
			}
		}
	}


	// Outputting the Names and Goals
	cout << "NAMES : ";
	for (auto v : names) {
		cout << v << ", ";
	}
	cout << endl;
	cout << "GOALS : ";
	for (auto v : goals) {
		cout << v << ", ";
	}

	a[0] = 1;
	a[1] = 2;
	for (auto v : a) {
		cout << v << ", ";
	}

}