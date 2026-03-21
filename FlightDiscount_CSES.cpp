#include <vector>
#include <set>
#include <utility>
#include <iostream>
#include <queue>
using namespace std;

long long const INF = 4e18;

void dijkstra(int n, vector<long long> &d, vector<vector<pair<int, int>>> &adj) {
    int s = n;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
    d[s] = 0;
    q.push({0, s});

    while(!q.empty()) {
        int cur = q.top().second;
        temp_w = q.top().first;
        q.pop();
        if (d[cur] != temp_w) continue;

        for (auto edge: adj[cur]) {
            int w = edge.first;
            int to = edge.second;
            if (d[cur] + w < d[to]) {
                d[to] = d[cur] + w;
                q.push({d[to], to});
            }
        }
    }

}

int main() {
    int n; int m;
    int a; int b; int w;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n+1, vector<pair<int, int>>({}));
    vector<vector<pair<int, int>>> rev(n+1, vector<pair<int, int>>({}));

    vector<pair<int, pair<int, int>>> edges;
    for (int i{0}; i < m; i++) {
        cin >> a >> b >> w;
        adj[a].push_back({w, b});
        rev[b].push_back({w, a});
        edges.push_back({w, {a, b}});
    }
    vector<long long> d_1(n+1, INF);
    vector<long long> d_n(n+1, INF);

    dijkstra(1, d_1, adj);
    dijkstra(n, d_n, rev);
    long long shortest = INF;

    for (auto edge: edges) {
        int w_cost = edge.first / 2;
        int j = edge.second.first;
        int k = edge.second.second;

        long long cur = d_1[j] + d_n[k] + w_cost;
        if (cur < shortest) shortest = cur;
    }

    cout << shortest;

}