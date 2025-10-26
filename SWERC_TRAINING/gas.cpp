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

#define debug false

int main() {
    int P, N;
    cin >> P >> N;

    vi finish_time(N);

    vector<queue<pi>> queues(2*P);   // q.F finish time, q.S.F index, q.S.S side

    vector<pi> lanes(2*P, {0,0});


    FOR(i,0,N) {
        int t, f;
        char s;
        cin >> t >> f >> s;
        int offset = s=='R';
        int index_available = -1;

        FOR (j,0,2*P) {
            while (!queues[j].empty() && lanes[j].F <= t) {
                int ff = queues[j].front().F;
                int ii = queues[j].front().S;

                queues[j].pop();
                pi lane = lanes[j];
                //cout << lane.F << " " << ff << endl;
                if (debug)
                    cout << "predequeuing " << ii << " finish time " << lane.F+ff << endl;
                finish_time[ii] = lane.F+ff;
                // Put the car in the lane
                if (lane.S <= lane.F) {
                    lanes[j] = MP(lane.F, lane.F+ff);
                } else {
                    lanes[j] = MP(lane.F+ff, lane.S);
                }   
            }
        }


        FOR(j,0,P) {
            int curr = (2*j)+offset;
            if (lanes[curr].F <= t) { // A libre, se queda
                index_available = j;
                break;
            }   
        }
        if (index_available == -1) {
            // Find shortest queue
            int best_index = 0;
            int best_size = INF;
            FOR(j,0,P) {
                int curr = (2*j)+offset;
                if (queues[curr].size() < best_size) {
                    best_size = queues[curr].size();
                    best_index = curr;
                }
            }
            queues[best_index].push(MP(f,i));
            if (debug)
                cout << "Cant put" << endl;
        } else {
            finish_time[i] = t+f;
            int lane_aux = (2*index_available)+offset;
            pi lane = lanes[lane_aux];
            // Put the car in the lane
            if (lane.S <= t) {
                if (debug)
                    cout << "putting in B-" << lane_aux << endl;
                lanes[lane_aux] = MP(lane.F, t+f);
            } else {
                if (debug)
                    cout << "putting in A-" << lane_aux << endl;
                lanes[lane_aux] = MP(t+f, lane.S);
            }
        }
    }
    
    FOR (j,0,2*P) {
        queue<pi> waiting = queues[j];
        while (!waiting.empty()) {
            int ff = waiting.front().F;
            int ii = waiting.front().S;

            waiting.pop();
            pi lane = lanes[j];
            //cout << lane.F << " " << ff << endl;
            if (debug)
                cout << "posdequeuing " << ii << " finish time " << lane.F+ff << endl;
            finish_time[ii] = lane.F+ff;
            // Put the car in the lane
            if (lane.S <= lane.F) {
                lanes[j] = MP(lane.F, lane.F+ff);
            } else {
                lanes[j] = MP(lane.F+ff, lane.S);
            }   
        }
    }

    FOR(i,0,N) {
        cout << finish_time[i] << endl;
    }
}