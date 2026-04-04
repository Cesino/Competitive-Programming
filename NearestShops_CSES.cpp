#include <vector>
#include <set>
#include <string>
#include <iostream>
#include <random>
#include <queue>
#include <cmath>
using namespace std;

int const INF = 1000000000;

vector<int> bfs(vector<bool> &shops, vector<vector<int>> &adj, vector<bool> visited) {
    int v; int d; vector<int> min_d(adj.size(), INF);
    queue<pair<int, int>> q;
    for (int i{0}; i < shops.size(); i++) {
        if (shops[i] == 1) {
            q.push({0, i}); visited[i] = true;
        }
    }

    while (!q.empty()) {
        v = q.front().second;
        d = q.front().first;
        q.pop();
        if (min_d[v] > d && d != 0) {
            min_d[v] = d;
        }

        for (int to: adj[v]) {
            if (!visited[to]) {
                visited[to] = true;
                q.push({d+1, to});
            }
        }
    }

    return min_d;
}


int main() {
    int n; int m; int k; string s; string emp;
    int a; int b;
    cin >> n >> m >> k;

    vector<int> shops;

    vector<vector<int>> adj(n+1, vector<int>({}));

    for (int i{0}; i < k; i++) {
        int inp;
        cin >> inp;
        shops.push_back(inp);
    }

    for (int i{0}; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> dist(n+1, INF);
    vector<int> cur_dist(n+1, INF);

    vector<bool> v(n+1, false);
    int r;

    for (int i{1}; i <= max(30, static_cast<int>(log(n))*5); i++) {
        vector<bool> shops_subset(n+1);
        for (auto shop: shops) {
            r = rand() % 2;
            if (r == 1) shops_subset[shop] = true;
        }

        cur_dist = bfs(shops_subset, adj, v);

        for (int j{0}; j < cur_dist.size(); j++) {
            if (cur_dist[j] < dist[j]) {
                dist[j] = cur_dist[j];
            }
        }
    }

    for (int i{1}; i < dist.size(); i++) {
        if (dist[i] == INF) cout << -1 << " ";
        else cout << dist[i] << " ";
    }
}
