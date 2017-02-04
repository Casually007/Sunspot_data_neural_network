#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <array>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include "fnn.h"


double** training_data = 0;
double** test_data = 0;
int border = 0;
double max_o,min_o,max_i,min_i;

using namespace std;
void encode_data()
{
	string lineA;
	int i;
	string filename;
	ifstream fileIN;

	max_o = data_set[0][1];
	for (i = 1; i < rowA; i++) {
		if (max_o < data_set[i][1]) {
			max_o = data_set[i][1];
		}
	}
	//Input Normalization i/p normalization -0.9 to 0.9 &  o/p normalization  -1 to 1
	min_i = data_set[0][0];
	max_i = data_set[rowA-1][0];
	min_o = 0;
	for (i = 0; i < rowA; i++) {
		data_set_norm[i][0] = -0.9 + (data_set[i][0] - min_i)*1.8 / (max_i - min_i);
		data_set_norm[i][1] = -1 + (data_set[i][1] - min_o)*2 / (max_o - min_o);
	}
	//training & test data
	border = 0.7*rowA;			// 60 percent data for training purpose
	training_data = new double*[border];
	test_data = new double*[rowA - border];
	for (i = 0; i < border; i++) {
		training_data[i] = new double[colA - 2];
	}
	for (i = 0; i < rowA - border; i++) {
		test_data[i] = new double[colA - 2];
	}
	int k = 0;
	int l = 0;
	int count = 0;
	int countA = 0;
	int flag,j;
	flag = 1;
	for (i = 0; i < rowA; i++) {
		if (k < border && flag == 1) {
			for (j = 0; j<colA - 2; j++) {
				training_data[k][j] = data_set_norm[i][j];
				//cout << training_data[k][j] << "  ";
			}
			//cout << endl;
			count = count + 1;
			k = k + 1;
		}
		if (l < (rowA - border) && flag == 0) {
			for (j = 0; j<colA - 2; j++) {
				test_data[l][j] = data_set_norm[i][j];
				//cout << test_data[l][j] << " ";
			}
			//cout << endl;
			l = l + 1;

		}
		if (l < (rowA - border) && count >= 2) {
			count = 0;
			flag = 0;
		}
		else {
			flag = 1;
		}
	}
}
