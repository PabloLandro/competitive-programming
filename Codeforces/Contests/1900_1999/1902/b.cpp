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

ll divCel(ll a, ll b) {
    return (a+b-1) / b;
}

void solve() {
    ll n, l, t, P;
    cin >> n >> P >> l >> t;
    ll tasks = divCel(n, 7);
    ll ans = n;

    ll d2 = (2*t) + l;
    ll d1 = t + l;
    ll d0 = l;

    if ((tasks %2 == 0)) {
        if (P >= (tasks/2) * d2) {
            P -= (tasks/2) * d2;
            ans -= tasks / 2;
            //cout << (tasks/2) << "d2" << endl;
            tasks = 0;
        } else {
            ans -= divCel(P, d2);
            //cout << divCel(P, d2) << "d2" << endl;
            P = 0;
        }
    } else {
        if (P >= ((tasks-1)/2) * d2) {
            P -= ((tasks-1)/2) * d2;
            ans -= (tasks-1) / 2;
            //cout << ((tasks-1) / 2) << "d2" << endl;
            tasks = 1;
        } else {
            //cout << divCel(P, d2) << "d2" << endl;
            ans -= divCel(P, d2);
            P = 0;
        }
    }
    if (P > 0 && tasks == 1) {
        ans--;
        P -= d1;
        //cout << "1d1" << endl;
        tasks = 0;
    }
    if (P > 0) {
        //cout << divCel(P, d0) << "d0" << endl;
        ans -= divCel(P, d0);
        P = 0;
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