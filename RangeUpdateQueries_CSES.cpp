#include <vector>
#include <iostream>
typedef long long ll;
using namespace std;


void increase(int inc, int l, int r, int tl, int tr, int t, vector<ll> &arr, vector<ll> &tree) {
    if (tl > r || tr < l) return;
    if (tl >= l && tr <= r) {tree[t] += inc; return;}

    int m = (tl + tr)/2;
    increase(inc, l, r, tl, m, 2*t, arr, tree);
    increase(inc, l, r, m+1, tr, 2*t + 1, arr, tree);
}

ll pos(int idx, int l, int r, int t, vector<ll> &arr, vector<ll> &tree) {
    if (l == r) {
        return tree[t];
    }
    int m = (l+r) / 2;
    ll c;
    if (l <= idx && idx <= m) {
        c = tree[t] + pos(idx, l, m, 2*t, arr, tree);
    }
    else {
        c = tree[t] + pos(idx, m+1, r, 2*t+1, arr, tree);
    }
    return c;
}

int main() {
    int n, q, k, a, b;
    ll u;
    cin >> n >> q;
    vector<ll> arr(n+1);
    vector<ll> tree(4*n + 1, 0);
    for (int i{1}; i <= n; i++) {
        cin >> arr[i];
    }
    for (int i{0}; i < q; i++) {
        cin >> k;
        if (k==1) {
            cin >> a >> b >> u;
            increase(u, a, b, 1, n, 1, arr, tree);
        }
        else {
            cin >> a;
            cout << arr[a] + pos(a, 1, n, 1, arr, tree) << "\n";
        }
    }

}