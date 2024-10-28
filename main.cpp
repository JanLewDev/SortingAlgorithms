#include <bits/stdc++.h>
#include "double_insertion_sort.h"
#include "heap_sort.h"
#include "insertion_sort.h"
#include "merge_sort.h"
#include "ternary_heap_sort.h"
#include "ternary_merge_sort.h"

#include "gen.h"
#include "spr.h"
#include "memory.h"
#include "windows.h"
#include "psapi.h"



#define upgrade ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int num_of_algs = 6;
std::string names[num_of_algs] = { "insertion_sort", "double_insertion_sort", "heap_sort", "ternary_heap_sort", "merge_sort", "ternary_merge_sort" };
void (*algorithms[num_of_algs])(int*, int) = { insertion_sort, double_insertion_sort, heap_sort, ternary::heap_sort, merge_sort, ternary::merge_sort };

const int number_of_tests = 1000;
const std::set<int> test_sizes = { 10, 100, 1000, 10000, 100000 };

long double get_MB() {
    int64_t bytes = getCurrentRSS();
    return (long double)(bytes) / 1000000;
}

int main() {
	std::ofstream result("result.csv");
	assert(result.is_open());
	result << "Algorithm,Length,Time,Memory\n";
	for(int i = 1; i <= number_of_tests; i++) {
		for(int n : test_sizes) {
			int* tab = generate_random_array(i, n);
			int* input = new int[n];
			std::copy(tab, tab + n, input);
			for(int j = 0; j < num_of_algs; j++) {
				int* copy = new int[n];
				std::copy(input, input + n, copy);
				auto start = std::chrono::high_resolution_clock::now();
				algorithms[j](copy, n);
				auto stop = std::chrono::high_resolution_clock::now();
				auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
				check(input, copy, n);
				std::cout << names[j] << " " << n << " " << duration.count() << " " << get_MB() << "\n";
				result << names[j] << "," << n << "," << duration.count() << "," << get_MB() << "\n";
				result.flush();
				delete[] copy;
			}
			delete[] tab;
			delete[] input;
		}
	}
	result.close();

	return 0;
}
