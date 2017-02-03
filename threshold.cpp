#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <array>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <math.h> 
#include "fnn.h"
using namespace std;

double threshold(int flag,int deriv,double net_val) {
	double ret_val = 0;
	if (flag == 0) {
		if (deriv == 0) {
			ret_val =  net_val;
		}
		else {
			ret_val = 1 ;
		}
	}
	else {
		double a = 1.7159;
		double b = 2.0 / 3.0;

		if(deriv == 0) {
			ret_val = a*tanh(b*net_val);
		}
		else {
			ret_val = a*b / (cosh(b*net_val)*cosh(b*net_val));
		}
		
	}

	return ret_val;
}