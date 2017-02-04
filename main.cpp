#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <array>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include "fnn.h"

double* train_error_LSE = 0;
double eta = 0.15;
double* input = 0;
double* training_error = 0;
using namespace std;
int main()
{
	create2DArray();
    encode_data();
	double temp = 0;
	//Parameter set for neural network
	int flag;
	cout << "\n (If you want to change neural network parameter please enter 1" << endl;
	cin >> flag;
	if (flag == 1) {
		nn_parameter_set();
	}
	else {
		//Call function which will create network;
	}

	param_read();
	net_construct();
	//cout << border;
	input = new double[num[0]];
	training_error = new double[num[layer_count - 1]];
	train_error_LSE = new double[border];

	//training error initialization
	for (int i = 0; i < border; i++) {
		train_error_LSE[i] = 0;
	}

	//online learning
	for (int i = 0; i < border; i++) {
		forward_propagation(i);
		for (int j = 0; j < num[layer_count - 1]; j++) {
			//train_error_LSE[i] = training_data[i][1] - neural_layers[layer_count - 2].neural_unit[0].o_p_val;
			temp = decoder(training_data[i+j][1]) - decoder(neural_layers[layer_count - 2].neural_unit[j].o_p_val);
			temp = encoder(temp);
			training_error[j] = temp;
			train_error_LSE[i] = train_error_LSE[i] + 0.5*temp * temp;
		}
		cout << train_error_LSE[i] << endl;
		//call backpropagation
		backpropagation();
		//weight update
		weight_update();
	}

	//untrained data response
	for (int i = border; i < rowA; i++) {
		forward_propagation(i);
		temp = decoder(test_data[i - border][1]) - decoder(neural_layers[layer_count - 2].neural_unit[0].o_p_val);
		cout << decoder(test_data[i -border][1]) << " " << decoder(neural_layers[layer_count - 2].neural_unit[0].o_p_val) << " " << temp << endl;
		//cout << test_data[i - border][1] << " " << neural_layers[layer_count - 2].neural_unit[0].o_p_val << " " << temp << endl;
	}



    system("pause");

	return 0;
	
}



