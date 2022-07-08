#include <bits/stdc++.h>
#define DBG(x) cerr << #x << " = " << x << endl
#define forn(i,n) for(int i = 0; i < int(n); i++)
#include "sorting.h"

using namespace std;

template<typename T>
ostream &operator<< (ostream &os, vector<T> &v) {
	os << "[";
	forn (i, v.size()) {
		if (i != 0) os << ", ";
		os << v[i];
	}
	os << "]";
	return os;
}

int findSwapPairs(int N, int S[], int M, int X[], int Y[], int P[], int Q[]) {
    vector<int> result (N), values(N), pTemp, qTemp;
	vector<bool> yaFueUbicado (N, false);

	forn(i, N) {
		result[i] = i;
		values[i] = S[i];
	}

	for (int i = M-1; i >= 0; i--) {
		swap(result[X[i]], result[Y[i]]);
	}

	forn (i, M) {
		swap(values[X[i]], values[Y[i]]);
		swap(yaFueUbicado[X[i]], yaFueUbicado[Y[i]]);
		swap(result[X[i]], result[Y[i]]);

		int minPos = -1; 
		int minPosOrdenado = int(find(result.begin(), result.end(), i) - result.begin());
		bool faltaUbicarAlguno = false;

		forn (j, N) {
			if (yaFueUbicado[j]) continue;
			faltaUbicarAlguno = true;

			if (minPos == -1) minPos = j;
			else if (values[minPos] > values[j]) minPos = j;
		}

		if (faltaUbicarAlguno) {
			yaFueUbicado[minPos] = true;

			pTemp.push_back(minPos);
			qTemp.push_back(minPosOrdenado);

			swap(values[minPos], values[minPosOrdenado]);
			swap(yaFueUbicado[minPos], yaFueUbicado[minPosOrdenado]);
		} else {
			pTemp.push_back(0);
			qTemp.push_back(0);
		}
	}

	copy(pTemp.begin(), pTemp.end(), P);
	copy(qTemp.begin(), qTemp.end(), Q);

	return int(qTemp.size());
}