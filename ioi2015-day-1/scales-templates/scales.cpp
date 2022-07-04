#include "scales.h"
#include <vector>
#include <iostream>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define DBG(x) cerr << #x << " = " << x << endl

using namespace std;

int t;

void init(int T) {
    t = T;
}

void orderCoins() {

    int W[] = {0, 0, 0, 0, 0, 0};

    const int heaviestLeft = getHeaviest(1,2,3);
    const int lightestLeft = getLightest(1,2,3);
    const int medLeft = 6 - (heaviestLeft + lightestLeft);

    vector<int> insertArray = {heaviestLeft, medLeft, lightestLeft};
    vector<vector<int>> toInsert (4);

    const int heaviestRight = getHeaviest(4,5,6);
    const int lightestRight = getLightest(4,5,6);
    const int medRight = 15 - (heaviestRight + lightestRight);

    toInsert[getNextLightest(1,2,3,lightestRight)].push_back(lightestRight);
    toInsert[getNextLightest(1,2,3,medRight)].push_back(medRight);
    toInsert[getNextLightest(1,2,3,heaviestRight)].push_back(heaviestRight);

    vector<int> begin, end;
    bool ahorrar = false;

    for (const int a: toInsert[lightestLeft]) {
        if (!ahorrar) {
            const int temp = getLightest(a, lightestLeft, heaviestLeft);
            if (temp == a) begin.push_back(a);
            else {
                end.push_back(a);
                ahorrar = true;
            }
        }
        else end.push_back(a);
    }

    int i = 0, loop = 0;
    vector<vector<int>> iterateArrays = {begin, toInsert[medLeft], toInsert[heaviestLeft], end};
    for (vector<int> v: iterateArrays) {
        for (int a: v) W[i++] = a;
        switch (loop) {
        case 0:
            W[i++] = lightestLeft;
            break;
        case 1:
            W[i++] = medLeft;
            break;
        case 2:
            W[i++] = heaviestLeft;
            break;
        }
        loop++;
    }
 
    answer(W);
}
