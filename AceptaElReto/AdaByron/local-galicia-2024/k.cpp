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
    string s;
    cin >> s;
    if(!cin) return false;

    unordered_map<char, int> count;
    F0R(i, s.length()) {
        if(count.find(s[i]) == count.end()) {
            count[s[i]] = 1;
        }  else {
            count[s[i]] = count[s[i]] + 1; 
        }
    }
    int n;
    cin >> n;
    int max_n = -1;
    string ans;
    F0R(i, n) {
        unordered_map<char, int> m(count);
        string t;
        cin >> t;
        int flag = 1;
        F0R(j, t.length()) {
            if(m.find(t[j]) == m.end()) {
                flag = 0; 
                break;
            }  else {
                m[t[j]] = m[t[j]] - 1;
                if(m[t[j]] == -1) {
                    flag = 0; 
                    break;
                }
            }
        }
        int len = (int) t.length();
        if(flag && (len == max_n)){
            bool flag2 = false;
            F0R(k, max_n) {
                if(ans[k] > t[k]) {
                    flag2 = true; break;
                } else if(ans[k] < t[k]) {
                    break;
                }
            }
            if(flag2)
                ans = t;
        } else if(flag && (len > max_n)) {
            max_n = len;
            ans = t;
        }
    }
    if(max_n == -1) {
        cout << "No es posible\n";
    } else {
        cout << ans << "\n";
    }
    return true;
}
int main() {
    fastio;
    while(solve());
}
