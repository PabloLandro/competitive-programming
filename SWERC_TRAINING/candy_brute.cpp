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
#define ROF(i, a, b) for(int i = b-1; i>=a; i--)

int main()
{
    int N, k;
    cin >> N >> k;

    vi candy;

    FOR(i,0,N) {
        int curr;
        cin >> curr;
        candy.PB(curr);
    }


    while (candy.size() >= k) {
        sort(all(candy));
        int small = candy[0];
        candy.erase(candy.begin());
        ROF(i,max(0,(int)candy.size()-k+1),candy.size()) {
            candy[i] -= small;
        }
    }

    ll ans = 0;
    sort(all(candy));
    while (!candy.empty()) {
        ll small = candy[0];
        ans += small *((ll)k-candy.size());
        candy.erase(candy.begin());
        FOR(i,0,candy.size()) {
            candy[i] -= small;
        }
    }

    cout << ans << endl;
    
}