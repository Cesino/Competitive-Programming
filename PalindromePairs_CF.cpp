#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int n; string s; int cur; int k;
    cin >> n;
    vector<int> bitmask(n, 0);
    for (int i{0}; i < n ; i++) {
        cin >> s;
        cur = 0;
        for (char c: s) {
            k = c - 'a';
            if (cur & (1 << k)) cur ^= (1 << k);
            else cur |= (1 << k);
        }
        bitmask[i] = cur;
    }

    unordered_map<int, long long> seen;
    long long total = 0;
    for (int i{0}; i < n; i++) {
        cur = bitmask[i];
        for (int j{0}; j < 26; j++) {
             if (seen.contains(cur ^ (1 << j))) {
                 total += seen[cur ^ (1 << j)];
             }
        }
        if (seen.contains(cur)) {
            total += seen[cur];
            seen[cur] += 1;
        }
        else {
            seen[cur] = 1;
        }
    }

    cout << total;

}