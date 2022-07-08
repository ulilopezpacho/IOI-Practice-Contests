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

bool findSwapPairsBrute (const int steps, const int N, const int S[], const int X[], const int Y[], vector<int> &pTemp, vector<int> &qTemp) {
	vector<int> result (N), values(N);
	vector<bool> yaFueUbicado (N, false);

	forn(i, N) {
		result[i] = i;
		values[i] = S[i];
	}

	for (int i = steps-1; i >= 0; i--) {
		swap(result[X[i]], result[Y[i]]);
	}

	int it = 0;

	forn (i, steps) {
		swap(values[X[i]], values[Y[i]]);
		swap(yaFueUbicado[X[i]], yaFueUbicado[Y[i]]);
		swap(result[X[i]], result[Y[i]]);

		int minPos = -1; 
		int minPosOrdenado = -1;

		while (minPos == minPosOrdenado && it < N) {
			minPos = -1; 
			minPosOrdenado = int(find(result.begin(), result.end(), i) - result.begin());
			forn (j, N) {
				if (yaFueUbicado[j]) continue;
				if (minPos == -1) minPos = j;
				else if (values[minPos] > values[j]) minPos = j;
			}
			it++;
		}

		if (minPos != minPosOrdenado) {
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
	return is_sorted(values.begin(), values.end());
}

int findSwapPairs(int N, int S[], int M, int X[], int Y[], int P[], int Q[]) {
    vector<int> pTemp, qTemp;
	forn (i, M-1) {
		pTemp.clear(); qTemp.clear();
		if (findSwapPairsBrute(i+1, N, S, X, Y, pTemp, qTemp)) {
			copy(pTemp.begin(), pTemp.end(), P);
			copy(qTemp.begin(), qTemp.end(), Q);
			return int(pTemp.size());
		}
	}
	return 0;
}