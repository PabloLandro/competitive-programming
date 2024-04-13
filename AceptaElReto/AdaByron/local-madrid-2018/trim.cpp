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

int recursive (vector<char> &simple, map<char,vi> &count, int actions, int i, int j) {
    int ans = actions;
    while (i < j) {
        if (count[simple[i]].size() <= 1) {
            i++;
            continue;
        }
        int front = count[simple[i]].front();
        int back = count[simple[i]].back();
        count[simple[i]].erase(count[simple[i]].begin());
        count[simple[i]].pop_back();
        FOR(k,back+1,j) {
            count[simple[k]].pop_back();
        }
        ans = min(ans, recursive(simple, count, actions-1, front, back));
        FOR(k,back+1,j) {
            count[simple[k]].PB(k);
        }
        //count[simple[i]].insert(count[simple[i]].begin(), front);
        count[simple[i]].PB(back);
        i++;
    }
    return ans;
}

bool solve() {
    string s;

    cin >> s;  

    if (!cin)
        return false;

    map<char, vi> count;
    int n = s.length();
    

    char prev = '0';

    vector<char> simple;

    int repeated = 0;

    FOR(i,0,n) {
        if (s[i] == prev) {
            repeated++;
            continue;
        }
        prev = s[i];
        simple.PB(s[i]);
        count[s[i]].PB(i-repeated);
    }

    int actions = n - repeated;

    int i = 0, j = simple.size()-1;

    cout << recursive(simple, count, actions, i, j) << endl;

    return true;
}

int main()
{
    // Optimizacion I/O
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Usar archivos I/O, comentar al subir
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    while (solve()) {}
}