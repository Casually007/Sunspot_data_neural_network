#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <array>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include "fnn.h"

int rowA = 0;
int colA = 0;
double** data_set = 0;
double** data_set_norm = 0;

using namespace std;
void create2DArray()
{
	string lineA;
	double x;
	double arrayA[500][4];
	string filename;
	ifstream fileIN;

	//intro
	cout << "\n please enter file name and enter" << endl;
	cin >> filename;
	fileIN.open(filename);

	//error check
	if (fileIN.fail()) {
		cerr << "Hey something went wrong!!" << endl;
		exit(1);
	}

	//reading data file
	cout << "\n" << endl;
	while (fileIN.good()) {
		while (getline(fileIN, lineA)) {
			istringstream streamA(lineA);
			colA = 0;
			while (streamA >> x) {
				arrayA[rowA][colA] = x;
				colA++;
			}
			rowA++;
		}
	}

	data_set = new double*[rowA];
	data_set_norm = new double*[rowA];
	for (int i = 0; i<rowA; i++) {
		data_set[i] = new double[colA-2];
		data_set_norm[i] = new double[colA - 2];
		for (int j = 0; j<colA-2; j++) {
			data_set[i][j] = arrayA[i][j];
		}
	}
}
