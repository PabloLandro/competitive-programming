#include <bits/stdc++.h>

#include <string>
using namespace std;    // Tipos
#define ll long long    // 64 bits INT
#define ld long double  // 80 bits FP

// Constantes
#define PI 3.1415926535897932384626433832795l
const int MAX_N = 1e5 + 5;  // Valor de numero máximo de casos genérico
const ll MOD =
    1e9 + 7;  // Para outputs grandes, a veces se piden darlos con este modulo.
              // El modulo se puede aplicar en cada op. sin cambiar resultado
const ll INF = 1e9;   // Infinito
const ld EPS = 1e-9;  // Comparaciones de fp, e.g. if(abs(a-b) < EPS)

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
#define all(a) \
    (a).begin(), (a).end()  // Aplicar a toda la estructura, e.g. sort(all(a))

// Bucles
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ROF(i, a, b) for (int i = b - 1; i >= a; i--)

bool isPerfectSquare(int num) {
    if (num < 0) {
        return false;  // Negative numbers are not perfect squares
    }

    int sqrtNum = static_cast<int>(sqrt(num));

    return (sqrtNum * sqrtNum == num);
}

int isValid(int n, int d) {
    int aux = 1 + 8*d + 4*n*(n+1);
    if (isPerfectSquare(aux)) {
        int root = static_cast<int>(sqrt(aux));
        if ((aux-1) % 2 == 0)
            return aux/2;
    }
    return -1;
}

void solve() {
    int d;

    cin >> d;
    vector<pi> sol;
    ROF(n,1,d) {
        int m = isValid(n, d);
        if (m != -1)
            sol.PB(MP(n,m));
    }
    
    FOR(i,0,sol.size()) {
        cout << sol[i].F << " " << sol[i].S << endl;
    }

}

int main() {
    // Optimizacion I/O
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Usar archivos I/O, comentar al subir
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    solve();
}