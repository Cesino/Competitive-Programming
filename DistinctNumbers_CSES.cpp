#include <algorithm>
#include <vector>
#include <iostream>
typedef long long int ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n;
    vector<int> s;
    for (int i{0}; i<n; i++) {
        cin >> x;
        s.push_back(x);
    }
    sort(s.begin(), s.end());
    int prev = s[0]; int c = 1;
    for (int i{1}; i<s.size(); i++) {
        if (s[i] != prev) {
            c++;
            prev = s[i];
        }
    }

    cout << c;
}