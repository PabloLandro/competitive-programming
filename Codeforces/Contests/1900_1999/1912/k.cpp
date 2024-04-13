#include <bits/stdc++.h>
using namespace std;   // Tipos
#define ll long long   // 64 bits INT
#define ld long double // 80 bits FP 


// Constantes
#define PI 3.1415926535897932384626433832795l
const int MAX_N = 1e5 + 5; // Valor de numero máximo de casos genérico
const ll MOD = 998244353;    // Para outputs grandes, a veces se piden darlos con este modulo. El modulo se puede aplicar en cada op. sin cambiar resultado
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

int n;
vi v;



umap<int,bool> visitedEE;
umap<int,bool> visitedOE;
umap<int,bool> visitedOO;
umap<int,bool> visitedEO;

umap<int, ll> valueEE;
umap<int, ll> valueOE;
umap<int, ll> valueOO;
umap<int, ll> valueEO;

int ans(int index, bool even1, bool even2, bool even3) { 
    if (even1 != (v[index]%2 == 0))
        return 0;
    if (index == n-1)
        return 1;
    if (even2) {
        if (even3 && visitedEE[index])
            return valueEE[index];
        if (visitedEO[index])
            return valueEO[index];
    } else {
        if (even3 && visitedOE[index])
            return valueOE[index];
        if (!even3 && visitedOO[index])
            return valueOO[index];
    }

    ll out = 1;
    int currEven = even1 == (v[index]%2==0);
    FOR(i,index+1,n) {
        ll val = ans(i, even2, even3, currEven);
        if (even2 && even3) {
            visitedEE[i] = true;
            valueEE[i] = val;
        } else if (even2 & !even3){
            visitedEO[i] = true;
            valueEO[i] = val;
        } else if (!even2 && even3) {
            visitedOE[i] = true;
            valueOE[i] = val;
        } else {
            visitedOO[i] = true;
            valueOO[i] = val;
        }
        out = (out+val) % MOD;
    }
    return out;
}

void solve() {
    cin >> n;

    v.resize(n);

    FOR(i,0,n) {
        int curr;
        cin >> curr;
        v[i] = curr%2;
    }

    ll out = 0;

    FOR(i,0,n) {
        bool aux = v[i] % 2 == 0;
        FOR(j,i+1,n) {
            FOR(k,j+1,n) {
                if (((v[i]+v[j]+v[k])%2 != 0))
                    continue;
                out = (out+1)%MOD;
                FOR(l,k+1,n) {
                    out = (out + ans(l, aux, v[j]%2==0, v[k]%2==0)) % MOD;
                }
            }
        }
    }

    cout << out << '\n';
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