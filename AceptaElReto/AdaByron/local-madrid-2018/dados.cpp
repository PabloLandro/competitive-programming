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
    int n;

    cin >> n;

    if (!n)
        return false;

    vi primero(n);
    vi segundo(n);
    //cout << "0" << endl;
    FOR(i,0,n)
        cin >> primero[i];
    //cout << "1" << endl;
    FOR(i,0,n)
        cin >> segundo[i];
    //cout << "2" << endl;

    sort(all(primero));
    reverse(all(primero));

    sort(all(segundo));
    reverse(all(segundo));

    int opciones_primero = 0;
    //cout << "firstloop" << endl;
    int index = 0;
    FOR(i,0,n) {
        while (index < n && segundo[index] >= primero[i]) {
            index++;
        }
        if (index < n && segundo[index] < primero[i])
            opciones_primero+=n-index;
    }

    int opciones_segundo = 0;
    //cout << "secondloop" << endl;
    index = 0;
    FOR(i,0,n) {
        while (index < n && primero[index] >= segundo[i]) {
            index++;
        }
        if (index < n && primero[index] < segundo[i])
            opciones_segundo+=n-index;
    }

    if (opciones_primero > opciones_segundo)
        cout << "PRIMERO\n";
    else if (opciones_segundo > opciones_primero)
        cout << "SEGUNDO\n";
    else
        cout << "NO HAY DIFERENCIA\n";

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