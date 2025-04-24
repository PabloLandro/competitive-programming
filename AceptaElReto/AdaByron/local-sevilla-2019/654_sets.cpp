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

#define L 0
#define T 1
#define R 2
#define B 3

inline bool intersection(const std::unordered_set<char>& set1, const std::unordered_set<char>& set2) {
    // Iterate through the smaller set for efficiency
    const std::unordered_set<char>& smallerSet = (set1.size() < set2.size()) ? set1 : set2;
    const std::unordered_set<char>& largerSet = (set1.size() < set2.size()) ? set2 : set1;

    for (const char& elem : smallerSet) {
        if (largerSet.find(elem) != largerSet.end()) {
            return true; // Found a common element
        }
    }
    return false; // No common elements
}

void solve() {
    int fil, col;
    cin >> col >> fil;
    vector<vector<char>> mat(fil, vector<char>(col));
    umap<char,bool> visited;
    umap<char,vector<int>> dims;

    unordered_set<char> chars;

    FOR(i,0,fil) {
        FOR(j,0,col) {
            char curr;
            cin >> curr;
            mat[i][j] = curr;
            if (curr == '.')
                continue;
            if (!visited[curr]) {
                visited[curr] = true;
                chars.insert(curr);
                // L T R B
                dims[curr] = vector<int>(4);
                dims[curr][L] = j;
                dims[curr][T] = i;
                dims[curr][R] = j;
                dims[curr][B] = i;
            } else {
                dims[curr][L] = min(j, dims[curr][0]);
                dims[curr][T] = min(i, dims[curr][1]);
                dims[curr][R] = max(j, dims[curr][2]);
                dims[curr][B] = max(i, dims[curr][3]);
            }
        }
    }

    umap<char, unordered_set<char>> encima;

    for (char curr: chars) {
        FOR(i,dims[curr][T], dims[curr][B]+1) {
            FOR(j,dims[curr][L], dims[curr][R]+1) {
                if (mat[i][j] == '.') {
                    cout << "IMPOSIBLE\n----\n";
                    return;
                } else if (mat[i][j] != curr) {
                    encima[curr].insert(mat[i][j]);
                }
            }
        }
    }

    int size = chars.size();

    vector<vector<char>> print_queue;

    while (chars.size() != 0) {
        vector<char> removal; // Las eliminamos todas al final para que no entren en conflicto
        for(char curr: chars) {
            if (chars.find(curr) == chars.end())
                continue;
            if (!intersection(encima[curr], chars))
                removal.PB(curr);
        }
        sort(all(removal));
        vector<char> queue;
        FOR(i,0,removal.size()) {
            char curr = removal[i];
            chars.erase(curr);
            queue.PB(curr);
        }
        print_queue.PB(queue);
        // Si no se quita ningun posit es imposible
        if (removal.size()==0) {
            cout << "IMPOSIBLE\n----\n";
            return;
        }
    }

    for(auto queue: print_queue) {
        FOR(i,0,queue.size()) {
            cout << queue[i];
            if (i != queue.size()-1)
                cout << ' ';
            else
                cout << "\n";
        }
    }    

    cout << "----\n";

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