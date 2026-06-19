#include <iostream>
#include <string_view>
#include <vector>
#define ll long long
using namespace std;

int bin_most(ll total_cost, ll r, ll hi) {
    ll lo = 0;
    while (lo < hi) {
        ll mid = l + (r - l) / 2;
        if (mid * total_cost > r) r = mid;
        else l = mid + 1;
    }
    return l;
}

int main() {
    ll n_b, n_s, n_c;
    ll p_b, p_s, p_c, r;
    string s;
    cin >> s;
    ll ing[3]{0};
    ll prices[3]{0};
    ll cur_count[3]{0};

    for (int i{}; i < s.size(); i++) {
        if (s[i] == 'B') 0[ing] += 1;
        else if (s[i] == 'S') 1[ing] += 1;
        else 2[ing] += 1;
    }

    cin >> n_b >> n_s >> n_c;
    cin >> p_b >> p_s >> p_c;
    prices[0] = p_b; prices[1] = p_s; prices[2] = p_c;
    cur_count[0] = n_b; cur_count[1] = n_s; cur_count[2] = n_c;
    for (int i{}; i < 3; i++) r += prices[i] * cur_count[i];

}