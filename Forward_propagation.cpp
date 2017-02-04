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
void forward_propagation(int pattern_no) {
	//forward propagation
	int derv;
	//initialization
	for (int i = 0; i < layer_count - 1; i++) {
		for (int j = 0; j < num[i + 1]; j++) {
			neural_layers[i].neural_unit[j].net_j = 0;
			neural_layers[i].neural_unit[j].o_p_val = 0;
			neural_layers[i].neural_unit[j].del_j = 0;
		}
	}
	for (int i = 0; i < layer_count - 1; i++) {
		for (int j = 0; j < num[i + 1]; j++) {
			for (int k = 0; k < num[i]; k++) {
				neural_layers[i].neural_unit[j].del_weight[k] = 0;
			}
		}
	}

	derv = 0;
	//first hidden layer

	for (int i = 0; i < num[0]; i++) {
		//input data
		if (pattern_no < border) {
			input[i] = training_data[pattern_no + i][0];
		}
		else {
			input[i] = test_data[pattern_no - border + i][0];
		}
	}

		for (int j = 0; j < num[1]; j++) {
			for (int i = 0; i < num[0]; i++) {

				if (pattern_no < border) {
					//regression data
					neural_layers[0].neural_unit[j].net_j = neural_layers[0].neural_unit[j].net_j + neural_layers[0].neural_unit[j].weight[0] * training_data[pattern_no + i][0];
					//time series data
					//neural_layers[0].neural_unit[j].net_j = neural_layers[0].neural_unit[j].weight[0] * training_data[pattern_no + i][0];
				}
				else {
					//regression data
					neural_layers[0].neural_unit[j].net_j = neural_layers[0].neural_unit[j].net_j + neural_layers[0].neural_unit[j].weight[0] * test_data[pattern_no - border + i][0];
					//time series data
					//neural_layers[0].neural_unit[j].net_j = neural_layers[0].neural_unit[j].weight[0] * test_data[pattern_no - border + i][0]; 
				}
		}
			neural_layers[0].neural_unit[j].o_p_val = threshold(neural_layers[0].threshold, derv, neural_layers[0].neural_unit[j].net_j);
			//cout << neural_layers[0].neural_unit[j].o_p_val << endl;
	}
	//subsequent layers including output layer

	for (int i = 1; i < layer_count-1; i++) {
		for (int j = 0; j < num[i+1]; j++) {
			for (int k = 0; k < num[i]; k++) {
				neural_layers[i].neural_unit[j].net_j = neural_layers[i].neural_unit[j].net_j + neural_layers[i-1].neural_unit[j].o_p_val *neural_layers[i].neural_unit[j].weight[k];
				//cout << neural_layers[i].neural_unit[j].weight[k] << endl;
			}
			neural_layers[i].neural_unit[j].o_p_val = threshold(neural_layers[i].threshold, derv, neural_layers[i].neural_unit[j].net_j);
			//cout << neural_layers[i].neural_unit[j].o_p_val << endl;
		}
	}
}
