#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n, t, x;
    cin >> t;
    for (int i{}; i < t; ++i) {
        cin >> n;
        unordered_map<int, int> m;
        for (int j{}; j < n; j++) {
            cin >> x;
            if (m.count(x) <= 0) m[x] = 1;
            else ++m[x];
        }
        int next = 0;

        for (int j{1}; j < 4000; j = j << 1) {
            m[j] += next;
            next = m[j] / 2;
        }


        cout << (m[2048] >= 1 ? "YES" : "NO") << "\n";

    }
}
