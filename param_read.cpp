#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <array>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include "fnn.h"

int layer_count = 0;
int* num = 0;
using namespace std;

void param_read() {	
	int A[100];
	int x;
	string line;
	ifstream inputfile;
	inputfile.open("neural_net_parameter.txt");
	while (!inputfile.eof()) {
		getline(inputfile, line);

		if (line.length() == 0 || line[0] == '#') {
			//ignore those lines
		}
		else {
			istringstream streamA(line);
			while (streamA >> x)
			A[layer_count] = x;		//stoi converts string to integer.
			layer_count++;
		}
	}
	num = new int[layer_count];
	for (int i = 0; i < layer_count; i++) {
		num[i] = A[i];
	}

	inputfile.close();
}