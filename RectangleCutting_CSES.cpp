#include <vector>
#include <iostream>
using namespace std;

const int INF = 1e9;

int rect(int a, int b, vector<vector<int>> &dp) {
    if (a == b) return 0;
    if (dp[a][b] != INF) return dp[a][b];
    int minm = INF;

    for (int i{1}; i < a; i++) {
        int cur_d = 1 + rect(a-i, b, dp) + rect(i, b, dp);
        if (cur_d < minm) {
            minm = cur_d;
        }
    }
    for (int i{1}; i < b; i++) {
        int cur_d = 1 + rect(a, b-i, dp) + rect(a, i, dp);
        if (cur_d < minm) {
            minm = cur_d;
        }
    }
    if (a < dp.size() && b < dp[0].size()) dp[a][b] = minm;
    if (b < dp.size() && a < dp[0].size()) dp[b][a] = minm;
    return minm;
}

int main() {
    int a, b;
    cin >> a >> b;
    vector<vector<int>> dp(a+1, vector<int>(b+1, INF));
    cout << rect(a, b, dp);
}