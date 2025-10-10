#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <stack>
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
    int m, n;

    cin >> m >> n;
    vi stamps(m);

    FOR(i,0,m) {
        cin >> stamps[i];
    }

    vector<ll> prefixes(m+1), suffixes(m+1);

    ll sum_p = 0, sum_s = 0;
    
    FOR(i,0,m+1) {
        prefixes[i] = sum_p;
        suffixes[m-i] = sum_s;
        if (i == m)
            continue;
        sum_p += stamps[i];
        sum_s += stamps[m-i-1];
    }

    //FOR (i,0,m+1) {
        //cout << prefixes[i] << " ";
    //}
    //cout << "\n";

    //FOR (i,0,m+1) {
        //cout << suffixes[i] << " ";
    //}
    //cout << "\n";

    FOR(i,0,n) {
        int curr;
        cin >> curr;
        bool flag = false;
        //cout << "Curr: " << curr << endl;
        FOR(left,0,m+1) {
            if (prefixes[left] > curr) {
                break;
            }
            // binary search
            ll q = (ll)curr - prefixes[left];

            //cout << "prefix: " << prefixes[left] << " q: " << q << endl;

            int l = left-1;
            int r = m+2;
            while (r-l>1) {
                int mid = (l+r)/2;
                //cout << "Checking: " << suffixes[mid] << endl;
                if (q < suffixes[mid]) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            //cout << "r is " << r << endl;
            if (suffixes[r] == q) {
                flag = true;
                break;
            }
        }
        if (flag) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }

    }
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