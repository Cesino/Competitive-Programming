#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

int bin_search(int t, int l, int r, vector<int> &a) {
    int mid = (l+r)/2;
    while (l < r) {
        mid = (l+r)/2;
        if (a[mid] > t && a[mid - 1] > t) l = mid + 1;
        else if (a[mid] < t && a[mid-1] < t) r = mid - 1;
        else return mid;
    }
    return mid;
}

int main() {
    int n, x;
    ll k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i{}; i < n; i++) {
        cin >> x;
        arr[i] = x;
    }
    sort(arr.begin(), arr.end());
    ll median = arr[arr.size()/2];

    if (k + median < arr[arr.size()/2 + 1]) cout << k + median;
    else {
        k -= arr[arr.size()/2 + 1] - median;
        ll max_median = arr[arr.size()/2 + 1];
        while (k > 0) {
            int t = bin_search(max_median + 1, (n-1)/2, n-1, arr);
            if (t - (n-1)/2 > k) break;
            k -= t - (n-1)/2;
            max_median += 1;
        }
        cout << max_median;
    }
}
