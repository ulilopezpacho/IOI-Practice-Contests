#include <bits/stdc++.h>
#include "boxes.h"
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define DBG(x) cerr << #x << " = " << x << endl

using namespace std;
typedef long long ll;

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

long long delivery(int N, int K, int L, int p[]) {

    ll result = 2e18;
    vector<ll> inVector;
    forn (i, N) inVector.push_back(p[i]);
    sort(inVector.begin(), inVector.end());

    forn (i, N+1) {
        ll accum = 0;
        ll costIda = 0;

        for (int j = 0; j < i; j++) {
            if ((++accum % K) == 0) costIda += 2 * inVector[j];
        }
        if (i > 0 && (accum % K) != 0) costIda += 2 * inVector[i-1];

        accum = 0;
        ll costVuelta = 0;

        for (int j = N-1; j >= i; j--) {
            if ((++accum % K) == 0) costVuelta += 2 * (ll(L) - inVector[j]);
        }
        DBG("=====");
        DBG(costVuelta);
        DBG(accum%K);
        if (i < N && (accum % K) != 0) costVuelta += 2 * (ll(L) - inVector[i]);

        DBG(costIda);
        DBG(costVuelta);
        result = min(result, costIda + costVuelta);
        DBG(result);
    }

    return result;
}
