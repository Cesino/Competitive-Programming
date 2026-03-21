#include <vector>
#include <set>
#include <queue>
#include <utility>
#include <iostream>
using namespace std;


long long const INF = 4e18;
vector<vector<pair<int, int>>> adj;

int main() {
    int n; int m; int q;
    vector<vector<long long>> min_dist;
    cin >> n >> m >> q;
    int a; int b; int w;
    vector<vector<long long>> d(n+1, vector<long long>(n+1, INF));
    for (int i{0}; i < m;  i++) {
        cin >> a >> b >> w;
        d[a][b] = min(d[a][b], 1LL * w);
        d[b][a] = min(d[b][a], 1LL * w);
    }
    for (int i{0}; i < n+1; i++) {
        d[i][i] = 0;
    }
    for (int k{0}; k < n+1; k++) {
        for (int i{0}; i < n+1; i++) {
            for (int j{0}; j < n+1; j++) {
                if (d[i][k] < INF && d[k][j] < INF) {
                    d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
                }
            }
        }
    }

    for (int i{0}; i < q; i++) {
        cin >> a >> b;
        cout << (d[a][b] < INF ? d[a][b] : -1) << '\n';
    }
}