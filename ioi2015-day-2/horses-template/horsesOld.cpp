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

vector<int> longestSub (const vector<int> &seq) {
    int nl = int(seq.size());
    vector<int> ans;
    forn (i, nl) {
        while (!ans.empty() && seq[ans.back()] <= seq[i]) ans.pop_back();
        ans.push_back(i);
    }
    return ans;
}

int getResult () {
    tint res = 0;
    vector<int> dondeVender = longestSub(prize);
    tint accum = 1; int it = 0;
    forn (i,n) {
        accum = ((accum % MOD) * (multiplyBy[i] % MOD)) % MOD;
        if (dondeVender[it] == i) {
            res = (((((accum - (i == n-1 ? 0: 1)) % MOD) * (prize[i] % MOD)) % MOD) + res) % MOD;
            accum = 1; it++;
        }
    }
    return int(res % MOD);
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
