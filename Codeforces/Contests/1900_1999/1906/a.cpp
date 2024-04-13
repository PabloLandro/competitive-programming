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

vector<string> v;

char bestPair(int i, int j, int notI, int notJ) {
    char best = 'C';
    FOR(k,-1,2) {
        FOR(l,-1,2) {
            if ((k+i) < 0 || (k+i) > 2 || (j+l) < 0 || (j+l) > 2 || (k==0 && l==0) || ((i+k == notI) && (j+l==notJ)))
                continue;
            if (v[i+k][j+l] <= best) {
                best = v[i+k][j+l];
            }
        }
    }
    return best;
}


string bestCombination(int i, int j) {
    string best = "CC";
    FOR(k,-1,2) {
        FOR(l,-1,2) {
            if ((k+i) < 0 || (k+i) > 2 || (j+l) < 0 || (j+l) > 2 || (k==0 && l==0))
                continue;
            string curr = string(1,v[i+k][j+l]) + string(1,bestPair(i+k,j+l,i,j));
            if (curr <= best) {
                best = curr;
            }
        }
    }
    return best;
}


void solve() {
    v.resize(3);
    FOR(i,0,3) {
        FOR(j,0,3) {
            char curr;
            cin >> curr;
            v[i].PB(curr);
        }
    }

    string best = "CCC";

    FOR(i,0,3) {
        FOR(j,0,3) {
            string curr = string(1,v[i][j]) + bestCombination(i,j);
            if (curr <= best)
                best = curr;
        }
    }

    cout << best << '\n';

}

int main()
{
    // Optimizacion I/O
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Usar archivos I/O, comentar al subir
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    solve();
}