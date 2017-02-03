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

void weight_update() {
	for (int i = 0; i < layer_count - 1; i++) {
		for (int j = 0; j < num[i + 1]; j++) {
			for (int k = 0; k < num[i]; k++) {
				neural_layers[i].neural_unit[j].weight[k] = neural_layers[i].neural_unit[j].weight[k] + eta*neural_layers[i].neural_unit[j].del_weight[k];
			}
		}
	}
}