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

/*inline void solve() {
    int n;
    cin >> n;


}*/

/*int main() {
    fastio;
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int tc;
    cin >> tc;
    while (tc--) 
        solve();
}*/


inline bool solve() {
    // WA
    int n; cin >> n;
    vector<string> words(n);
    vi b, m;
    F0R(i, n){
        cin >> words[i];
    }
    sort(all(words), [](string &left, string &right) {
        int m = min(left.size(), right.size());
        FOR(i, 1, m) {
            if(left[i] > right[i]) {
                return 0;
            } else if(left[i] < right[i]) {
                return 1;
            }   
        }
        if(left.size() < right.size()) {
            return 1;
        } else if(left.size() > right.size()) {
            return 0;
        }
        return 0;
    });

    vi buenos, malos;

    F0R(i, n) {
        if(words[i][0] == '+') {
            buenos.PB(i);
        } else {
            malos.PB(i);
        }
    }
    // I = MALOS POINTER, J = BUENOS POINTER
    int j = 0; 
    vector<string> ans;
    if(buenos.size() == 0) {
        char last = '-';
        vector<char> letters;
        F0R(i, malos.size()) {
            char primera_letra = words[malos[i]][1];
            if(primera_letra != last) {
                last = primera_letra;
                letters.PB(primera_letra);
            }
        }
        cout << letters.size() << "\n";
        F0R(i, letters.size()) {
            cout << letters[i] << "\n";
        }
        return true;
    }

    F0R(i, malos.size()) {
        int current = malos[i];
        while(j < buenos.size() && current > buenos[j]) {
            j++;
        }        
        string s = words[current]; 
        int start_value = 1;
        if(ans.size() > 0) {
            string last = ans[ans.size()-1];
            //cout << "LAST = " << last << endl;
            for(; start_value < min(last.size(), s.size()); start_value++) {
                if(s[start_value] != last[start_value]) {
                    //cout << s[start_value] << " " << last[start_value] << endl;
                    break;
                }
            }
        }
        // cout << "START VAL = " << start_value << endl;
        if(start_value == s.size()) {
            continue;
        }
        int a = start_value, b = start_value, c = 1e9;
        // arriba
        //cout << " MALO = " << s << endl;
        if(j > 0) {
            string t = words[buenos[j-1]];
            //cout << " UP = " << t << endl;
            for(; a  < min(t.size(), s.size()); a++) {
                if(s[a] != t[a]) {
                    break;
                }
            }
            //cout << " A LOGRADO = " << a << endl;
            if(a == s.size()) {
                cout << "-1\n"; return true;
            }
            c = min(c, a);
        }
        // abajo
        if(j < buenos.size()) {
            string t = words[buenos[j]];
            //cout << " DOWN = " << t << endl;
            for(; b < min(t.size(), s.size()); b++) {
                if(s[b] != t[b]) {
                    break;
                }
            }
            //cout << " B LOGRADO " << b << endl;
            if(b == s.size()) {
                cout << "-1\n"; return true;
            }
            c = min(c, b);
        }
        // cout << start_value << " " << a << " " <<  b << " " << c << endl;
        if(start_value > 1 && start_value == c) continue;
        ans.PB(s.substr(0, c+1));
    }

    cout << ans.size() << "\n";
    F0R(i, ans.size()) {
        cout << ans[i].substr(1, ans[i].size()) << "\n";
    }
    return true;
}
int main() {
    fastio;
    solve();
}
