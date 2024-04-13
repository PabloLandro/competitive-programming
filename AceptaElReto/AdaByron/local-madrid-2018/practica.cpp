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
    int R, N;

    cin >> R;

    if (!cin)
        return false;

    cin >> N;

    vi clave(R);
    vi progress(R,-1);
    map<int,int> dict;
    map<int,bool> es_clave;
    FOR(i,0,R) {        
        cin >> clave[i];
        dict[clave[i]] = i;
        es_clave[clave[i]] = true;
    }

    int curr;
    int ans = N;
    FOR(i,0,N) {
        cin >> curr;
        if (es_clave[curr]) {
            if (dict[curr] == 0)
                progress[0] = i;
            else if ((dict[curr] == R-1) && progress[dict[curr]-1] != -1)
                ans = min(ans, 1+i-progress[R-2]);
            else if (progress[dict[curr]-1] != -1)
                progress[dict[curr]] = progress[dict[curr]-1];
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
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    while (solve()) {}
}