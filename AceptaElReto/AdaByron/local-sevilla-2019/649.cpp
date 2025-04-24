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
    int N, M, T;
    cin >> N;
    if (!cin) return false;

    cin >> M >> T;


    // inicio fin periodo
    auto compare = [](const vector<int>& a, const vector<int>& b) {
        return a[0] > b[0]; // Min-heap: smallest `a[0]` comes first
    };

    // Priority queue with custom comparator
    priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> tareas(compare);


    FOR(i,0,N) {
        vi aux(3, -1);
        cin >> aux[0] >> aux[1];
        tareas.push(aux);
    }

    FOR(i,0,M) {
        vi aux(3);
        cin >> aux[0] >> aux[1] >> aux[2];
        tareas.push(aux);
    }

    int time = 0;
    while (time < T && !tareas.empty()) {
        vi curr = tareas.top();
        tareas.pop();
        if (curr[0] < time) {
            cout << "SI\n";
            return true;
        }
        time = curr[1];
        if (curr[2] != -1) {
            vi aux(3);
            aux[0] = curr[0] + curr[2];
            aux[1] = curr[1] + curr[2];
            aux[2] = curr[2];
            tareas.push(aux);
        }
    }

    cout << "NO\n";
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