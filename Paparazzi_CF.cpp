#include <vector>
#include <iostream>
#include <utility>
using namespace std;

int main() {
    int r, n, t, x, y;
    cin >> r >> n;
    vector<pair<int, pair<int, int>>> p;
    vector<int> dp(-1);

    for (int i{0}; i < n; i++) {
        cin >> t >> x >> y;
        p.push_back({t, {x,y}});
    }


}