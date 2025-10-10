#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <stack>
//#include <bits/stdc++.h>
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
    int n, k;

    cin >> n >> k;
    
    vector<vi> adj(n+1);

    FOR(i,0,k) {
        int from, to;
        cin >> from >> to;
        adj[from].PB(to);
        adj[to].PB(from);
    }

    vi color(n+1,0);

    stack<int> st;

    st.push(0);

    set<int> remaining;

    for (int i = 2; i < n+1; i++) {
        remaining.insert(i);
    }

    while(!remaining.empty() || !st.empty()) {
        if (st.empty()) {
            int aux = *remaining.begin();
            st.push(aux);
            remaining.erase(aux);
        }
        int curr = st.top();
        st.pop();
        if (color[curr] == 0)
            color[curr] = 1;
        int curr_color = color[curr];
        int check_col = (curr_color == 1) ? 2: 1;
        FOR(i,0,adj[curr].size()) {
            int next = adj[curr][i];
            if (color[next] == 0) {
                st.push(next);
                color[next] = check_col;
                remaining.erase(next);
            } else if (color[next] != check_col) {
                cout << "NOT BICOLORABLE" << endl;
                return;
            }
        }
    }
    cout << "BICOLORABLE" << endl;
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

    solve();
}