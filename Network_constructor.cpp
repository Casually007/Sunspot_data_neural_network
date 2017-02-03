#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <array>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include "fnn.h"

layers* neural_layers = 0;

using namespace std;
void net_construct() {
	double mean = 0;
	double stddev = 0.3;
	neural_layers = new layers[layer_count-1];
	for (int i = 0; i < layer_count-1; i++) {
		neural_layers[i].neural_unit = new neuron[num[i+1]];
		if (i != layer_count - 2) {							// threshold function defined for each hidden layer set tan-hyperbolic function; 
			neural_layers[i].threshold = 1;
		}
		else {
			neural_layers[i].threshold = 0;
		}
		for (int j = 0; j < num[i+1]; j++) {
			neural_layers[i].neural_unit[j].weight = new double[num[i]];
			neural_layers[i].neural_unit[j].del_weight = new double[num[i]];
			for (int k = 0; k < num[i]; k++) {
				neural_layers[i].neural_unit[j].weight[k] = rand_gen(mean,stddev); 
			}

		}
	}
}
