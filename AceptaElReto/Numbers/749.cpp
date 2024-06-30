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

bool solve() {
    ll c,f,h;
    cin >> c >> f >> h;

    if (c == 0 && f == 0 && h == 0)
        return false;

    ll ans = (c-1) * f + c*(f-1);

    set<pi> destroyed_hor;
    set<pi> destroyed_ver;

    FOR(k,0,h) {
        int i, j;
        cin >> j >> i;
        
        // Horizontal derecha
        if (j < c && destroyed_hor.find(MP(i,j)) == destroyed_hor.end()) {
            destroyed_hor.insert(MP(i,j));
            ans--;
        }
        
        // Horizontal izquierda
        if (j > 1 && destroyed_hor.find(MP(i,j-1)) == destroyed_hor.end()) {
            destroyed_hor.insert(MP(i,j-1));
            ans--;
        }

        // Vertical abajo
        if (i < f && destroyed_ver.find(MP(i,j)) == destroyed_ver.end()) {
            destroyed_ver.insert(MP(i,j));
            ans--;
        }

        // Vertical arriba
        if (i > 1 && destroyed_ver.find(MP(i-1,j)) == destroyed_ver.end()) {
            destroyed_ver.insert(MP(i-1,j));
            ans--;
        }

    }

    cout << ans << '\n';

    return true;
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

    while (solve()) {}
}