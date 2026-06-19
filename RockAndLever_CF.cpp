#include <vector>
#include <iostream>
using namespace std;

int main() {
    int t, n, x;
    cin >> t;
    vector<int> bit(32, 0);
    for (int i{0}; i < t; i++) {
        cin >> n;
        for (int j{0}; j < n; j++) {
            cin >> x;
            int bucket = 31 - __builtin_clz(x);
            bit[bucket]++;
        }

        int total = 0;
        for (int i{0}; i < 32; i++) {
            total += bit[i] * (bit[i] - 1) / 2;
        }
        cout << total << "\n";
        bit = vector<int>(32, 0);
    }
}