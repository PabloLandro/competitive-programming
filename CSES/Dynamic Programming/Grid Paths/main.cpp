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

int main()
{
    int n;

    cin >> n;

    vector<vi> mat(n);

    vector<vector<ll>> count(n);

    FOR(i,0,n) {
        FOR(j, 0, n) {
            char aux;
            cin >> aux;
            if (aux == '*')
                mat[i].PB(1);
            else
                mat[i].PB(0);
        }
        count[i].resize(n);
    }

    count[n-1][n-1] = 1;

    ROF(i,0,n) {
        ROF(j, 0, n) {

            if (mat[i][j] == 1)
                continue;

            ll curr = 0;
            
            if (i < n-1) {
                curr = (curr + count[i+1][j]) % MOD;
            }
            if (j < n-1) {
                curr = (curr + count[i][j+1]) % MOD;
            }
            count[i][j] = curr;
        }
    }

    cout << count[0][0] << endl;

}