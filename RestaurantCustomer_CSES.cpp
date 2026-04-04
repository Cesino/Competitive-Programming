#include <vector>
#include <utility>
#include <iostream>
#include <set>

using namespace std;


int main() {
    int n; int a; int l;
    vector<pair<int, int>> t;
    cin >> n;
    vector<int> leave;

    for (int i{0}; i < n; i++) {
        cin >> a >> l;
        t.push_back({a, l});
        leave.push_back(l);
    }

    sort(t.begin(), t.end());
    sort(leave.begin(), leave.end());
    int max_cust = 0;

    for (int i{});

}