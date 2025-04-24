#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
// ORDERED SET STUFF order_of_key(k) and find_by_order(k)
#include <ext/pb_ds/assoc_container.hpp> // ORDERED SET
#include <ext/pb_ds/tree_policy.hpp> // ORDERED SET
using namespace __gnu_pbds; // ORDERED SET
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
tree_order_statistics_node_update>; // ORDERED SET
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define all(a) (a).begin(), (a).end()
#define F0R(i, n) for (int i = 0; i < n; i++)
#define fastio cin.sync_with_stdio(0);cin.tie(0);
const ll MOD = 1e9 + 7; // change MOD value


inline bool solve() {
    int A;

    int M = 24, N = 5;

    cin >> A;
    if (A==0)
        return false;

    int a = A % 19;
    int b = A % 4;
    int c = A % 7;
    int d = (19*a + M) % 30;
    int e = (2 * b + 4 * c + 6 * d + N) % 7;
    if ((d + e) < 10) {
        cout << d + e + 22 << " de marzo\n";
    } else {
        int out = d + e - 9;
        if (out == 26)
            out = 19;
        else if (out == 25 && d == 28)
            out = 18;
        cout << out << " de abril\n";
    }
    return true;
}


int main() {
    fastio;
    while(solve());
}