#include <vector>
#include <algorithm>
#include <iostream>
#define ll long long
using namespace std;

int main() {
    int n; ll t;
    cin >> n;
    vector<ll> a(n);
    vector<ll> dp(1e5);
    vector<ll> m(1e5+1, 0);
    for (int i{}; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    dp[0] = 0;
    dp[1] = upper_bound(a.begin(), a.end(), 1) - a.begin();
    dp[2] = 2 * (upper_bound(a.begin(), a.end(), 2) - upper_bound(a.begin(), a.end(), 1));
    m[1] = dp[1]; m[2] = max(dp[1], dp[2]);

    for(int i{3}; i < 1e5+1; i++) {
        ll amount = i * (upper_bound(a.begin(), a.end(), i) - upper_bound(a.begin(), a.end(), i-1));
        dp[i] = m[i-2] + amount;
        if (dp[i] > m[i-1]) m[i] = dp[i];
        else m[i] = m[i-1];
    }
    cout << m[1e5];
}