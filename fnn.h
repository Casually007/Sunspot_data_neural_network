#pragma once
#ifndef FNN_H
#define FNN_H
#include <iostream>
extern int rowA;
extern int colA;
extern int layer_count;		//No of layers in NN including input & output layer
extern int border;
extern double* training_error;
extern double eta;
extern double** data_set;
extern double** data_set_norm;
extern double** training_data;
extern double** test_data;
extern double* train_error_LSE;
extern int* num;			//Array containing info about  nos. of neurons in each layer *including o/p & i/p layer
extern int epoch;
extern double* input;
void create2DArray();
void encode_data();
void nn_parameter_set();
void param_read();
double rand_gen(double mean, double stddev);
double threshold(int flag, int deriv, double net_val);
void net_construct();
void forward_propagation(int pattern_no);
void backpropagation();
void weight_update();
class neuron
{
public:
	double* weight;
	double net_j;
	double  o_p_val;
	double* del_weight;
	double del_j;
};

class layers
{
public:
	neuron* neural_unit;	//neurons in one layer;
	int threshold;			//a flag to choose between a bunch of threshold function.
};
extern layers* neural_layers;
#endif