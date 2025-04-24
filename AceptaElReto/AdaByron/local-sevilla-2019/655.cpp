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
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
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

vector<vector<pll>> adj;

void dijkstra(int s, vector<ll>& d, vector<ll>& p) {
    int n = adj.size();
    d[s] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> q;
    q.push({0, s});
    while (!q.empty()) {
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
        continue;
        for (auto edge : adj[v]) {
            int to = edge.first;
            ll len = edge.second;
            if (d[v] + len < d[to] || (d[v] + len == d[to] && ((p[to] > v) || (s == p[to] && v > p[to])))) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}   

bool solve() {
    int N, M;
    cin >> N >> M;
    if (N == 0 && M == 0)
        return false;

    adj.clear();
    adj.resize(N);

    vector<bool> origenes(N,true);
    vector<bool> destinos(N,true);


    FOR(i,0,M) {
        int o, d, p;
        cin >> o >> d >> p;
        o--; d--;
        origenes[d]=false;
        destinos[o]=false;
        adj[o].PB(MP(d,-p));
    }

    FOR(i,0,N) {
        sort(all(adj[i]));
        reverse(adj[i].begin(), adj[i].end());
    }

    vll d(N,INF);
    vll p(N,-1);

    ROF(i,0,N) {
        if (!origenes[i])
            continue;
        dijkstra(i,d,p);
    }

    int big = 0, idx=-1;

    FOR(i,0,N) {
        if (!destinos[i])
            continue;
        if (big < -d[i]) {
            big = -d[i];
            idx = i;
        }
    }

    cout << big << "\n";
    vll out;
    while(idx != -1) {
        out.PB(idx+1);
        idx = p[idx];
    }
    ROF(i,0,out.size()) {
        cout << out[i];
        if (i != 0)
            cout << " ";
    }
    cout << "\n";

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

    while(solve());
}