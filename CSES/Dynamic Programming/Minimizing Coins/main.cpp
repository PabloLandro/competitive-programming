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

int main()
{
    int n, x;
    cin >> n >> x;

    //umap<int,ll> count;
    vector<ll> count(x+1);

    vi coins(n);
    FOR(i,0,n)
        cin >> coins[i];
    count[0] = 0;
    FOR(i,1,x+1) {
        count[i] = INF;
        FOR (j,0,n) {
            int val= coins[j];
            if (i - val >= 0)
                count[i] = min(count[i], 1 + count[i-val]);
        }
    }

    if (count[x] == INF)
        cout << -1 << endl;
    else
        cout << count[x] << endl;
}