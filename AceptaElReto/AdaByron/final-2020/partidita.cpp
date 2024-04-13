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

void solve() {
    int L, N;

    cin >> L >> N;

    int curr_hour = 8;
    int curr_minutes = 0;

    int ans = 0;

    FOR (i,0,N) {
        string time;
        cin >> time;
        int hours = stoi(time.substr(0,2));
        int minutes = stoi(time.substr(3));

        int idle = (hours*60 + minutes) - (curr_hour*60 + curr_minutes);

        if (idle >= L)
            ans += idle;
        //cout << idle << '\n';
        int duration;
        cin >> duration;

        

        int aux = minutes + duration;

        curr_hour = hours + aux/60;
        curr_minutes = aux % 60;
        
        //cout << "starts at " << hours << ':' << minutes <<'\n';
        //cout << "lasts " << duration << " minutes\n";
        //cout << "finishes at " << curr_hour << ':' << curr_minutes << '\n';
    }

    int idle = (14*60) - (curr_hour*60 + curr_minutes);

    if (idle >= L)
        ans += idle;

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