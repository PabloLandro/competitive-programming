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

vector<bool> definitive;
vi prices;
vector<vi> formulas;

ll getPrice(int index) {
    if (definitive[index])
        return prices[index];
    ll cost = 0;
    vi formula = formulas[index];
    FOR(i,0,formula.size()) {
        cost += getPrice(formula[i]);
        if (cost >= prices[index])
            break;
    }
    int best = (cost >= prices[index]) ? prices[index]: cost;
    prices[index] = best;
    definitive[index] = true;
    return best;
}

void solve() {
    int n, k;
    cin >> n >> k;

    definitive.clear();
    definitive.resize(n);
    definitive.assign(n,false);

    prices.clear();
    prices.resize(n);
    
    formulas.clear();
    formulas.resize(n);
    

    FOR(i,0,n) {
        cin >> prices[i];
    }

    FOR(i,0,k) {
        int index;
        cin >> index;
        index--;
        prices[index] = 0;
        definitive[index] = true;
    }
    FOR(i,0,n) {
        int size;
        cin >> size;
        FOR(j,0,size) {
            int potion;
            cin >> potion;
            formulas[i].PB(potion-1);
        }
        if (size == 0)
            definitive[i] = true;
    }

    /*bool changes = true;
    while(changes) {
        changes = false;
        FOR(i,0,n) {
            if (definitive[i])
                continue;
            ll cost = 0;
            FOR(j,0,formulas[i].size()) {
                cost += prices[formulas[i][j]];
                if (cost >= prices[i])
                    continue;
            }
            if (cost < prices[i]) {
                prices[i] = cost;
                changes = true;
            }
        }
    }*/

    FOR(i,0,n) {
        if (definitive[i])
            cout << prices[i];
        else {
            ll price = getPrice(i);
            prices[i] = price;
            definitive[i] = true;
            cout << price;
        }
        if (i!=n-1)
            cout << " ";
    }
    cout << endl;
}

int main() {
    // Optimizacion I/O
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Usar archivos I/O, comentar al subir
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    // Número de casos
    int tc = 1;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        solve();
    }
}