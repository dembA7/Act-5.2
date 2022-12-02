// =================================================================
//
// File: main.cpp
// Author 1: Arturo Diaz
// Author 2: Pablo Javier Arreola Velasco
// Author 3: Erik Cabrera Gonzalez
// Date: 01/12/22
//
// =================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main(int argc, char* argv[]) {
	
	ifstream inputFile;
	ofstream outputFile;

	inputFile.open(argv[1]);
	if (inputFile.fail()){
		cout << "Error opening file" << endl;
		return 1;
	}

	outputFile.open(argv[2]);
	if (outputFile.fail()){
		cout << "Error opening file" << endl;
		return 1;
	}

	int j, p;
	inputFile >> j >> p;

	string job;
	int salary = 0;

// =================================================================
// Definition of the Hash Table
// =================================================================
  
	map<string, int> salaries;

	for (int i = 0; i < j; i++){
		inputFile >> job >> salary;
		salaries[job] = salary;
	}

	string description;
	int total = 0;
	

	for (int i = 0; i < p; i++){
		inputFile >> description;
		total += salaries[description];

		while(description != "."){
			inputFile >> description;
			total += salaries[description];
		}
    
		outputFile << total << endl;
		total = 0;
	}

	inputFile.close();
	outputFile.close();
	
	return 0;
}
