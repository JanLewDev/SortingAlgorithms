#pragma once
#include<bits/stdc++.h>

std::mt19937 rng;
inline int rand(const int &a, const int &b) { return std::uniform_int_distribution<int>(a, b)(rng); }

int* generate_random_array(int seed, int n) {
	rng.seed(seed);
	int* tab = new int[n];
	for(int i = 0; i < n; i++) tab[i] = rand(0, n >> 3);
	return tab;
}
