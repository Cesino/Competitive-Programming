#include <cmath>
#include <iostream>
using namespace std;

int main() {
    long long t, n, k;
    cin >> t;
    long long MOD = 1e+9 + 7;

    for (int i{0}; i < t; i++) {
        cin >> n >> k;
        long long res = 1;
        while (k > 0) {
            if (k & 1) res = res * n % MOD;
            n = n * n % MOD;
            k >>= 1;
        }

        cout << res << "\n";
    }

}