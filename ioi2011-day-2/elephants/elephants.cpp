#include <bits/stdc++.h>
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define DBG(x) cerr << #x << " = " << x << endl;
#include "grader.h"

using namespace std;

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

int camara, cantElefantes;
vector<pair<int,int>> elefantesActual;

void swapSortElefantes () {
    for (int i = 1; i < int(elefantesActual.size()); i++) {
        if (i == 0) continue;
        if (elefantesActual[i].first < elefantesActual[i-1].first)
            swap(elefantesActual[i], elefantesActual[i-1]);
    }

    for (int i = int(elefantesActual.size())-1; i > 0; i--) {
        if (elefantesActual[i].first < elefantesActual[i-1].first)
            swap(elefantesActual[i], elefantesActual[i-1]);
    }
}

void init (int N, int L, int X[]) {
    camara = L;
    cantElefantes = N;
    elefantesActual.resize(N);
    forn (i, cantElefantes) elefantesActual[i] = {X[i], i};
}

int update (int i, int y) {
    int posReal = -1;
    forn (j, cantElefantes) {
        if (elefantesActual[j].second == i) {
            elefantesActual[j].first = y;
        }
    }
    swapSortElefantes();

    int primeroAnterior = elefantesActual[0].first;
    int cantidadCamaras = 1;

    for (int i = 1; i < cantElefantes; i++) {
        if (elefantesActual[i].first - primeroAnterior > camara) {
            primeroAnterior = elefantesActual[i].first;
            cantidadCamaras++;
        }
    }

    return cantidadCamaras;
}