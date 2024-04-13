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
    vector<vi> adj(n+1);
    F0R(i, m) {
        int u, v; cin >> u >> v;
        adj[u].PB(v);
        adj[v].PB(u);
    }
    vector<bool> used(n+1, false);
    queue<int> q;
    int comp_n = 0; ll prod = 1;
    for(int i = 1; i<=n; i++) {
        if(used[i]) continue;
        q.push(i);
        comp_n ++;
        ll comp_counter = 1;
        used[i] = true;
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            for(int u: adj[v]) {
                if(!used[u]) {
                    used[u] = true;
                    comp_counter++;
                    q.push(u);
                }
            }
        }

        prod = (prod * comp_counter) % MOD;
    }
    cout << comp_n << " " << prod << "\n";
}

int main() {
    fastio;
    int tc;
    cin >> tc;
    while (tc--) 
        solve();
}