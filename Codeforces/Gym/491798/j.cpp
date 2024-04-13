#include <bits/stdc++.h>
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
#define ROF(i, a, b) for (int i = b - 1; i >= 0; i--)


umap<int, vi> changes;
umap<int, vector<ll>> weights;
umap<int, bool> visited;

ll maxWeight(int y, ll k, ll current) {
    if (current >= k)
        return current;

    ll maxPath = 0;

    FOR(i,0,changes[y].size()) {

        int next = changes[y][i];
        ll weight = weights[y][i];

        if (current+weight >= k)
            return current+weight;
        if (visited[next])
            return k;
        visited[next] = true;
        ll aux = maxWeight(next, k, current + weight);
        visited[next] = false;
        maxPath = max(maxPath, aux);
        if (maxPath >= k)
            return maxPath;
    }
    return maxPath ;

} 

void solve() {
    int n, m, y;
    ll k;
    cin >> n >> m >> k >> y;

    changes.clear();
    weights.clear();
    visited.clear();

    FOR(i,0,m) {
        int u, v, e;
        cin >> v >> u >> e;
        changes[u].PB(v);
        weights[u].PB(e);
    }

    visited[y] = true;
    if (maxWeight(y, k, 0) >= k)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main() {
    // Optimizacion I/O
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Usar archivos I/O, comentar al subir
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    // Número de casos
    int tc = 1;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        solve();
    }
}