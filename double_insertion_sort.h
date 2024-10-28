#include <bits/stdc++.h>

void double_insertion_sort(int* tab, int n) {
	for(int i = 1; i < n; i += 2) {
		if (tab[i-1] > tab[i]) {
			std::swap(tab[i-1], tab[i]);
		}
		int first = tab[i-1];
		int second = tab[i];
		// inserting both elements
		int j = i - 2;
		while(j >= 0 && tab[j] > second) {
			tab[j+2] = tab[j];
			j--;
		}
		tab[j+2] = second;

		// inserting the smaller element
		while(j >= 0 && tab[j] > first) {
			tab[j+1] = tab[j];
			j--;
		}
		tab[j+1] = first;
	}

	// if n is odd, the last element has been omitted
	if (n % 2 != 0) {
		int last = tab[n-1];
		int j = n - 2;
		while(j >= 0 && tab[j] > last) {
			tab[j+1] = tab[j];
			j--;
		}
		tab[j+1] = last;
	}
}
