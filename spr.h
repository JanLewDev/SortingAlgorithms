#include <bits/stdc++.h>

void check(int* input, int* tab, int n) {
	std::map<int, int> input_counter;
	for(int i = 0; i < n; i++) {
		input_counter[input[i]]++;
	} 

	assert(input_counter[tab[0]] > 0);
	input_counter[tab[0]]--;
	for(int i = 1; i < n; i++) {
		assert(input_counter[tab[i]] > 0);
		input_counter[tab[i]]--;
		assert(tab[i-1] <= tab[i]);
	}
}
