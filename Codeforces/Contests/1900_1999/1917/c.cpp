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

int getCount(int n) {
    return floor(n/2);
}

void solve() {
    int n, k, d;
    cin >> n >> k >> d;

    vi a(n),b(k);

    int c = 0;

    FOR(i,0,n) {
        cin >> a[i];
        if (a[i] == i+1)
            c++;
    }

    FOR(i,0,k) cin >> b[i];

    int m = min(d,(2*n)+1);
    int ans = getCount(d-1);
    ans += c;
    FOR(i,0,m) {
        c = 0;

        FOR(j,0,n) {
            if (a[j] == j+1)
                c++;   
        }
        ans = max(ans, c+getCount(d-i-1));
        FOR(j,0,b[i%k]) {
            a[j]++;
        }
    }

    cout << ans << '\n';
    
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

    // Número de casos
    int tc = 1;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        solve();
    }
}