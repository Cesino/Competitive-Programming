#include <iostream>
#include <vector>
#include <limits.h>
#include <set>
#include <algorithm>
#define ll long long int
#define set set<ll>
using namespace std;

int main() {
    ll n;
    cin >> n;
    vector<ll> m(n);
    vector<ll> pos(n);
    vector<ll> dp(n, 0);
    set seen;
    vector<bool> s(n, false);
    for (ll i{0};i<n;i++) {
        cin >> m[i];
        pos[i] = i;
    }
    sort(pos.begin(), pos.end(), [&](ll a, ll b) {
        if (m[a] == m[b]) return a < b;
        return m[a] < m[b];
    });

    for (ll i{0};i<n;i++) {
        ll cur = pos[i];
        ll mm = 0;
        dp[cur] = 1;
        seen.insert(cur);
        while (seen.count(cur+1) > 0 && cur < n-1 && m[cur+1] != m[pos[i]]) {
            if (dp[cur+1] > mm) mm = dp[cur+1];
            cur+=1;
        }
        cur = pos[i];
        while (seen.count(cur-1) > 0 && cur > 0 && m[cur-1] != m[pos[i]]) {
            if (dp[cur-1] > mm) mm = dp[cur-1];
            cur-=1;
        }
        dp[pos[i]] += mm;
    }
    ll mm = 0;
    for (ll z: dp) {
        if (z > mm) mm = z;
    }
    cout << mm;
}