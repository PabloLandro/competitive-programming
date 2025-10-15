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

#define DEBUG false

void print(string name, pi pair) {
    if (DEBUG)
        cout << name << ": (" << pair.F << ", " << pair.S << ")\n";
}

void print_v(vi v) {
    if (!DEBUG)
        return;
    FOR(i,0,v.size())
        cout << v[i] << " ";
    cout << "\n";
}

int main()
{
    //---------------READ INPUT-----------------------//
    int n;
    cin >> n;
    string s;
    cin >> s;
    vi arr(n);
    FOR(i,0,n) {
        arr[i] = s[i] - '0';
    }
    //------------------------------------------------//

    vi cost_1(n), cost_2(n);

    vi pos(n, -1);  

    int balance = 0;


    // last real position with 0 or 1 count
    int last_0=0;
    int last_1=-INF;

    int real_index = 0;
    int curr_count = 0;

    vi teller_cost_1, teller_cost_2;

    //cout << "curr_count 1: ";
    FOR(i,0,n) {
        //cout << curr_count << " ";
        pos[i] = (curr_count < 0) ? -1: (curr_count > 0)? 1: 0;
        if (arr[i] == 0) {
            if (curr_count > 0) {
                teller_cost_1.PB(INF);
                teller_cost_2.PB(INF);
                balance++;
            }
            else if (curr_count < 0) {
                teller_cost_1.PB(real_index-last_0);
                teller_cost_2.PB(INF);
                balance--;
            } else {
                teller_cost_1.PB(INF);
                teller_cost_2.PB(INF);
            }
            cost_0[i] = real_index-last_0;
            //if (cost_0[i] < 0)
            //    cout << "WTF1\n";
            cost_1[i] = real_index-last_1;
            if (curr_count < 0) {
                cost_2[i] = real_index-last_1;
            }
        } else {
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
        
    }
    //cout << "\n";

    last_0 = (curr_count != 0) ? INF: n;
    last_1 = (curr_count <= 0) ? INF: n;
    //real_index=n-1;
    ROF(i,0,n) {
        if (arr[i] == 0) {
            int aux_cost0 = last_0 - real_index;
            if (aux_cost0 < cost_0[i]) {
                cost_0[i] = aux_cost0;
                magic[i] *= -1;
            }
            //if (cost_0[i] < 0)
            //    cout << "WTF2\n";
            int aux_cost1 = last_1 - real_index;
            if (aux_cost1 < cost_1[i]) {
                cost_1[i] = aux_cost1;
                magic[i] *= -1;
            }

            if (curr_count < 0) {
                cost_2[i] = min(cost_2[i], aux_cost1);
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
    
    print_v(cost_0);
    print_v(cost_1);
    print_v(pos);
    
    //-------------------FILL THE PRIORITY QUEUES------------//
    FOR(i,0,n) {
        if (cost_0[i] != 0 && cost_0[i] < 6000)
            pq_0.push(MP(cost_0[i], i));
        if (cost_1[i] != 0 && cost_1[i] < 6000)
            pq_1.push(MP(cost_1[i], i));
        if (cost_2[i] != 0 && cost_2[i] < 6000)
            pq_2.push(MP(cost_2[i], i));
    }
    //----------------------------------------------------------------//

    int ans = 0;

    // dp[d][i]: minimum csot of obtaining a+d points by moving the
    // first i tellers (in any arbitrary order).

    // dp[0][0] = 0
    // dp[>0][0] = INF

    // consider a teller t_i, it has a cost to obtain +1 and a cost to obtain +2
    // cost for +2 is INF if teller is currently at a tie

    // d[d][i>0] is the minimum of d[d][i-1], d[d-1][i-1]+Cost1, d[d-2][i-1]+Cost2
}