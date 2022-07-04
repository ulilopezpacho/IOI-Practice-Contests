#include <bits/stdc++.h>
#include "boxes.h"
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define DBG(x) cerr << #x << " = " << x << endl

using namespace std;
typedef long long ll;

ll cuantasVecesVolver (ll sumaParcial, ll cantidadActual, ll k) {
    int paraCompletar = (sumaParcial % k) + cantidadActual;
    return paraCompletar / k;
}

void calculateCost (vector<pair<ll,ll>> &placesAndCount, vector<ll> &cost, vector<ll> &anterior, ll k) {
    int n = int(placesAndCount.size());

    vector<int> sumasParciales (n);
    cost.resize(n);
    anterior.resize(n);

    forn (i, n) {
        pair<ll,ll> p = placesAndCount[i];

        if (i == 0) {
            sumasParciales[i] = p.second;
            cost[i] = cuantasVecesVolver(0, p.second, k) * p.first;
            anterior[i] = sumasParciales[i] % k == 0 ? 0 : p.first;
            continue;
        }

        sumasParciales[i] = sumasParciales[i-1] + p.second;
        cost[i] = cost[i-1] + cuantasVecesVolver(sumasParciales[i-1], p.second, k) * p.first + (p.first - anterior[i-1]);
        anterior[i] = sumasParciales[i] % k == 0 ? 0 : p.first;
    }
}

long long delivery(int N, int K, int L, int p[]) {
    
    ll result = 1e18;
    vector<pair<ll,ll>> placesAndCount;

    forn (i,N) {
        if (i > 0 && p[i-1] == p[i]) placesAndCount.back().second++;
        else placesAndCount.push_back({p[i], 1});
    }

    vector<ll> cost1, anterior1, cost2, anterior2;
    calculateCost(placesAndCount, cost1, anterior1, K);
    reverse(placesAndCount.begin(), placesAndCount.end());

    forn (i, placesAndCount.size()) placesAndCount[i].first = L - placesAndCount[i].first;
    calculateCost(placesAndCount, cost2, anterior2, K);

    reverse(cost2.begin(), cost2.end());
    reverse(anterior2.begin(), anterior2.end());

    forn (i, placesAndCount.size()) {
        if (i == 0) result = min(result, cost2[i] + anterior2[i]);
        else if (i == (ll(placesAndCount.size()) - 1)) result = min(result, cost1[i] + anterior1[i]);
        else {
            result = min(result, cost1[i-1] + anterior1[i-1] + cost2[i] + anterior2[i]);
            result = min(result, cost1[i] + anterior1[i] + cost2[i-1] + anterior2[i-1]);
        }
    }

    return result;
}
