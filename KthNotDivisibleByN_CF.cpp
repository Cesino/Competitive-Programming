#include <vector>
#include <iostream>
#define ll long long
using namespace std;

int bin_search(ll n, ll k) {
    ll lo = 0; ll hi = n * (k + 1);
    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        if (mid - mid/n >= k) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

int main() {
    ll n, k, t;
    cin >> t;
    for (int i{}; i < t; i++) {
        cin >> n >> k;
        cout << bin_search(n, k) << "\n";
    }
}