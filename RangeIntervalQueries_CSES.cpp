#include <vector>
#include <iostream>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;

int buildtree(int l, int r, int t, vector<int> &tree, vector<int> &seen) {
    if (l == r) {
        tree[t] = seen[l];
        return tree[t];
    }

    int mid = (l+r) / 2;
    int left = buildtree(l, mid, 2*t, tree, seen);
    int right = buildtree(mid+1, r, 2*t + 1, tree, seen);
    tree[t] = max(left, right);
    return tree[t];
}

int updatetree(int tl, int tr, int t, int ch, int ch_n, vector<int> &tree, vector<int> &seen) {
    if (tl == tr) {
        tree[t] = ch_n;
        seen[ch] = ch_n;
        return tree[t];
    }
    int mid = (tl+tr)/2;
    int left, right;

    if (tl <= ch && ch <= mid) left = updatetree(tl, mid, 2*t, ch, ch_n, tree, seen);
    else left = tree[2*t];

    if (mid + 1 <= ch && ch <= tr) right = updatetree(mid+ 1, tr, 2*t + 1, ch, ch_n, tree, seen);
    else right = tree[2*t + 1];

    tree[t] = max(left, right);
    return tree[t];
}

int querytree(int l, int r, int tl, int tr, int t, vector<int> &tree) {
    if (l <= tl && tr <= r) {
        return tree[t];
    }
    if (l > tr || r < tl) return 0;

    int mid = (tl+tr)/2;
    return max( querytree(l, r, tl, mid, 2*t, tree), querytree(l, r, mid+1, tr, 2*t+1, tree));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q, t, a, b;
    cin >> n >> q;
    unordered_map<int, set<int>> last;
    vector<int> seen(n+1, 0);
    vector<int> actual(n+1, 0);
    vector<int> tree(4*n + 1, -1);
    seen[0] = -1; actual[0] = -1;
    for (int i{1}; i < n+1; i++) {
        cin >> a;
        if (last.find(a) != last.end()) {
            seen[i] = *prev(last[a].end());
        }
        else {
            seen[i] = 0;
        }
        actual[i] = a;
        last[a].insert(i);
    }

    buildtree(1,n, 1, tree, seen);

    for (int i{0}; i < q; i++) {
        cin >> t >> a >> b;
        if (t == 1) {
            int old = actual[a];
            if (b == old) continue;
            auto it = last[old].find(a);

            int before = 0;
            int after = 0;

            if (it != last[old].begin()) {
                before = *prev(it);
            }

            auto it_after = next(it);

            if (it_after != last[old].end()) after = *it_after;

            if (after != 0) updatetree(1, n, 1, after, before, tree, seen);

            last[old].erase(it);

            auto it2 = last[b].lower_bound(a);

            before = 0;
            after = 0;

            if (it2 != last[b].begin()) before = *prev(it2);
            if (it2 != last[b].end()) after = *it2;

            updatetree(1, n, 1, a, before, tree, seen);
            if (after != 0) updatetree(1, n, 1, after, a, tree, seen);

            last[b].insert(a);
            actual[a] = b;
        }
        else {
            int mx = querytree(a, b, 1, n, 1, tree);

            if (mx >= a) cout << "NO\n";
            else cout << "YES\n";
        }
    }
}