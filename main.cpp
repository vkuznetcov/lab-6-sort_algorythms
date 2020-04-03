#include <iostream>
#include <ctime>
#include <math.h>
#include <vector>
#include <chrono>
#include <iomanip>
#include "sorts.h"
#define simulations 5

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

int main() {
	vector<int> vect;
	long int sizes[simulations];
	long int sizes_big[simulations];
	for (int i = 0; i < simulations; ++i) {
		if (i == 0) {
			sizes[i] = 50000;
			sizes_big[i] = 5000000;
			continue;
		}
		sizes[i] = sizes[i - 1] + 25000;
		sizes_big[i] = sizes_big[i - 1] + 5000000;
	}
	double results[simulations];
	cout << "How many simulations do you want to perform?\n\nNumber of simulations: ";
	int sim_size;
	cin >> sim_size;
	getchar();
	system(CLEAR);
	double result_cur = 0;
	cout << "Which sort do you want to use?\n1.Choise Sort\n2.Bubble Sort\n3.Shell Sort\n4.Quick Sort\n5.Merge Sort\n0.Exit\nYour choice: ";
	switch (getchar()) {
	case '1': {
		system(CLEAR);
		cout << setw(30) << "SIZES" << setw(16) << "SORTING TIME" << setw(16) << "SIZE RATIO" << setw(16) << "TIME RATIO" << endl << endl;
		for (int i = 0; i < simulations; ++i) {
			for (int j = 0; j < sim_size; ++j) {
				Fill_Rand(vect, sizes[i]);
				time_t start = clock();
				Choice_Sort(vect, vect.begin(), vect.end());
				time_t stop = clock();
				vect.erase(vect.begin(), vect.end());
				result_cur += (stop - start);
			}
			if (i != 0)
				results[i] = (static_cast<double>(result_cur) / (static_cast<long double>(sim_size) * CLK_TCK)) - results[i - 1];
			else results[i] = (static_cast<double>(result_cur) / (static_cast<long double>(sim_size) * CLK_TCK));
			if (i == 0)
				cout << setw(30) << sizes[i] << setw(16) << results[i] << setw(16) << "-" << setw(16) << "-" << endl << endl;
			else
				cout << setw(30) << sizes[i] << setw(16) << results[i] << setw(16) << static_cast<double>(sizes[i]) * sizes[i] / (static_cast<long double>(sizes[0]) * sizes[0]) << setw(16) << results[i] / results[0] << endl << endl;
		}
	}break;
	case '2': {
		system(CLEAR);
		cout << setw(30) << "SIZES" << setw(16) << "SORTING TIME" << setw(16) << "SIZE RATIO" << setw(16) << "TIME RATIO" << endl << endl;
		for (int i = 0; i < simulations; ++i) {
			for (int j = 0; j < sim_size; ++j) {
				Fill_Rand(vect, sizes[i]);
				time_t start = clock();
				Bubble_Sort(vect);
				time_t stop = clock();
				vect.erase(vect.begin(), vect.end());
				result_cur += (stop - start);
			}
			if (i != 0)
				results[i] = (static_cast<double>(result_cur) / (static_cast<long double>(sim_size) * CLK_TCK)) - results[i - 1];
			else results[i] = (static_cast<double>(result_cur) / (static_cast<long double>(sim_size) * CLK_TCK));
			if (i == 0)
				cout << setw(30) << sizes[i] << setw(16) << results[i] << setw(16) << "-" << setw(16) << "-" << endl << endl;
			else
				cout << setw(30) << sizes[i] << setw(16) << results[i] << setw(16) << (static_cast<double>(sizes[i]) * sizes[i]) / (static_cast<long double>(sizes[0]) * sizes[0]) << setw(16) << results[i] / results[0] << endl << endl;
		}
	}break;
	case '3': {
		system(CLEAR);
		cout << setw(30) << "SIZES" << setw(16) << "SORTING TIME" << setw(16) << "SIZE RATIO" << setw(16) << "TIME RATIO" << endl << endl;
		for (int i = 0; i < simulations; ++i) {
			for (int j = 0; j < sim_size; ++j) {
				Fill_Rand(vect, sizes_big[i]);
				time_t start = clock();
				Shell_Sort(vect);
				time_t stop = clock();
				vect.erase(vect.begin(), vect.end());
				result_cur += (stop - start);
			}
			if (i != 0)
				results[i] = (static_cast<double>(result_cur) / (static_cast<long double>(sim_size) * CLK_TCK)) - results[i - 1];
			else results[i] = (static_cast<double>(result_cur) / (static_cast<long double>(sim_size) * CLK_TCK));
			if (i == 0)
				cout << setw(30) << sizes_big[i] << setw(16) << results[i] << setw(16) << "-" << setw(16) << "-" << endl << endl;
			else
				cout << setw(30) << sizes_big[i] << setw(16) << results[i] << setw(16) << static_cast<long double>(sizes_big[i]) * sqrt(sizes_big[i]) / (static_cast<long double>(sizes_big[0]) * sqrt(sizes_big[0])) << setw(16) << results[i] / results[0] << endl << endl;
		}
	}break;
	case '4': {
		system(CLEAR);
		cout << setw(30) << "SIZES" << setw(16) << "SORTING TIME" << setw(16) << "SIZE RATIO" << setw(16) << "TIME RATIO" << endl << endl;
		for (int i = 0; i < simulations; ++i) {
			for (int j = 0; j < sim_size; ++j) {
				Fill_Rand(vect, sizes_big[i]);
				time_t start = clock();
				Quick_Sort(vect);
				time_t stop = clock();
				vect.erase(vect.begin(), vect.end());
				result_cur += (stop - start);
			}
			if (i != 0)
				results[i] = (static_cast<double>(result_cur) / (static_cast<long double>(sim_size) * CLK_TCK)) - results[i - 1];
			else results[i] = (static_cast<double>(result_cur) / (static_cast<long double>(sim_size) * CLK_TCK));
			if (i == 0)
				cout << setw(30) << sizes_big[i] << setw(16) << results[i] << setw(16) << "-" << setw(16) << "-" << endl << endl;
			else
				cout << setw(30) << sizes_big[i] << setw(16) << results[i] << setw(16) << static_cast<double>(sizes_big[i]) * log(sizes_big[i]) / (static_cast<double>(sizes_big[0]) * log(sizes_big[0])) << setw(16) << results[i] / results[0] << endl << endl;
		}
	}break;
	case '5': {
		system(CLEAR);
		cout << setw(30) << "SIZES" << setw(16) << "SORTING TIME" << setw(16) << "SIZE RATIO" << setw(16) << "TIME RATIO" << endl << endl;
		for (int i = 0; i < simulations; ++i) {
			for (int j = 0; j < sim_size; ++j) {
				Fill_Rand(vect, sizes_big[i]);
				time_t start = clock();
				Merge_Sort(vect);
				time_t stop = clock();
				vect.erase(vect.begin(), vect.end());
				result_cur += (stop - start);
			}
			if (i != 0)
				results[i] = (static_cast<double>(result_cur) / (static_cast<long double>(sim_size) * CLK_TCK)) - results[i - 1];
			else results[i] = (static_cast<double>(result_cur) / (static_cast<long double>(sim_size) * CLK_TCK));
			if (i == 0)
				cout << setw(30) << sizes_big[i] << setw(16) << results[i] << setw(16) << "-" << setw(16) << "-" << endl << endl;
			else
				cout << setw(30) << sizes_big[i] << setw(16) << results[i] << setw(16) << static_cast<double>(sizes_big[i]) * log(sizes_big[i]) / (static_cast<double>(sizes_big[0]) * log(sizes_big[0])) << setw(16) << results[i] / results[0] << endl << endl;
		}
	}break;
	case '0': return 0;
	default: cout << "ERROR: there is no such option.";
	}
}