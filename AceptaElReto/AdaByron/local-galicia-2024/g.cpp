#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long	// 64 bits
#define ld long double	// 80 bits
#define PI 3.1415926535897932384626433832795l
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<vector<int>> graph;
typedef vector<vector<pair<int, int>>> wgraph;
// set with also order_of_key(k) and find_by_order(k)
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define umap unordered_map
#define uset unordered_set
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()  // all the structure
#define F0R(i, n) for (int i = 0; i < n; i++)
#define R0F(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ROF(i, a, b) for (int i = b - 1; i >= 0; i--)
#define fastio cin.sync_with_stdio(0);cin.tie(0);
const ll MOD = 1e9 + 7; // change MOD value

inline void solve() {
    int n, m;
    cin >> n >> m;
    vector<vi> g(n+1);

    F0R(i, m) {
        int u, v; cin >> u >> v;
        g[u].PB(v); g[v].PB(u);
    }
    vi color(n+1, -1);
    queue<int> q;
    bool is_bipartite = true;
    for(int st = 1; st <=n; st++) {
        if(color[st] == -1) {
            q.push(st);
            color[st] = 0;
            while(!q.empty()) {
                int v = q.front();
                q.pop();
                for(int u: g[v]) {
                    if(color[u] == -1) {
                        color[u] = color[v] ^1;
                        q.push(u);
                    } else {
                        is_bipartite &= color[u] != color[v];
                    }
                }
            }
        }
    }

    if(is_bipartite) {
        cout << "Que comience la batalla\n";
    } else {
        cout << "Mejor nos vamos de cena o algo\n";
    }

}

int main() {
    fastio;
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int tc;
    cin >> tc;
    while (tc--) 
        solve();
}

/*
inline bool solve() {
    int n; cin >> n;
    if(!cin) return false;


    return true;
}
int main() {
    fastio;
    while(solve());
}
*/