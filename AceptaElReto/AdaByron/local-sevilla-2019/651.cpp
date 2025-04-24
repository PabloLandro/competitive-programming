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
    int o_F, o_C, o_D, n, F=0, C=0, D=0, FC=0, FD=0, CD=0, FCD=0;
    cin >> o_F >> o_C >> o_D;

    if (o_F == 0 && o_C == 0 && o_D == 0)
        return false;

    cin >> n;



    FOR(i,0,n) {
        string str;
        cin >> str;
        if (str.size() == 1) {
            if (str == "F") {
                F++;
            } else if (str == "C") {
                C++;
            } else {
                D++;
            }
        } else if (str.size() == 2) {
            if (str[0] != 'F' && str[1] != 'F')
                CD++;
            else if (str[0] != 'C' && str[1] != 'C')
                FD++;
            else
                FC++;
        } else
            FCD++;
    }

    // quitamos F

    if (F+FC+FD+FCD < o_F) {
        cout << "NO\n";
        return true;
    }

    o_F -= F;

    while (o_F > 0) {
        if (FC > 0 && FD > 0) {
            o_F--;FC--;FD--;CD++;
        } else if (FC>0) {
            o_F--;FC--;
        } else if (FD > 0) {
            o_F--;FD--;
        } else {
            o_F--;FCD--;
        }
    }

    C += FC;
    D += FD;

    // quitamos C

    if (C+CD+FCD < o_C) {
        cout << "NO\n";
        return true;
    }

    o_C -= C;

    while (o_C > 0) {
        if (CD > 0) {
            o_C--;CD--;
        } else {
            o_C--;FCD--;
        }
    }

    D += CD;

    if (D + FCD < o_D) {
        cout << "NO\n";
        return true;
    }

    cout << "SI\n";

    return true;
}

int main()
{
    // Optimizacion I/O
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (solve());
}