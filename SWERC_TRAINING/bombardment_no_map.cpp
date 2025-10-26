#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <list>
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

void print(list<int> lt) {
    auto aux = lt.begin();
    while (aux != lt.end()) {
        cout << *aux << " ";
        aux = next(aux);
    }
    cout << endl;
}

int main()
{
    int N, R;
    cin >> N >> R;


    list<int> lt;

    FOR(i,0,N) {
        int curr;
        cin >> curr;
        lt.PB(curr);
    }

    lt.sort();
    vi ans;

    while (N > 0) {
        /*for (int i = 0; i < places.size(); i++) {
            cout << bombs[places[i]] << ' ';
        }
        cout << endl;
        for (int i = 0; i < places.size(); i++) {
            cout << places[i] << ' ';
        }
        cout << endl;*/
        int count = 0;
        auto i = lt.begin();
        pair<int,pair<list<int>::iterator,list<int>::iterator>> best = MP (0,MP(lt.begin(),lt.begin()));
        auto lastidx = lt.begin();
        while(i != lt.end()) {
            count++;
            while (*lastidx < (*i)-2*R) {
                count--;
                lastidx = next(lastidx);
            }
            if (best.F < count)
                best = MP(count, MP(lastidx,i));
            i = next(i);
        }
        N -= best.F;
        //cout << best.S << endl;
        //cout << "best: (" << best.F << ",(" << *(best.S.F) << "," << *(best.S.S) << "))" << endl;
        ans.PB((*(best.S.S))-R);

        //cout << "before" << endl;
        //print(lt);
        lt.erase(best.S.F, next(best.S.S));
        //cout << "after" << endl;
        //print(lt);
    }
    cout << ans.size() << endl;
    FOR(i,0,ans.size()) {
        cout << ans[i];
        if (i != ans.size()-1)
            cout << ' ';
    }
    cout << endl;
}