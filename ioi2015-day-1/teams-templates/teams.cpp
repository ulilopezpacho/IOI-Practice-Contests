#include <bits/stdc++.h>
#include "teams.h"

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define DBG(x) cerr << #x << " = " << x << endl

using namespace std;

int n = 0, segN = 1;

vector<pair<int, bool>> operations;
vector<int> cantidad;
vector<int> segTree;

template<typename T>
ostream &operator << (ostream &os, vector<T> &v) {
	os << "[";
	forn (i,v.size()) {
		if (i != 0) os << ", ";
		os << v[i];
	}
	os << "]\n";
	return os;
}

void update (int pos, int val) {
	pos += segN; segTree[pos] = val;
	for (pos /= 2; pos >= 1; pos /= 2) {
		segTree[pos] = min(segTree[pos*2], segTree[pos*2+1]);
	}
}

int getMin (int a, int b) {
	int ans = 2e9;
	a += segN; b += segN;
	while (a <= b) {
		if (a % 2 == 1) ans = min(segTree[a++], ans);
		if (b % 2 == 0) ans = min(segTree[b--], ans);
		a /= 2; b /= 2; 
	}
	return ans;
}

void init(int N, int A[], int B[]) {
	
	n = N+1;
	cantidad.resize(N+1);
	while (segN < n) segN *= 2;
	segTree.resize(segN*2);
	
	forn (i,N) operations.push_back({A[i], true});
	forn (i,N) operations.push_back({B[i]+1, false});

	sort(operations.begin(), operations.end());
	int counter = 0;

	int anterior = 0;

	for (pair<int,bool> &op: operations) {
		if (anterior != op.first) {
			for (int i = anterior; i < op.first; i++) {
				cantidad[i] = counter;
				update(i, counter);
			}
		}
		anterior = op.first;
		if (op.second) counter++; else counter--;
	}
}

int can(int M, int K[]) {

	vector<int> cants (M);
	forn (i,M) cants[i] = K[i];
	sort(cants.begin(), cants.end());

	vector<pair<int,int>> acumulados (1, {cants[0], 1});

	for (int i = 1; i < M; i++) 
		if (acumulados.back().first == cants[i])
			acumulados.back().second++;
		else
			acumulados.push_back({cants[i], 1});

	int anterior = 0;
	int pasan = 0;

	for (auto &a: acumulados) {
		int puedenCompartirHasta = getMin(anterior, a.first);
		int cantidadSinCompartir = cantidad[a.first] - puedenCompartirHasta;
		int realmenteComparten = min(puedenCompartirHasta, pasan);

		int seNecesitan = a.first * a.second;
		if (realmenteComparten + cantidadSinCompartir < seNecesitan) return 0;
		
		pasan = cantidad[a.first] - seNecesitan;
		anterior = a.first;
	}
	return 1;
}
