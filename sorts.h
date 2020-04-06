#pragma once
#include <iostream>
#include <ctime>
#include <math.h>
#include <vector>
#include <chrono>
#include <iomanip>


using namespace std;
using namespace std::chrono;

template <typename T>
const ostream& operator<<(ostream& out, const vector<T>& v) {
	for (auto i : v) {
		out << i << ' ';
	}
	out << endl << endl;

	return out;
}

template <typename T>
int partition(vector<T>& v, const int left, const int right) {
	T pivot = v[(right + left) / 2];
	int i = left - 1;
	int j = right + 1;
	while (true) {
		do { i++; } while (v[i] < pivot);
		do { j--; } while (v[j] > pivot);
		if (i >= j) return j;
		swap(v[i], v[j]);
	}
}

template <typename T, typename iterator>//O(n2)
void selection_sort_src(vector<T>& v, const iterator begin, const iterator end) {
	for (iterator iterator1 = begin; iterator1 + 1 != end; ++iterator1) {
		iterator min = iterator1;
		for (iterator iterator2 = iterator1 + 1; iterator2 != end; ++iterator2)
			if (*iterator2 < *min)
				min = iterator2;
		if (min != iterator1) {
			swap(*min, *iterator1);
		}
	}
}

template <typename T>
void Selection_Sort(vector<T>& v) {
	selection_sort_src(v, v.begin(), v.end());
}

template <typename T>//O(n2)
void Bubble_Sort(vector<T>& v) {
	if (v.size() == 1)
		return;
	bool changed = true;
	while (1) {
		for (auto iterator = v.begin(); iterator + 1 != v.end(); ++iterator) {
			if (*iterator > * (iterator + 1)) {
				swap(*iterator, *(iterator + 1));
				changed = true;
			}
		}
		if (!changed)
			return;
		changed = false;
	}
}

template <typename T>//O(n2)???????????????????O(n2/3)
void Shell_Sort(vector<T>& v) {
	for (int distance = v.size() / 2; distance > 0; distance /= 2)
		for (size_t i = distance; i < v.size(); ++i)
			for (int j = i - distance; j >= 0 && v[j] > v[j + distance]; j -= distance) {
				swap(v[j], v[j + distance]);
			}
}

template <typename T>
void quick_sort_src(vector<T>& v, const int left, const int right) {
	if (left < right) {
		int part = partition<T>(v, left, right);
		quick_sort_src(v, left, part);
		quick_sort_src(v, part + 1, right);

	}
}

template <typename T>//O(nlogn)
void Quick_Sort(vector<T>& v) {
	quick_sort_src(v, 0, v.size() - 1);
}

template <typename T>//O(nlogn)
void Merge_Sort(vector<T>& v) {
	v.resize(v.size() * 2);
	bool s = true, f;
	int i, j, k, l;
	do {
		if (s) {
			i = 0; j = v.size() / 2 - 1; k = v.size() / 2; l = v.size() - 1;
		}
		else {
			k = 0; l = v.size() / 2 - 1; i = v.size() / 2; j = v.size() - 1;
		}
		int d = 1;
		f = false;
		while (1) {
			if (i == j) {
				v[k] = v[i];
				s = !s;
				break;
			}
			if (v[i] < v[j]) {
				v[k] = v[i];
				k = k + d;
				++i;
				if (v[i - 1] <= v[i]) continue;
				do {
					v[k] = v[j];
					k = k + d;
					--j;
				} while (v[j + 1] <= v[j]);
			}
			else {
				v[k] = v[j];
				k = k + d;
				--j;
				if (v[j + 1] <= v[j]) continue;
				do {
					v[k] = v[i];
					k = k + d;
					++i;
				} while (v[i - 1] <= v[i]);
			}
			f = true;
			d = -d;
			swap(k, l);
		}
	} while (f);

	if (s)
		v.resize(v.size() / 2);
	else {
		for (size_t c = 0; c < v.size() / 2; ++c)
			v[c] = v[c + v.size() / 2];
		v.resize(v.size() / 2);
	}
}


/////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////

template <typename T>
void Fill_Rand(vector<T>& v, const int size) {
	srand(time(NULL));
	for (int i = 0; i < size; ++i)
		v.push_back(rand());
}
