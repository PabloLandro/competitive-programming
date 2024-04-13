#include <bits/stdc++.h>
using namespace std;    // Tipos
#define ll long long    // 64 bits INT
#define ld long double  // 80 bits FP

// Constantes
#define PI 3.1415926535897932384626433832795l
const int MAX_N = 1e5 + 5;  // Valor de numero máximo de casos genérico
const ll MOD =
    1e9 + 7;  // Para outputs grandes, a veces se piden darlos con este modulo.
              // El modulo se puede aplicar en cada op. sin cambiar resultado
const ll INF = 1e9;   // Infinito
const ld EPS = 1e-9;  // Comparaciones de fp, e.g. if(abs(a-b) < EPS)

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
#define all(a) \
    (a).begin(), (a).end()  // Aplicar a toda la estructura, e.g. sort(all(a))

// Bucles
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ROF(i, a, b) for (int i = b - 1; i >= 0; i--)

bool attacked(pi queen1, pi queen2) {
    if (queen1.F == queen2.F || queen1.S == queen2.S) {
        //cout << "cond1" << endl;
        return true;
    }
    if (queen1.S-queen1.F == queen2.S-queen2.F) {
        //cout << "cond2" << endl;
        return true;
    }
    if (queen1.S+queen1.F == queen2.S+queen2.F) {
        //cout << "cond3" << endl;
        return true;
    }
    return false;
}

vector<pi> make_possible_points(pi queen1, pi queen2, vector<bool> valid) {
    vector<pi> out(12);
    int distX = queen2.F-queen1.F, distY = queen2.S-queen1.S;
    // Horizontal 2
    out[0] = MP(queen1.F, queen2.S);
    out[1] = MP(queen1.F+distY, queen2.S);
    out[2] = MP(queen1.F-distY, queen2.S);

    //Vertical 2
    out[3] = MP(queen2.F, queen1.S);
    out[4] = MP(queen2.F, queen1.S+distX);
    out[5] = MP(queen2.F, queen1.S-distX);

    //45 2
    out[6] = MP(queen2.F-distY, queen1.S);
    out[7] = MP(queen1.F, queen1.S-(distX-distY));
    int ord1 = queen1.S+queen1.F;
    int ord2 = queen2.S-queen2.F;
    if((ord2-ord1)%2==0) {
        out[8] = MP((ord1-ord2)/2, (ord1+ord2)/2);
    } else {
        valid[8] = false;
    }

    //-45 2
    out[9] = MP(queen1.F, queen2.S+distX);
    out[10] = MP(queen2.F+distY, queen1.S);
    ord1 = queen1.S-queen1.F;
    ord2 = queen2.S+queen2.F;
    if((ord2-ord1)%2==0) {
        out[11] = MP((ord2-ord1)/2, (ord1+ord2)/2);
    } else {
        valid[11] = false;
    }
    return out;
}

void solve() {
    int n;
    cin >> n;
    vector<pi> queens(n);
    vector<bool> valid(12, true);
    pi queen1, queen2;
    

    FOR(i,0,n) {
        int f,s;
        cin >> f >> s;
        queens[i] = MP(f,s);
    }

    int index = 0;
    bool found = false;

    while (!found && index <= n-1) {
        queen1 = queens[index];
        FOR(i,index+1,n) {
            if (!attacked(queen1, queens[i])) {
                queen2 = queens[i];
                found = true;
                break;
            }
        }
        index++;
    }
    
    if (!found) {
        cout << "YES" << endl << queens[0].F << " " << queens[0].S << endl;
        return;
    }

    //cout << "Queen1: " << queen1.F << " " << queen1.S << endl;
    //cout << "Queen2: " << queen2.F << " " << queen2.S << endl;

    vector<pi> positions = make_possible_points(queen1,queen2, valid);
    
    /*FOR(i,0,positions.size()) {
        cout << positions[i].F << " " << positions[i].S << endl;
    }*/

    

    FOR(i,0,n) {
        pi queen = queens[i];
        FOR(j,0,12) {
            if (!valid[j])
                continue;
            if (!attacked(queen, positions[j]))
                valid[j] = false;
        }
    }

    bool ok = false;

    FOR(i,0,12) {
        if (valid[i]) {
            cout << "YES" << endl;
            ok = true;
            cout << positions[i].F << " " << positions[i].S << endl;
            break;
        }
    }

    if (!ok)
        cout << "NO" << endl;
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