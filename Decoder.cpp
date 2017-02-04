#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <array>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include "fnn.h"

using namespace std;

double decoder(double decrypt) {
	double ret_val;
	//output normalization
	ret_val = min_o + (decrypt + 1)*(max_o - min_o) / 2;
	return ret_val;
}

double encoder(double encrypt) {
	double ret_val;
	ret_val = -1 + (encrypt - min_o) * 2 / (max_o - min_o);
	return ret_val;
}