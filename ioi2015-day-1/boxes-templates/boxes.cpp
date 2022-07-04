#include <bits/stdc++.h>
#include "boxes.h"
#define forn(i,n) for(int i = 0; i < n; i++)

using namespace std;
typedef long long ll;

void calculateCost (vector<ll> &cost, vector<ll> &anterior) {

}

long long delivery(int N, int K, int L, int p[]) {
    vector<pair<int,int>> placesAndCount;
    
    forn (i,n) {
        if (i > 0 && p[i-1] == p[i]) placesAndCount.back().second++;
        else placesAndCount.push_back({p[i], 1});
    }
    
}
