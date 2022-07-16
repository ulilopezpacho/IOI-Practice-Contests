#include <bits/stdc++.h>
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define DBG(x) cerr << #x << " = " << x << endl;
#include "grader.h"

using namespace std;

vector<vector<pair<int,int>>> g;
vector<int> cantVisitado, minimos;
set<int> salidas;

template<typename T>
ostream &operator<< (ostream &os, vector<T> v) {
    os << "[";
    forn (i, v.size()){
        if (i > 0) os << ", ";
        os << v[i];
    }
    os << "]";
    return os;
}

template<typename T>
ostream &operator<< (ostream &os, pair<T,T> p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

int travel_plan (int N, int M, int R[][2], int L[], int K, int P[]) {

    g.resize(N);
    cantVisitado.resize(N,0);
    minimos.resize(N);

    forn (i,M) {
        g[R[i][0]].push_back({R[i][1], L[i]});
        g[R[i][1]].push_back({R[i][0], L[i]});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    forn (i, K) {
        q.push({0,P[i]});
        salidas.insert(P[i]);
    }

    while (!q.empty()) {
        
        int w, node;
        tie(w, node) = q.top(); q.pop();

        if (++cantVisitado[node] > 2) continue;
        minimos[node] = w;

        if ((w == 0 && salidas.count(node) > 0) || (salidas.count(node) == 0 && cantVisitado[node] == 2)) {
            if (node == 0) return minimos[node];

            for (auto &e: g[node]) {
                if (cantVisitado[e.first] < 2) {
                    q.push({e.second + minimos[node], e.first});
                }
            }
        }
    }

    return 1e9;
}
/*
int main () {
    int N, M, K;
    cin >> N >> M >> K;
    int R [M][2], L[M], P[K];

    forn (i, M) cin >> R[i][0] >> R[i][1] >> L[i];
    forn (i, K) cin >> P[i];

    cout << travel_plan(N, M, R, L, K, P);
}
*/