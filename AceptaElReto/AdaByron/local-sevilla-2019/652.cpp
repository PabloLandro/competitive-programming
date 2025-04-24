#include <bits/stdc++.h>
#include <string>
#include <iostream>
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
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define ROF(i, a, b) for(int i = b-1; i>=0; i--)

umap<int, int> memo;
umap<int, int> reverse_memo;

bool solve() {
    ll a, b;
    cin >> a;

    if (!cin)
        return false;
    cin >> b;

    ll A = (ll)reverse_memo[a], B = (ll)reverse_memo[b];

    ll Out = A*B;

    cout << memo[Out] << "\n";

    return true;
}

int main()
{
    // Optimizacion I/O
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll curr = 0;
    FOR(i,1,100000) {
        curr++;
        int aux = i;
        int expo = 0;
        while (aux > 0) {
            int digit = aux % 10; // Get the last digit
            aux /= 10; // Remove the last digit
            if (digit==5) {
                curr += pow(10,expo);
            }
            expo++;
        }
        memo[i] = curr;

        reverse_memo[curr] = i;
    }

    FOR(j,1,100) {
        string sa = to_string(j);
        int na = 0;
        int pow = 1;
        for(int i = sa.length()-1; i>=0; i--) {
            if(sa[i] > '5') sa[i]--;
            na += ((int) (sa[i] - '0')) * pow;
            pow *= 9;
        }
        if (reverse_memo[j] != na)
            cout << "(" << j << ") " << reverse_memo[j] << " != " << na << endl;
    }

    //while(solve());
}