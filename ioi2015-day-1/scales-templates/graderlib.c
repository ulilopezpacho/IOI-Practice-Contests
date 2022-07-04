#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "scales.h"

#define MAXN 6
#define MAX_ANSWER_CALLS 1

#define fail(s, x...) do { \
        fprintf(stderr, s "\n", ## x); \
        exit(1); \
    } while(0)

static int _realC[MAXN];
static int _ind[MAXN];
static int _numQueries;
static int _numAnswerCalls;
static FILE * _f;
static FILE * _of;

int _getNumberOfTests() {
    int T;

    _f = fopen("scales.in", "r");
    if (!_f)
        fail("Failed to open input file.");
    
    _of = fopen("scales.out", "w");
    if (!_of)
        fail("Failed to open output file.");

    fscanf(_f, "%d", &T);
    return T;
}

void _initNewTest() {    
    int i;

    for (i = 0; i < MAXN; i++) {
        fscanf(_f, "%d", &_realC[i]);
        _realC[i]--;
        _ind[_realC[i]] = i;
    }

    _numQueries = 0;
    _numAnswerCalls = 0;
}

void answer(int C[]) {
    int i;

    for (i = 0; i < 6; i++)
        fprintf(_of, "%d ", C[i]);
    fprintf(_of, "\n"); 
}

void _checkQuery(int A, int B, int C, int D) {
    if (D == -1) {
        if (A < 1 || A > 6 || B < 1 || B > 6 || C < 1 || C > 6)
            assert(0);
        if (A == B || B == C || A == C)
            assert(0);
    }
    else {
        if (A < 1 || A > 6 || B < 1 || B > 6 || C < 1 || C > 6 || D < 1 || D > 6)
            assert(0);
        if (A == B || A == C || A == D || B == C || B == D || C == D)
            assert(0);
    }
}

int getMedian(int A, int B, int C) {
    _numQueries++;
    _checkQuery(A, B, C, -1);

    A--; B--; C--;

    if (_ind[B] < _ind[A] && _ind[A] < _ind[C])
        return A + 1;

    if (_ind[C] < _ind[A] && _ind[A] < _ind[B])
        return A + 1;

    if (_ind[A] < _ind[B] && _ind[B] < _ind[C])
        return B + 1;

    if (_ind[C] < _ind[B] && _ind[B] < _ind[A])
        return B + 1;

    return C + 1;
}

int getHeaviest(int A, int B, int C) {
    _numQueries++;
    _checkQuery(A, B, C, -1);    

    A--; B--; C--;

    if (_ind[A] > _ind[B] && _ind[A] > _ind[C])
        return A + 1;

    if (_ind[B] > _ind[A] && _ind[B] > _ind[C])
        return B + 1;

    return C + 1;
}

int getLightest(int A, int B, int C) {
    _numQueries++;
    _checkQuery(A, B, C, -1);

    A--; B--; C--;

    if (_ind[A] < _ind[B] && _ind[A] < _ind[C])
        return A + 1;
    
    if (_ind[B] < _ind[A] && _ind[B] < _ind[C])
        return B + 1;

    return C + 1;
}

int getNextLightest(int A, int B, int C, int D) {
    int allLess = 1;    

    _numQueries++;
    _checkQuery(A, B, C, D);

    A--; B--; C--; D--;

    if (_ind[A] > _ind[D] || _ind[B] > _ind[D] || _ind[C] > _ind[D])
        allLess = 0;

    if (allLess == 1) {
        if (_ind[A] < _ind[B] && _ind[A] < _ind[C])
            return A + 1;
    
        if (_ind[B] < _ind[A] && _ind[B] < _ind[C])
            return B + 1;

        return C + 1;
    }

    if (_ind[A] > _ind[D]) {
        if ((_ind[A] < _ind[B] || _ind[B] < _ind[D]) && (_ind[A] < _ind[C] || _ind[C] < _ind[D]))
            return A + 1;
    }

    if (_ind[B] > _ind[D]) {
        if ((_ind[B] < _ind[A] || _ind[A] < _ind[D]) && (_ind[B] < _ind[C] || _ind[C] < _ind[D]))
            return B + 1;
    }

    return C + 1;
}
