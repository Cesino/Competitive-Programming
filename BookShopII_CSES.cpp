#include <vector>
#include <iostream>
#include <utility>
using namespace std;

int main() {
    int n, x, h, s, k;
    cin >> n >> x;
    vector<int> price(x+1, 0);
    vector<pair<int, int>> pages;
    for (int i{0}; i < n; i++) {
        cin >> h;
        pages.push_back({h, 0});
    }
    for (int i{0}; i < n; i++) {
        cin >> s;
        pages[i].second = s;
    }
    for (int i{0}; i < n; i++) {
        cin >> k;
        int cnt = 1; int rem = k-1;
        while (rem >= cnt*2) {
            cnt *= 2;
            rem -= cnt;
            pages.push_back({cnt * pages[i].first, cnt * pages[i].second});
        }
        if (rem > 0) pages.push_back({(rem) * pages[i].first, (rem) * pages[i].second});
    }

    int size = price.size()-1;
    int m = 0;
    for (int j{0}; j < pages.size(); j++) {
        int cur_price = pages[j].first;
        int cur_pages = pages[j].second;
        for (int i{size}; i >= 0; i--) {
            if (i + cur_price <= size) {
                if (price[i + cur_price] <= cur_pages + price[i]) {
                    price[i + cur_price] = cur_pages + price[i];
                    if (price[i + cur_price] >= m) m = price[i + cur_price];
                }
            }
        }
    }
    cout << m;
}