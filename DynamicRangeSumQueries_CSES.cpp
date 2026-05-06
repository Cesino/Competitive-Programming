#include <vector>
#include <iostream>
using namespace std;
#define ll long long

ll sum(int l, int r, int tl, int tr, int t, vector<ll> &arr, vector<ll> &tree) {
    if (tl > r || l > tr) {
        return 0;
    }
    if (tl >= l && tr <= r) {
        return tree[t];
    }
    int m = (tl+tr) / 2;
    ll s = sum(l, r, tl, m, 2*t, arr, tree) + sum(l, r, m+1, tr, 2*t + 1, arr, tree);
    return s;
}

ll build(int l, int r, int t, vector<ll> &arr, vector<ll> &tree) {
    if (l == r) {
        tree[t] = arr[l];
        return arr[l];
    }

    int m = (l+r) / 2;
    tree[t] = build(l, m, 2*t, arr, tree) + build(m+1, r, 2*t +1, arr, tree);
    return tree[t];
}

ll update(int idx, ll n, int l, int r, int t, vector<ll> &arr, vector<ll> &tree) {
    if (l==r) {
        ll diff = n - tree[t];
        tree[t] = n;
        return diff;
    }

    int m = (l+r) / 2; ll cur;
    if (l <= idx && idx <= m) {
        cur = tree[t] + update(idx, n, l, m, 2*t, arr, tree);
    }
    else {
        cur = tree[t] + update(idx, n, m+1, r, 2*t + 1, arr, tree);
    }

    ll cur_dif = cur - tree[t];
    tree[t] = cur;
    return cur_dif;
}

int main() {
    int n, q, k, a, b;
    cin >> n >> q;
    vector<ll> arr(n+1);
    vector<ll> tree(4*n + 1);
    for (int i{1}; i <= n; i++) {
        cin >> arr[i];
    }
    build(1, n, 1, arr, tree);
    for (int i{1}; i <= q; i++) {
        cin >> k >> a >> b;
        if (k == 1) {
            update(a, b, 1, n, 1, arr, tree);
        }
        else {
            cout << sum(a, b, 1, n, 1, arr, tree) << "\n";
        }
    }
}