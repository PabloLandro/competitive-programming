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

pi intersection (pi l1, pi l2) {
    //null
    if (l1.F > l2.S || l2.F > l1.S)
        return MP(-1,-1);
    //contained l2
    if (l1.F <= l2.F && l1.S >= l2.S)
        return l2;
    //contained l1
    if (l2.F <= l1.F && l2.S >= l1.S)
        return l1;
    return MP(max(l1.F, l2.F), min(l1.S, l2.S));
}

int n;
vector<pi> levels;


bool isDoable(int jump) {
    pi zone = MP(0,jump);
    FOR(i,0,n) {
        zone = intersection(zone, levels[i]);
        if (zone.F==-1 && zone.S==-1)
            return false;
        zone = MP(zone.F-jump, zone.S+jump);
    }
    return true;
}

void solve() {
    cin >> n;

    levels.clear();

    int a = 0, b = 0;

    FOR(i,0,n) {
        int curr1, curr2;
        cin >> curr1;
        cin >> curr2;
        b = max(b, curr2);
        levels.PB(MP(curr1, curr2));
    }

    int ans = b;
    while (a <= b) {
        int k = (a+b)/2;
        if (isDoable(k)) {
            ans = min(ans,k);
            b = k-1;
        } else {
            a = k+1;
        }
        //cout << a << ' ' << b << endl;
    }
    cout << ans << '\n';
}

int main() {
    // Optimizacion I/O
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Usar archivos I/O, comentar al subir
     //freopen("input.txt", "r", stdin);
     //freopen("output.txt", "w", stdout);

    /*while(true) {
        int a1, b1, a2, b2;
        cin >> a1 >> b1 >> a2 >> b2;
        pi ans = intersection(MP(a1,b1), MP(a2,b2));
        cout << ans.F << ' ' << ans.S << endl;
    }*/

    // Número de casos
    int tc = 1;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        solve();
    }
}