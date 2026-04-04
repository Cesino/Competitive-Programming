#include <vector>
#include <iostream>
#include <utility>
#include <set>
using namespace std;

const int INF = 10000000;

int dijkstra(int a, int b, vector<vector<pair<int, int>>> &adj) {
    int w, v;
    set<pair<int, int>> q;
    q.insert({0, a});
    vector<int> min_d(adj.size(), INF);
    min_d[a] = 0;

    while (!q.empty()) {
        w = q.begin()->first;
        v = q.begin()->second;
        if (v == b) {return min_d[b];}
        q.erase(q.begin());

        for (auto to: adj[v]) {
            int u = to.second;
            int w_to = to.first;
            if (min_d[u] > min_d[v] + w_to) {
                min_d[u] = min_d[v] + w_to;
                q.insert({min_d[u], u});
            }
        }
    }

    return min_d[b];
}

int main() {
    int n, m, k;
    int a, b, w;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> adj(n+1);
    vector<vector<int>> min_d(n+1, vector<int>(n+1, INF));
    vector<pair<int, int>> routes;
    vector<pair<int, int>> edges;


    for (int i{0}; i < m; i++) {
        cin >> a >> b >> w;
        adj[a].push_back({w, b});
        adj[b].push_back({w, a});
        min_d[a][b] = w;
        min_d[b][a] = w;
        edges.push_back({a, b});
    }

    for (int i{0}; i < k; i++) {
        cin >> a >> b;
        routes.push_back({a,b});
    }
    for (int i{1}; i <= n; i++) min_d[i][i] = 0;


    for (int z{1}; z < n+1; z++) {
        for (int i{1}; i < n+1; i++) {
            for (int j{1}; j < n+1; j++) {
                if (min_d[i][k] < INF && min_d[k][j] < INF) {
                    min_d[i][j] = min(min_d[i][j], min_d[i][z] + min_d[z][j]);
                }
            }
        }
    }

    int min_distance = INF;

    for (auto edge: edges) {
        a = edge.first;
        b = edge.second;
        min_distance += min_d[a][b];
    }

    for (auto edge: edges) {
        int cur_min_d = 0;
        a = edge.first;
        b = edge.second;

        for (auto i: adj[a]) {
            if (i.second == b) {
                int temp_w = i.first;
                i.first = 0;
                for (auto route: routes) {
                    int u = route.first;
                    int v = route.second;
                    int d1 = dijkstra(u, a, adj) + dijkstra(b, v, adj);
                    int d2 = dijkstra(u, b, adj) + dijkstra(a, v, adj);
                    cur_min_d += min(min_d[u][v], min(d1, d2));
                }
                i.first = temp_w;
            }
        }

        if (cur_min_d < min_distance) min_distance = cur_min_d;

    }

    cout << min_distance;

}