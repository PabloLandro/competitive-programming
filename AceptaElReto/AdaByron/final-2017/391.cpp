#include <bits/stdc++.h>
using namespace std;
#define fastio cin.sync_with_stdio(0);cin.tie(0);
#define F0R(i, n) for (int i = 0; i < n; i++)

using ll = long long;
using pull = pair<ll, ll>;

const ll INF = numeric_limits<ll>::max();;

vector<vector<pull>> adj;
void dijkstra(ll s, vector<ll> & d) {
    ll n = adj.size();
    d.assign(n, INF);
    d[s] = 0;
    priority_queue<pull, vector<pull>, greater<pull>> q;
    q.push({0, s});
    while (!q.empty()) {
        ll v = q.top().second;
        ll d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;
        for (auto edge : adj[v]) {
            ll to = edge.first;
            ll len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                q.push({d[to], to});
            }
        }
    }
}

bool in_v(vector<ll>&v, ll a) {
    for(ll i = 0; i<v.size(); i++){
        if(v[i] == a){
            return true;
        }
    }
    return false;
}

// WA for some reason
bool solve(bool *check) {
    if (check[0] != false)
        cout << "\n";
    check[0] = true;
    ll n; cin >> n; 
    if(!cin) return false;
    ll m;
    cin >> m;
    adj.resize(n);
    F0R(i, m) {
        ll from, to, w; cin >> from >> to >> w; from--, to--;
        adj[from].push_back(make_pair(to, w));
        adj[to].push_back(make_pair(from, w));
    }

    ll c; cin >> c;
    map<ll, vector<ll>> dists; // cache results over diff queries
    F0R(i, c) {
        ll nc; cin >> nc;
        vector<ll>nodes(nc);
        F0R(j, nc) {
            ll x; cin >> x; x--;
            nodes[j] = x;
            if(dists.find(x) == dists.end()) {
                vector<ll>d;
                dijkstra(nodes[j], d);
                dists[x] = d;
            }
        }

        // find best vertices for start along all possible pairs of first-last village
        vector<vector<ll>> best_starts(nc, vector<ll>(nc, -1)); 
        vector<vector<ll>> best_costs(nc, vector<ll>(nc, INF));
        F0R(j, nc) {
            F0R(k, nc) {
                // only compute lower triag
                if(j > k) continue;
                F0R(l, n) {
                    if(in_v(nodes, l)) continue;
                    else {
                        ll st_cost = dists[nodes[j]][l] + dists[nodes[k]][l];
                        if(st_cost < best_costs[j][k]) {
                            best_starts[j][k] = l, best_costs[j][k] = st_cost;
                        }
                    }
                }
            }
        }

        // extract best path over all possible permutations (up to 720)
        vector<ll> perm(nc);
        iota(perm.begin(), perm.end(), 0);
        ll best = INF, bestest_start = -1;
        do {
            ll cost = 0;
            for (ll i = 1; i< nc; ++i) {
                cost += dists[nodes[perm[i]]][nodes[perm[i-1]]];
            }
            // add starting node cost
            ll min_node = std::min(perm[0], perm[nc-1]);
            ll max_node = std::max(perm[0], perm[nc-1]);
            cost += best_costs[min_node][max_node];
            if(cost < best || (cost == best && best_starts[min_node][max_node] < bestest_start)) {
                bestest_start = best_starts[min_node][max_node];
                best = cost;
            }
        } while (next_permutation(perm.begin(), perm.end()));
        std::cout << bestest_start+1 << " " << best << "\n";
    }
    std::cout << "---";
    return true;
}

int main() {
    fastio;
    bool check[1];
    check[0] = false;
    while (solve(check));
}
