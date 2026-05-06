#include <vector>
#include <iostream>
using namespace std;

long long build(int l, int r, int t, vector<long long> &arr, vector<long long> &tree) {
    if (l == r) {
        tree[t] = arr[l];
        return arr[l];
    }
    int mid = (l+r)/2;
    tree[t] = build(l, mid, 2*t, arr, tree) + build(mid+1, r, 2*t+1, arr, tree);
    return tree[t];
}

long long query(int l, int r, int tl, int tr, int t, vector<long long> &tree) {
    if (l > tr || r < tl) {
        return 0;
    }
    if (l <= tl && tr <= r) {
        return tree[t];
    }
    int tm = (tl + tr) / 2;

    return query(l, r, tl, tm, 2*t, tree) + query(l, r, tm + 1, tr, 2*t + 1, tree);
}

int main() {
    int n, q, a, b, x;
    cin >> n >> q;
    vector<long long> arr(n+1);
    vector<long long> tree(4 * n + 1);
    for (int i{1}; i <= n; i++) {
        cin >> arr[i];
    }
    build(1, n, 1, arr, tree);
    for (int i{0}; i < q; i++) {
        cin >> a >> b;
        cout << query(a, b, 1, n, 1, tree) << "\n";
    }

}