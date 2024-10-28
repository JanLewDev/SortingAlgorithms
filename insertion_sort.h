#include <bits/stdc++.h>

void insertion_sort(int* tab, int n) {
	for(int i = 1; i < n; i++) {
		int key = tab[i];
		int j = i - 1;
		while(j >= 0 && tab[j] > key) {
			tab[j+1] = tab[j];
			j--;
		}
		tab[j+1] = key;
	}
}
