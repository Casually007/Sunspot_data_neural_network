#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <array>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include "fnn.h"
using namespace std;
void nn_parameter_set() {
	int n_hidden,i_p,temp;
	std::ofstream outfile;
	outfile.open("neural_net_parameter.txt", ios::out | ios::trunc);
	cout << "\n How much hidden layers do you want?" << endl;
	cin >> n_hidden;
	outfile << "#No. of input nodes:";
	outfile << endl;
	cout << "\n Please enter nos. of input nodes" << endl;
	cin >> i_p;
	outfile << i_p;
	outfile << endl;
	for (int count = 1; count < n_hidden+1; count++)
	{
		outfile << "#No. of  nodes in hidden layer " << count << ":" << endl; 
		cout << "\n Please enter nos. of nodes in hidden layer" << count <<":";
		cin >> temp;
		outfile << temp;
		outfile << endl;
	}
	outfile << "#No. of output nodes:";
	outfile << endl;
	outfile << i_p;
	outfile << endl;
}