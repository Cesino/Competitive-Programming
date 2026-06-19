#include <vector>
#include <iostream>
typedef long long int ll;
using namespace std;

ll build(int l, int r, int t, vector<ll> &arr, vector<ll> &tree, vector<ll> &idxs) {
    if (l == r) {
        tree[t] = arr[l];
        idxs[t] = l;
        return tree[t];
    }
    int m = (l+r) / 2;
    tree[t] = max(build(l, m, 2*t, arr, tree, idxs) , build(m+1, r, 2*t + 1, arr, tree, idxs));
    return tree[t];
}

ll update(int num, int idx, int l, int r, int t, vector<ll> &arr, vector<ll> &tree) {
    if (l==r) {
        tree[t] -= num;
        return tree[t];
    }
    int m = (l+r)/2;
    if (l <= idx && idx <= m) {
        update(num, idx, l, m, 2*t, arr, tree);
        tree[t] = max(tree[2*t], tree[2*t + 1]);
        return tree[t];
    }
    update(num, idx, m+1, r, 2*t + 1, arr, tree);
    tree[t] = max(tree[2*t], tree[2*t + 1]);
    return tree[t];
}

ll group(int g, int l, int r, int t, vector<ll> &arr, vector<ll> &tree) {
    if (g > tree[t]) {
        return 0;
    }
    if (l == r) {
        return t;
    }

    int m = (l+r) / 2;
    if (tree[2*t] >= g) {
        return group(g, l, m, 2*t, arr, tree);
    }
    return group(g, m+1, r, 2*t + 1, arr, tree);
}

int main() {
    ll n, m, r;
    cin >> n >> m;
    vector<ll> arr(n+1);
    vector<ll> tree(4*n + 1);
    vector<ll> idx(4*n + 1);
    for (int i{1}; i <= n; i++) {
        cin >> arr[i];
    }
    build(1, n, 1, arr, tree, idx);
    for (int i{0}; i < m; i++) {
        cin >> r;
        ll index = group(r, 1, n, 1, arr, tree);
        ll cur_ind = idx[index];
        cout << cur_ind << " ";
        if (index != 0) update(r, cur_ind, 1, n, 1, arr, tree);
    }
}