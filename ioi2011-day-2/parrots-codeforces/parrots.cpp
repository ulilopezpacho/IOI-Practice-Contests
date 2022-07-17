#include <bits/stdc++.h>
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define DBG(x) cerr << #x << " = " << x << endl;
#include "parrotslib.h"

using namespace std;

const int bitsM = 8;

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

string numToString (int num) {
    string res;
    for (int i = 0; i < 8; i++){
        if (num % 2 == 1) res += "1";
        else res += "0";
        num/=2;
    }
    reverse(res.begin(), res.end());
    return res;
}

int stringToNum (string str) {
    int res = 0;
    forn (i, str.size()) {
        res *= 2;
        if (str[i] == '1') res += 1;
    }
    return res;
} 

pair<int,int> cantMensajesYBitsDedicadosAOrden (int N) {

    const int cantBitsMensaje = N*bitsM;
    int pow2 = 1;
    int cantMensajes = -1, bitsDedicadosAOrden = -1;

    for (int i = 0; i < 8; i++) {
        const int cantMensajesMax = pow2;
        const int cantidadMensajesNecesarios = (cantBitsMensaje+(8-i-1))/(8-i);

        if (cantidadMensajesNecesarios <= cantMensajesMax) {
            cantMensajes = cantidadMensajesNecesarios;
            bitsDedicadosAOrden = i;
            break;
        }
        pow2 *= 2;
    }

    assert(cantMensajes != -1);
    assert(bitsDedicadosAOrden != -1);

    return {cantMensajes, bitsDedicadosAOrden};
}

void encode (int N, int mInmutable[]) {
    
    int M[N];
    forn(i,N) M[i] = mInmutable[i]; 

    int cantMensajes, bitsDedicadosAOrden;
    tie(cantMensajes, bitsDedicadosAOrden) = cantMensajesYBitsDedicadosAOrden(N);

    int mensajeActual = 0, bitActual = 0;

    for (int j = 0; j < cantMensajes; j++) {
        
        int numeroMensaje = j;
        int valorAEnviar = numeroMensaje;

        forn (i, 8-bitsDedicadosAOrden) {
            valorAEnviar *= 2;
            if (bitActual == bitsM) {
                mensajeActual++;
                bitActual = 0;
                if (mensajeActual >= N) continue;
            }

            if (M[mensajeActual] % 2 == 1) valorAEnviar++;
            M[mensajeActual] /= 2;
            bitActual++;
        }

        send(valorAEnviar);
    }
}

void decode (int N, int L, int X[]) {

    vector<int> avesOrdenadas;
    forn (i, L) avesOrdenadas.push_back(X[i]);
    sort(avesOrdenadas.begin(), avesOrdenadas.end());

    int cantMensajes, bitsDedicadosAOrden;
    tie(cantMensajes, bitsDedicadosAOrden) = cantMensajesYBitsDedicadosAOrden(N);
    assert(L == cantMensajes);

    int mensajeActual = 0, bitActual = 0;

    vector<string> avesString;
    forn (i,L) avesString.push_back(numToString(avesOrdenadas[i]));
    string numeroActual = "";

    for (int j = 0; j < cantMensajes; j++) {
        for (int i = bitsDedicadosAOrden; i < 8; i++) {

            if (avesString[j][i] == '1') numeroActual += '1';
            else numeroActual += '0';
            bitActual++;

            if (bitActual == bitsM) {
                mensajeActual++;
                bitActual = 0;

                reverse(numeroActual.begin(), numeroActual.end());
                output(stringToNum(numeroActual));
                numeroActual = "";
            }
        }
    }
}