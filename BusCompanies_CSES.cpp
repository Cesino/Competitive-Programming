#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <utility>
#define ll long long int
using namespace std;

ll INF = LLONG_MAX;

void dijkstra(ll f, vector<vector<pair<ll ,ll>>> &adj, vector<ll> &d) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    d[f] = 0;
    q.push({d[f], f});
    while (!q.empty()) {
        ll d_v = q.top().first;
        ll v = q.top().second;
        q.pop();
        if (d[v] != d_v){continue;}
        for (auto n: adj[v]) {
            ll w = n.first;
            ll u = n.second;
            if (d[u] > d[v] + w) {
                d[u] = d[v] + w;
                q.push({d[u], u});
            }
        }
    }
}

int main() {
    ll n,m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj(n+m+1);
    vector<bool> vis(n+m+1);
    vector<ll> d(n+m+1, INF);
    vector<ll> cost(n+m+1, 0);
    int th, temp;
    for (ll i{n+1};i<n+m+1;i++){cin >> th; cost[i] = th;}
    for (ll i{n+1};i<n+m+1;i++) {
        cin >> th;
        for (ll j{0}; j<th; j++) {
            cin >> temp;
            adj[i].push_back({0,temp});
            adj[temp].push_back({cost[i], i});
        }
    }

    dijkstra(1, adj, d);
    for (int i{1}; i<n+1; i++){cout << d[i] << " ";}
}