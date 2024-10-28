// intervals [p, s] oraz [s+1, k]
void merge(int* tab, int p, int s, int k) {
	int n1 = s - p + 1;
	int n2 = k - s; 
	int* L = new int[n1];
	int* P = new int[n2];

	for (int i = 0; i < n1; i++) {
		L[i] = tab[i + p];
	}

	for (int i = 0; i < n2; i++) {
		P[i] = tab[i + s + 1];
	}

	int i = 0, j = 0;
	while (i < n1 && j < n2) {
		if (L[i] <= P[j]) {
			tab[p + i + j] = L[i];
			i++;
		} else {
			tab[p + i + j] = P[j];
			j++;
		}
	}
	
	while (i < n1) {
		tab[p + i + j] = L[i];
		i++;
	}
	while (j < n2) {
		tab[p + i + j] = P[j];
		j++;
	}
	delete[] L;
	delete[] P;
}

void merge_sort_rec(int* tab, int p, int k) {
	if (p < k) {
		int s = (p + k) / 2;
		merge_sort_rec(tab, p, s);
		merge_sort_rec(tab, s + 1, k);
		merge(tab, p, s, k);
	}
}

void merge_sort(int* tab, int n) {
	merge_sort_rec(tab, 0, n - 1);
}
