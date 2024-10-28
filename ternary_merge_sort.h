#include <bits/stdc++.h>

namespace ternary {
	// intervals [p, m1], [m1+1, m2] oraz [m2+1, k]
	void thirds_merge(int* tab, int p, int m1, int m2, int kon) {
		int n1 = m1 - p + 1;
		int n2 = m2 - m1;
		int n3 = kon - m2;
		// left, middle, right arrays
		int* L = new int[n1];
		int* S = new int[n2];
		int* P = new int[n3];

		for (int i = 0; i < n1; i++) {
			L[i] = tab[i + p];
		}

		for (int i = 0; i < n2; i++) {
			S[i] = tab[i + m1 + 1];
		}

		for (int i = 0; i < n3; i++) {
			P[i] = tab[i + m2 + 1];
		}

		int i = 0, j = 0, k = 0;
		while (i < n1 && j < n2 && k < n3) {
			if (L[i] <= S[j] && L[i] <= P[k]) {
				tab[p + i + j + k] = L[i];
				i++;
			} else if (S[j] <= L[i] && S[j] <= P[k]) {
				tab[p + i + j + k] = S[j];
				j++;
			} else {
				tab[p + i + j + k] = P[k];
				k++;
			}
		}

		// Copying leftovers from L and S
		while (i < n1 && j < n2) {
			if (L[i] <= S[j]) {
				tab[p + i + j + k] = L[i];
				i++;
			} else {
				tab[p + i + j + k] = S[j];
				j++;
			}
		}

		// Copying leftovers from S and P
		while (j < n2 && k < n3) {
			if (S[j] <= P[k]) {
				tab[p + i + j + k] = S[j];
				j++;
			} else {
				tab[p + i + j + k] = P[k];
				k++;
			}
		}

		// Copying leftovers from L and P
		while (i < n1 && k < n3) {
			if (L[i] <= P[k]) {
				tab[p + i + j + k] = L[i];
				i++;
			} else {
				tab[p + i + j + k] = P[k];
				k++;
			}
		}

		// Copying leftovers from L, S, and P
		while (i < n1) {
			tab[p + i + j + k] = L[i];
			i++;
		}
		while (j < n2) {
			tab[p + i + j + k] = S[j];
			j++;
		}
		while (k < n3) {
			tab[p + i + j + k] = P[k];
			k++;
		}
		delete[] L;
		delete[] S;
		delete[] P;
	}

	void merge_sort_rec(int* tab, int p, int k) {
		if (p < k) {
			int m1 = p + (k - p) / 3;
			int m2 = p + 2 * (k - p) / 3;
			merge_sort_rec(tab, p, m1);
			merge_sort_rec(tab, m1+1, m2);
			merge_sort_rec(tab, m2+1, k);
			thirds_merge(tab, p, m1, m2, k);
		}
	}

	void merge_sort(int* tab, int n) {
		merge_sort_rec(tab, 0, n - 1);
	}
}
