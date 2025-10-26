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

    // Difference of tellers with positive/negative vote
    int diff = 0;

    // last real position with 0 or 1 count
    int last_0=0;
    int last_1=-INF;

    int real_index = 0;
    int curr_count = 0;

    FOR(i,0,n) {
        pos[i] = (curr_count < 0) ? -1: (curr_count > 0)? 1: 0;
        if (arr[i] == 0) {
            if (curr_count > 0) {
                diff++;
            }
            else if (curr_count < 0) {
                diff--;
                cost_1[i] = real_index-last_0;
                cost_2[i] = real_index-last_1;
            } else {
                cost_1[i] = real_index-last_1;
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
            if (curr_count < 0) {
                cost_1[i] = min(cost_1[i], last_0 - real_index);
                cost_2[i] = min(cost_2[i], last_1 - real_index);
            } else if (curr_count == 0) {
                cost_1[i] = min(cost_1[i], last_1 - real_index);
            }
        } else {
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
        
    }
    
    print_v(cost_1);
    print_v(cost_2);
    print_v(pos);
    
    priority_queue<pi, vector<pi>, greater<pi>> pq_1;
    priority_queue<pi, vector<pi>, greater<pi>> pq_2;    

    //-------------------FILL THE PRIORITY QUEUES------------//
    FOR(i,0,n) {
        if (cost_1[i] != 0 && cost_1[i] < n)
            pq_1.push(MP(cost_1[i], i));
        if (cost_2[i] != 0 && cost_2[i] < n)
            pq_2.push(MP(cost_2[i], i));
    }
    //----------------------------------------------------------------//

    int ans = 0;

    // for -1 to 1, keep variable that says distance from 0 to 1. if taken 0, push distance to ar_1
    while (true) {
        /*
        if (ans > 5000*5000) {
            cout << "impossible\n";
            return;
        }
        */

        if (diff > 0) {
            cout << ans << "\n";
            return 0;
        }

        //-------------LOAD BEST POSSIBLE NEXT STEPS------------//
        pi def = MP(INF,-1);
        pi pi1=def,     // first best pair in pq_1
            pi2=def,    // first best pair in pq_2
            pi11=def;    // second best pair in pq_1 different than pi2
            
        // take pi2
        while(!pq_2.empty() && pi2 == def) {
            pi2 = pq_2.top();
            pq_2.pop();
            if (pos[pi2.S] != -1)
                pi2 = def;
        }

        // take pi1
        while(!pq_1.empty() && pi1 == def) {
            pi1 = pq_1.top();
            pq_1.pop();
            if (pos[pi1.S] == 1)
                pi1 = def;
        }

        pi better_pi11 = def;
        if (pi1 != def && pos[pi1.S] == -1) {
            better_pi11 = MP(cost_2[pi1.S] - cost_1[pi1.S], pi1.S);
        }

        // take pi11
        while(!pq_1.empty() && pi11 == def) {
            pi11 = pq_1.top();
            pq_1.pop();
            if (pos[pi11.S] == 1)
                pi11 = def;
        }

        pq_1.push(pi1);
        pq_1.push(pi11);
        pq_2.push(pi2);
        
        vector<pi> save;

        if (better_pi11.F < pi11.F)
            pi11 = better_pi11;
        //------------------------------------------------------//

        //-----------------If no possible pairs, finish---------//
        if (pi2==def && pi1==def) {
            cout << "impossible\n";
            return 0;
        }
        //------------------------------------------------------//
        if (DEBUG)
            cout << "HOLLAAAA\n";

        // If directly promoting from -1 to 1 is better than any other pair of possible options, we do it
        if (DEBUG)
            cout << "NO EYOOO\n";
        print("pi2", pi2);
        print("pi1", pi1);
        print("pi11", pi11);

        if (diff != 0 && pi2 != def && pi11 != def && pi2.F < pi1.F + pi11.F) {
            if (DEBUG)
                cout << "case -1 to 1\n";
            ans += pi2.F;
            diff += 2;
            pos[pi2.S] = 1;
            pq_2.pop();
        } //else if (pi1 != def) {
        else {
            if (DEBUG)
                cout << "case 0 to 1\n";
            ans += pi1.F;
            diff++;
            pq_1.pop();
            if (pos[pi1.S] == -1) {
                int distance = cost_2[pi1.S] - cost_1[pi1.S];
                if (distance < n)
                    pq_1.push(MP(distance, pi1.S));
            }

            pos[pi1.S]++;
        }
    }
}