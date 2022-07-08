#include <bits/stdc++.h>
#include "horses.h"
#define DBG(x) cerr << #x << " = " << x << endl
#define forn(i,n) for(int i = 0; i < int(n); i++)

using namespace std;
typedef long long tint;

const tint MOD = 1e9+7;

int n;
vector<int> prize;
vector<int> multiplyBy;

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

int getResult () {
    tint accumulator = 1;
    tint result = -1;
    forn (i, n) {
        accumulator = ((accumulator % MOD) * (multiplyBy[i] % MOD)) % MOD;
        if (prize[i] / multiplyBy[i] > 0) result = ((accumulator % MOD) * (prize[i] % MOD)) % MOD;
    }
    return int(result%MOD);
}

int init(int N, int X[], int Y[]) {
    n = N;
    multiplyBy.resize(N);
    prize.resize(N);
    forn (i,n) multiplyBy[i] = X[i];
    forn (i,n) prize[i] = Y[i];
    return getResult();
}

int updateX(int pos, int val) {
    multiplyBy[pos] = val;
    return getResult();
}

int updateY(int pos, int val) {
    prize[pos] = val;
    return getResult();
}
