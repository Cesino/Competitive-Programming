#include <vector>
#include <iostream>
using namespace std;

void dfs(int n, vector<int> &v, vector<vector<int>> &adj, vector<int> &fin) {
    v[n] = 1;
    for (int to: adj[n]) {
        if (v[to] == 1) {
            v[0] = -1;
            return;
        }
        if (v[to] == 0) dfs(to, v, adj, fin);
    }
    v[n] = 2;
    fin.push_back(n);
}
int main() {
    int n; int m; int a; int b;
    cin >> n >> m;
    vector<int> v(n+1, 0);
    vector<vector<int>> adj(n+1, vector<int>({}));
    vector<int> fin({});
    for (int i{0}; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for (int i{1}; i < n+1; i++) {
        if (!v[i]) dfs(i, v, adj, fin);
    }
    if (v[0] != -1) {
        for (int j{0}; j < fin.size(); j++) {
            cout << fin[fin.size()-1-j] << " ";
        }
    }
    else {
        cout << "IMPOSSIBLE";
    }
}
