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

vi getDigits(int x) {
    vi out;
    int exp = 1;
    while (x >= exp) {
        out.PB((x/exp)%10);
        exp *= 10;
    }
    return out;
}

int main()
{
    int n;

    cin >> n;


    vector<ll> count(n+1);

    /*vi aux = getDigits(n);
    FOR(i,0,aux.size()) {
        cout << aux[i] << ' ';
    }
    cout << endl;*/

    count[0] = 0;
    
    FOR(i,1,n+1) {

        ll curr = INF;

        vi digits = getDigits(i);
        FOR(j,0,digits.size()) {
            if (i - digits[j] >= 0 && digits[j] != 0) {
                curr = min(curr, count[i-digits[j]]+1);
            }
        }
        count[i] = curr;
        //cout << i << ' ' << curr << endl;
    }

    cout << count[n] << endl;
    
}