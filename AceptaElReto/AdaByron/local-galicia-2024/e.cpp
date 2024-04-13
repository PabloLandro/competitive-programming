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


inline bool solve() {
    int f; cin >> f;
    if(!cin) return false;
    int c; cin >> c;
    vector<vector<ll>> pre(f, vector<ll>(c, 0));
    vector<vi> arr(f, vi(c));
    F0R(i, f) {
        F0R(j, c) {
            cin >> arr[i][j];
        }
    }
    pre[0][0] = arr[0][0];
    for(int i = 1; i<f; i++) {
        pre[i][0] = pre[i-1][0] + arr[i][0];
    }
    for(int j = 1; j<c; j++) {
        pre[0][j] = pre[0][j-1] + arr[0][j];
    }
    for(int i = 1; i<f; i++) {
        for(int j = 1; j<c; j++) {
            pre[i][j] = -pre[i-1][j-1] + pre[i][j-1] + pre[i-1][j] + arr[i][j];
        }
    }
    int q;
    cin >> q;
    ll m = -1, ans = -1;
    F0R(i, q) {
        int id, x1, y1, x2, y2; cin >> id >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;
        ll sum = pre[x2][y2];
        if(x1-1 >= 0)
            sum -=  pre[x1-1][y2];
        if(y1-1 >=0)
            sum -= pre[x2][y1-1];
        if(x1-1 >= 0 && y1-1 >= 0)
            sum += pre[x1-1][y1-1];
        
        if(sum > m) {
            m = sum;
            ans = id;
        }
    } 
    cout << ans << " " << m << "\n";
    return true;
}
int main() {
    fastio;
    while(solve());
}
