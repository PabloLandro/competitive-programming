#include <bits/stdc++.h>

using namespace std; 
#define ll long long 

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define ROF(i, a, b) for (ll i = b - 1; i >= a; i--)


void solve() {
    ll d;

    cin >> d;
    vector<pair<ll,ll>> sol;

    d *= 2;
    for(ll k = 1; k*k <= d; k++) {
        if (d%k != 0)
            continue;

        ll n = d/k - k - 1;
        if (n > 0 && n%2 == 0) {
            n /= 2;
            sol.PB(MP(n, n+k));
        }
    }
    cout << sol.size() << endl;
    FOR(i,0,sol.size()) {
        cout << sol[i].F << " " << sol[i].S << endl;
    }
}

int main() {
    solve();
}