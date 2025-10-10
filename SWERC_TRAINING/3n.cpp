//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cmath>
//#include <map>
//#include <set>
//#include <stack>
#include <bits/stdc++.h>
using namespace std;   // Tipos
#define ll long long   // 64 bits INT
#define ld long double // 80 bits FP 


// Constantes
#define PI 3.1415926535897932384626433832795l
const int MAX_N = 1e5 + 5; // Valor de numero máximo de casos genérico
const ll MOD = 1e9 + 7;    // Para outputs grandes, a veces se piden darlos con este modulo. El modulo se puede aplicar en cada op. sin cambiar resultado
const ll INF = 1e9;        // Infinito
const ld EPS = 1e-9;       // Comparaciones de fp, e.g. if(abs(a-b) < EPS)

// Estructuras de datos
#define ar array        
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<vector<int>> graph;
typedef vector<vector<pair<int, int>>> wgraph; 
#define umap unordered_map
#define uset unordered_set
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define sza(x) ((int)x.size())  
#define all(a) (a).begin(), (a).end() // Aplicar a toda la estructura, e.g. sort(all(a))

// Bucles
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define ROF(i, a, b) for(int i = b-1; i>=0; i--)

#define MAX_N 1000000

umap<ll,int> memo;

int segment_tree[4*MAX_N];

int count(ll input) {
    if (input == 1)
        return 1;
    if (memo[input] != 0)
        return memo[input];
    if (input & 1) {
        memo[input] = 1 + count(3*input+1);
        return memo[input];
    }
    memo[input] = 1 + count(input / 2);
    return memo[input];
}

void build_segment_tree(int v, int tl, int tr) {
    if (tl == tr) {
        segment_tree[v] = count((ll)tl);
    } else {
        int tm = (tl + tr) / 2;
        build_segment_tree(v*2, tl, tm);
        build_segment_tree(v*2+1, tm+1, tr);
        segment_tree[v] = max(segment_tree[v*2], segment_tree[v*2+1]);
    }
}

int get_max(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return segment_tree[v];
    }
    int tm = (tl + tr) / 2;
    return max(get_max(v*2, tl, tm, l, min(r, tm)), get_max(v*2+1, tm+1, tr, max(l, tm+1), r));
}

bool solve() {
    int i, j;

    if (!cin)
        return false;

    cin >> i;

    if (!cin)
        return false;
    cin >> j;

    cout << i << " " << j << " " << get_max(1, 1, MAX_N, i, j) << endl;
    return true;
}

int main()
{
    // Optimizacion I/O
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    build_segment_tree(1, 1, MAX_N);


    while (solve());

}