#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n.length()+1, vector<int>(m.length()+1, -1));
    if (m.length() == 0 || n.length() == 0) {
        cout << max(m.length(), n.length());
    }
    else {
        for (int i{0}; i<m.length()+1; i++) {
            dp[0][i] = i;
        }
        for (int i{0}; i<n.length()+1; i++) {
            dp[i][0] = i;
        }

        for (int i{1}; i < n.length()+1; i++) {
            for (int j{1}; j < m.length()+1; j++) {
                dp[i][j] = m[j-1] == n[i-1] ? dp[i-1][j-1] : min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
            }
        }
        cout << dp[n.length()][m.length()];
    }
}