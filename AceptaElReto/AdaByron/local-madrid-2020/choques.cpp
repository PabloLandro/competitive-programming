#include <bits/stdc++.h>
using namespace std;   // Tipos
#define ll long long   // 64 bits INT
#define ld long double // 80 bits FP 


// Constantes
#define PI 3.1415926535897932384626433832795l
const int MAX_N = 1e5 + 5; // Valor de numero máximo de casos genérico
const ll MOD = 1e9 + 7;    // Para outputs grandes, a veces se piden darlos con este modulo. El modulo se puede aplicar en cada op. sin cambiar resultado
const ll INF = 2*1e9 + 5;        // Infinito
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
    int n;

    cin >> n;

    if (n == 0)
        return false;

    priority_queue<pi, vector<pi>, greater<pi>> queue;
    FOR(i,0,n) {
        int x, v;
        cin >> x >> v;
        queue.push(MP(x,v));
    }

    int prev_x = queue.top().F, prev_v = queue.top().S;
    queue.pop();

    int ans = INF;
    bool colision = false;
    FOR (i,1,n) {
        pi curr = queue.top();
        queue.pop();
        int x = curr.F, v = curr.S;
        int dist = x - prev_x;
        int speed = v - prev_v;
        prev_x = x;
        prev_v = v;

        if (dist == 0) {
            colision = true;
            ans = 0;
        }


        if (speed >= 0)
            continue;
        speed *= -1;
        colision = true;
        int t = dist / speed;
        ans = min(t, ans);
    }
    if (!colision)
        cout << "SIN COLISION\n";
    else
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