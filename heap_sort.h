#include <bits/stdc++.h>

inline int left(int a){ return a * 2 + 1; }
inline int right(int a){ return a * 2 + 2; } 

void heapify(int* tab, int n, int i) {
	int l = left(i);
	int r = right(i);
	int largest = i;
	if (l < n && tab[l] > tab[i]) largest = l;
	if (r < n && tab[r] > tab[largest]) largest = r;

	if (largest != i) {
		std::swap(tab[i], tab[largest]);
		heapify(tab, n, largest);
	}
}

void build_heap(int* tab, int n) {
	for(int i = n / 2; i >= 0; i--) {
		heapify(tab, n, i);
	}
}

void heap_sort(int* tab, int n) {
	build_heap(tab, n);
	for(int i = n - 1; i >= 1; i--) {
		std::swap(tab[0], tab[i]);
		heapify(tab, i, 0);
	}
}
