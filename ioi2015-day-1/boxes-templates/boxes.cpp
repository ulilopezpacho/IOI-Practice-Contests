#include <bits/stdc++.h>
#include "boxes.h"
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define DBG(x) cerr << #x << " = " << x << endl

using namespace std;
typedef long long tint;

template<typename T>
ostream &operator << (ostream &os, vector<T> &v) {
	os << "[";
	forn (i,v.size()) {
		if (i != 0) os << ", ";
		os << v[i];
	}
	os << "]";
	return os;
}

vector<tint> tablaDP (vector<tint> v, int mod) {
    int ln = v.size();
    vector<tint> ans (ln);
    forn (i, v.size()) {
        if (i < mod) ans[i] = v[i] * 2;
        else ans[i] = ans[i-mod] + v[i] * 2;
    }
    return ans;
}

long long delivery(int N, int K, int L, int p[]) {

    tint ans = 2e18;

    vector<tint> pos (N), posInv (N);
    forn (i, N) pos[i] = tint(p[i]);
    forn (i, N) posInv[i] = tint(L - pos[i]);
    reverse(posInv.begin(), posInv.end());

    vector<tint> tablaDer = tablaDP(pos, K), tablaIzq = tablaDP(posInv, K);
    
    tablaDer.insert(tablaDer.begin(), 0);
    reverse(tablaIzq.begin(), tablaIzq.end());
    tablaIzq.push_back(0);

    for (int i = 0; i < int(tablaDer.size()); i++) {
        if (i+K < int(tablaDer.size())) ans = min(ans, tablaDer[i] + L + tablaIzq[i+K]);
        else ans = min(ans, tablaDer[i] + L);
        ans = min(ans, tablaDer[i] + tablaIzq[i]);
    }

    return ans;
}
