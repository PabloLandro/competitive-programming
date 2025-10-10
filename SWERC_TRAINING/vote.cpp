#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <queue>
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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vi arr(n);
    FOR(i,0,n) {
        arr[i] = s[i] - '0';
    }

    vi cost_0(n), cost_1(n), cost_2(n);

    priority_queue<pi, vector<pi>, greater<pi>> pq_0;   // n of swaps to put -1 to 0
    priority_queue<pi, vector<pi>, greater<pi>> pq_1;   // n of swaps to put 0 to 1
    priority_queue<pi, vector<pi>, greater<pi>> pq_2;   // n of swaps to put -1 to 1
    vector<pi> ar_0;
    vector<pi> ar_1;
    vector<pi> ar_2;
    

    // Number of tellers with positive/negative vote
    int positives = 0;
    int negatives = 0;


    // last real position with 0 or 1 count
    int last_0=-INF;
    int last_1=-INF;

    int real_index = 0;
    int curr_count = 0;

    FOR(i,0,n) {
        if (arr[i] == 0) {
            if (curr_count > 0)
                positives++;
            else if (curr_count < 0)
                negatives++;
            cost_0[i] = real_index-last_0;
            cost_1[i] = real_index-last_1;
            if (curr_count < 0) {
                cost_2[i] = real_index-last_1;
            }
            continue;
        }
        real_index++;
        if (arr[i] == 1)
            curr_count++;
        else if (arr[i] == 2)
            curr_count--;
        if (curr_count == 0)
            last_0 = real_index;
        else if (curr_count >= 1)
            last_1 = real_index;
        
    }

    last_0=INF;
    last_1=INF;

    real_index=n-1;
    ROF(i,0,n) {
        if (arr[i] == 0) {
            cost_0[i] = min(cost_0[i], last_0-real_index);
            //cout << cost_1[i] << " " << last_1-real_index << "\n";
            cost_1[i] = min(cost_1[i], last_1-real_index);
            if (curr_count < 0) {
                cost_2[i] = last_1-real_index;
            }
            continue;
        }
        if (curr_count == 0)
            last_0 = real_index;
        else if (curr_count >= 1)
            last_1 = real_index;
        real_index--;
        if (arr[i] == 1)
            curr_count--;
        else if (arr[i] == 2)
            curr_count++;
        
    }
    /*
    FOR(i,0,n) {
        cout << cost_0[i] << " ";
    }
    cout << "\n";
    FOR(i,0,n) {
        cout << cost_1[i] << " ";
    }
    cout << "\n";
    */

    FOR(i,0,n) {
        if (cost_0[i] != 0)
            pq_0.push(MP(cost_0[i], i));
        if (cost_1[i] != 0)
            pq_1.push(MP(cost_1[i], i));
        if (cost_2[i] != 0)
            pq_2.push(MP(cost_1[i], i));
    }

    int diff = negatives-positives;

    int ans = 0;

    vector<bool> moved(n, false);

    pi aux2 = pq_2.empty() ? MP(0,-1): pq_2.top();
    pi aux1 = pq_1.empty() ? MP(0,-1): pq_1.top();
    pi aux0 = pq_0.empty() ? MP(0,-1): pq_0.top();
    
    if (!pq_1.empty() && positives == 0 && aux1.S == aux0.S) {
        pq_0.pop();
        aux0 = pq_0.top();
    }

    //cout << diff << " " << positives << "\n";
    if (!pq_2.empty() && positives == 0 && diff > 0 && (aux2.F <= aux1.F + aux0.F)) {
        moved[aux2.S] = true;
        ans += aux2.F;
        diff-=2;
        positives++;
        //cout << "NOPE\n";
    } else if (positives == 0 && !pq_1.empty()) {
        pi aux = pq_1.top();

        moved[aux.S] = true;
        ans += aux.F;
        diff--;
        positives++;
        //cout << "YES\n";
    }

    while (diff >= 0 && !pq_0.empty()) {
        pi aux = pq_0.top();
        pq_0.pop();
        if (moved[aux.S])
            continue;
        //cout << "move index " << aux.S << "\n";
        ans += aux.F;
        diff--;
    }

    if (diff >= 0 || positives==0)
        cout << "impossible\n";
    else
        cout << ans << "\n";


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