#include <vector>
#include <iostream>
#include <string>
#include <utility>

using namespace std;

const vector<pair<int, int>> dir({{1,0}, {0,1}});
const int MOD = 1e9+7;

long dp_dfs(int r, int c,vector<string> &grid, vector<vector<int>> &dp) {
    if (r == grid.size()-1 && c == grid.size()-1) return 1;
    long cur_pos = 0;
    dp[r][c] = 0;
    for (pair<int, int> d: dir) {
        if ((grid.size() > r + d.first) && (grid.size() > c + d.second)) {
            if (grid[r+d.first][c+d.second] == '.') {
                if (dp[r+d.first][c+d.second] > -1)  cur_pos = (cur_pos + dp[r+d.first][c+d.second])%MOD;
                else cur_pos = (cur_pos + dp_dfs(r+d.first, c+d.second, grid, dp))%MOD;
            }
        }
    }
    dp[r][c] = cur_pos;
    return cur_pos;
}
int main() {
    string l; vector<string> grid; int n;
    cin >> n;
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for (int i{0}; i < n; i++) {
        cin >> l;
        grid.push_back(l);
    }
    if (grid[0][0] == '*') cout << 0;
    else cout << dp_dfs(0, 0, grid, dp);
}