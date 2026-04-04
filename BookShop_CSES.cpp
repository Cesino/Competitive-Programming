#include <vector>
#include <iostream>
using namespace std;
int main() {
    int n, x;
    cin >> n >> x;
    vector<int> pages(n), prices(n); int most_pages = 0;
    for (int i{0}; i < n; i++) {cin >> prices[i];}
    for (int i{0}; i < n; i++) {cin >> pages[i];}
    vector<int> dp(x+1, -1);
    dp[0] = 0;
    for (int i{0}; i < n; i++) {
        vector<int> dp_new_val(x+1, -1);
        for (int j{0}; j < x+1; j++) {
            if (dp[j] >= 0 && j + prices[i] <= x) {
                dp_new_val[j + prices[i]] = max(dp[j + prices[i]], dp[j] + pages[i]);
            }
        }
        for (int z{0}; z < x+1; z++) {
            if (dp_new_val[z] > -1){dp[z] = dp_new_val[z];}
        }
    }
    for (int m: dp){most_pages = max(most_pages, m);}
    cout << most_pages;
}