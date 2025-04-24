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

inline bool solve() {
    int x, n;
    cin >> x;
    if (!cin) return false;
    cin >> n;

    vi c(n);
    FOR(i,0,n) {
        cin >> c[n-1-i];
    }

    vi dp(x+1, INF);

    dp[0] = 0;

    vector<vi> select(x+1);
    select[0];

    FOR(sum,1,x+1) {
        FOR(j,0,n) {
            if (sum - c[j] >= 0) {
                if (dp[sum] > dp[sum-c[j]]+1) {
                    dp[sum] = dp[sum-c[j]]+1;
                    select[sum].clear();
                    select[sum].PB(c[j]);
                    FOR(k,0,select[sum-c[j]].size())
                        select[sum].PB(select[sum-c[j]][k]);
                }
                
            }
        }
    }

    if (dp[x] == INF)
        cout << "Imposible\n";
    else {
        sort(all(select[x]));
        cout << dp[x] << ": ";
        ROF(i,0,select[x].size()) {
            cout << select[x][i];
            if (i!=0)
                cout << " ";
            else
                cout << "\n";
        }
    } 

    return true;
}

int main()
{
    // Optimizacion I/O
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(solve());
}