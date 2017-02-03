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

void backpropagation() {

	// backpropagation
	//regression data
	// delta weight in output layer
	for (int l = 0; l < num[layer_count - 1]; l++) {
		neural_layers[layer_count - 2].neural_unit[l].del_j = training_error[l];
		for (int j = 0; j < num[layer_count - 1]; j++) {
			neural_layers[layer_count - 2].neural_unit[l].del_weight[j] = neural_layers[layer_count - 2].neural_unit[l].del_j * neural_layers[layer_count - 3].neural_unit[j].o_p_val;
		}
	}


	// weight update for hidden layers
	int flag = 1;
	int deriv = 1;
	double temp = 0;
	for (int i = 0; i < layer_count - 2; i++) {
		for (int j = 0; j < num[layer_count - 2 - i]; j++) {
			for (int k = 0; k < num[layer_count - 3 - i]; k++) {
				for (int l = 0; l < num[layer_count - 1 - i]; l++) {
					temp = neural_layers[layer_count - 2 - i].neural_unit[l].del_j*neural_layers[layer_count - 2 - i].neural_unit[l].weight[j] * threshold(flag, deriv, neural_layers[layer_count - 3 - i].neural_unit[j].net_j);
					neural_layers[layer_count - 3 - i].neural_unit[j].del_j = neural_layers[layer_count - 3 - i].neural_unit[j].del_j + temp;
				}
				if (layer_count - 4 - i < 0) {
					neural_layers[layer_count - 3 - i].neural_unit[j].del_weight[k] = neural_layers[layer_count - 3 - i].neural_unit[j].del_j*input[k];
				}
				else {
					neural_layers[layer_count - 3 - i].neural_unit[j].del_weight[k] = neural_layers[layer_count - 3 - i].neural_unit[j].del_j*neural_layers[layer_count - 4 - i].neural_unit[k].o_p_val;
				}
			}
		}
	}
}