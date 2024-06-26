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

vi memo(101,-1);

int fact(int a) {
    if (memo[a] != -1)
        return memo[a];
    if (a == 0)
        return 1;
    
    memo[a] = (a * fact(a-1))%MOD;
    return memo[a];
}

int combinations(vi in) {
    int total = 0;
    int divisor = 1;
    FOR(i,0,in.size()) {
        total += in[i];
        divisor *= fact(in[i]);
    }
    return fact(total) / divisor;
}

bool solve() {
    int n, k;
    cin >> n;

    if (n == 0)
        return false;

    cin >> k;

    vi peld(k);

    FOR(i,0,k) {
        cin >> peld[i];
    }

    sort(all(peld));

    stack<pair<pi, vi>> st;

    vi aux(k);

    st.push(MP(MP(n,k), aux));

    int ans = 0;

    while (!st.empty()) {
        int curr = st.top().F.F;
        int l = st.top().F.S;
        vi count = st.top().S;
        st.pop();
        FOR(i,0,l) {
            vi aux = count;
            if (curr - peld[i] > 0) {
                aux[i] = aux[i]+1;
                st.push(MP(MP(curr-peld[i], i+1), aux));
            }
            else if (curr-peld[i] == 0) {
                aux[i] = aux[i]+1;
                ans = (ans+combinations(aux))%MOD;
            }
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