#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

void dfs(int u, vector<pair<int, int>> &d, vector<vector<int>> &adj) {
    for (int v: adj[u]) {
        if (d[u].first + 1 > d[v].first) {
            d[v] = {d[u].first + 1, u};
            dfs(v, d, adj);
        }
    }

}

int main() {
    int n; int m; int a; int b;
    cin >> n >> m;
    vector<vector<int>> adj(n+1, vector<int>({}));
    vector<pair<int, int>> d(n+1, {-1, -1});
    cout << "HERE";
    for (int i{0}; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
    }
    d[1] = {0, -1};
    dfs(1, d, adj);
    vector<int> path;
    int past = d[n].second;
    path.push_back(n);
    while (past != -1) {
        path.push_back(past);
        past = d[past].second;
    };
    reverse(path.begin(), path.end());
    cout << path.size() << "\n";
    for (int i{0}; i < path.size(); i++) {
        cout << path[i] << " ";
    }


}