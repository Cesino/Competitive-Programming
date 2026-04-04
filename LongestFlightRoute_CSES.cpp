#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

queue<int> kahns_algorithm(vector<int> &degree, vector<vector<int>> &adj){
    queue<int> fin, ready;

    for (int i = 1; i < degree.size(); i++) {
        if (degree[i] == 0) ready.push(i);
    }

    while (!ready.empty()) {
        int cur = ready.front();
        ready.pop();
        fin.push(cur);

        for (int to: adj[cur]) {
            degree[to] -= 1;
            if (degree[to] == 0) {
                ready.push(to);
            }
        }
    }

    return fin;
}

int main() {
    int n; int m; int a; int b;
    cin >> n >> m;
    vector<vector<int>> adj(n+1, vector<int>({}));
    vector<int> degree(n+1, 0);
    for (int i{0}; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        degree[b] += 1;
    }
    vector<int> d(n+1, -1);
    vector<int> p(n+1, -1);
    d[1] = 0;
    p[1] = 1;
    queue<int> top = kahns_algorithm(degree, adj);

    while (!top.empty()) {
        int cur = top.front();
        top.pop();

        if (d[cur] == -1) continue;

        for (int to: adj[cur]) {
            if (d[to] < d[cur] + 1) {
                d[to] = d[cur] + 1;
                p[to] = cur;
            }
        }
    }


    if (d[n] == -1) cout << "IMPOSSIBLE";
    else {
        vector<int> r;
        cout << d[n]+1 << "\n";
        while (n != p[n]) {
            r.push_back(n);
            n = p[n];
        }
        r.push_back(1);
        reverse(r.begin(), r.end());
        for (int in: r) cout << in << " ";
    }
}