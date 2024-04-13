#include <bits/stdc++.h>
#include <algorithm>
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
#define ROF(i, a, b) for(int i = b; i>=0; i--)




void solve() {
    int n;
    cin >> n;
    vector<ll> v(n);
    ll jump = 0, x, ans;
    bool chosen = false;
    int k = 1;
    FOR(i,0,n)
        cin >> v[i];

    sort(v.begin(),v.end());
    if (n == 1) {
        cout << 1 << '\n';
        return;
    }

    
    FOR(i,0,n) {
        jump = __gcd(jump,v[n-1]-v[i]);
    }
    jump = max(jump, (ll)1);

    
    x = v[n-1]-jump;
    
    ROF(i,0,n-2) {
        if(x!=v[i])break;
		x-=jump;k++;
    }
    ans = k;
    FOR(i,0,n-1) {
        ans += (v[n-1]-v[i]) / jump;
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
     //freopen("output.txt", "w", stdout);

    // Número de casos
    int tc = 1;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        solve();
    }
}