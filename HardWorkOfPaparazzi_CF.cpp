#include <vector>
#include <utility>
#include <iostream>
#include <cmath>
using namespace std;

const int NEG = -1e9;

int main() {
    int r, n, x, y, t;
    cin >> r >> n;
    vector<int> dp(n+1, NEG);
    dp[0] = 0;
    vector<pair<int, pair<int, int>>> pp(n+1, {0, {1,1}});
    vector<int> mp(n+1, 0);
    for (int i{1}; i<=n; i++) {
        cin >> t >> x >> y;
        pp[i] = {t, {x,y}};
        int m = NEG;
        for (int j{i-1}; j>=0; j--) {
            if (t - pp[j].first >= 1000) {
                if (mp[j] >= m) m = mp[j] + 1;
                break;
            }
            if (abs(x-pp[j].second.first) + abs(y-pp[j].second.second) <= t - pp[j].first) {
                m = max(m, dp[j] + 1);
            }
        }
        dp[i] = m;
        if (m > mp[i-1]) mp[i] = m;
        else mp[i] = mp[i-1];
    }
    cout << mp[mp.size()-1];
}