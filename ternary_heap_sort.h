#include <bits/stdc++.h>

namespace ternary {
	inline int left(int a){ return a * 3 + 1; }
	inline int middle(int a){ return a * 3 + 2; }
	inline int right(int a){ return a * 3 + 3; } 

	void heapify(int* tab, int n, int i) {
		int l = left(i);
		int m = middle(i);
		int r = right(i);
		int largest = i;
		if (l < n && tab[l] > tab[i]) largest = l;
		if (m < n && tab[m] > tab[largest]) largest = m;
		if (r < n && tab[r] > tab[largest]) largest = r;

		if (largest != i) {
			std::swap(tab[i], tab[largest]);
			heapify(tab, n, largest);
		}
	}

	void build_heap(int* tab, int n) {
		for(int i = n / 3 + 1; i >= 0; i--) {
			heapify(tab, n, i);
		}
	}

	void heap_sort(int* tab, int n) {
		build_heap(tab, n);
		for(int i = n - 1; i >= 1; i--) {
			std::swap(tab[0], tab[i]);
			heapify(tab, i - 1, 0);
		}
	}
}
