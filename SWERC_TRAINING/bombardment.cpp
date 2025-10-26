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

int main()
{
    int N, R;
    cin >> N >> R;

    umap<int,int> bombs;

    vi places;

    FOR(i,0,N) {
        int curr;
        cin >> curr;
        if (bombs[curr] == 0)
            places.PB(curr);
        bombs[curr] += 1;
    }
    sort(all(places));

    umap<int, int> score;   // score[i] is the current number of targets when exploding at center places[i] - R

    vi ans;

    while (N > 0) {
        bool valid = false;
        int count = 0;
        int lastidx = 0;
        pi best = MP (0,0);
        /*for (int i = 0; i < places.size(); i++) {
            cout << bombs[places[i]] << ' ';
        }
        cout << endl;
        for (int i = 0; i < places.size(); i++) {
            cout << places[i] << ' ';
        }
        cout << endl;*/
        FOR(i,0,places.size()) {
            count += bombs[places[i]];
            while (places[lastidx] < places[i]-2*R) {
                count -= bombs[places[lastidx]];
                lastidx++;
            }
            if (best.F < count)
                best = MP(count, i);
        }
        N -= best.F;
        //cout << best.S << endl;
        ans.PB(places[best.S]-R);
        int idx = best.S;
        // set 0 on the right
        while (idx < places.size() && places[idx] <= places[best.S]) {
            bombs[places[idx]] = 0;
            idx++;
        }
        idx = best.S;
        // set 0 on the left
        while (idx >= 0 && places[idx] >= places[best.S]-2*R) {
            bombs[places[idx]] = 0;
            idx--;
        }
    }
    cout << ans.size() << endl;
    FOR(i,0,ans.size()) {
        cout << ans[i];
        if (i != ans.size()-1)
            cout << ' ';
    }
    cout << endl;
}