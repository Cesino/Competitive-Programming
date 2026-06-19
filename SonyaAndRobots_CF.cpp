#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int n, x;
    long long total{0};
    cin >> n;
    unordered_map<int, int> l;
    unordered_set<int> r;
    vector<int> arr(n);
    for (int i{0}; i < n; i++) {
        cin >> x;

        if (l.count(x)) l[x]++;
        else l[x] = 1;

        arr[i] = x;
    }
    for (int i{n-1}; i >= 0; --i) {
        l[arr[i]]--;
        if (l[arr[i]] == 0) l.erase(arr[i]);
        if (!r.count(arr[i])) {
            r.insert(arr[i]);
            total += l.size();
        }
    }

    cout << total;
}