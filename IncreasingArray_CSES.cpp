#include <iostream>
#include <vector>

typedef long long ll;
using namespace std;

int main() {
    ll n;
    cin >> n;
    ll cur; ll prev = -1; ll m = 0;
    for (int i{0}; i < n; i++) {
        cin >> cur;
        if (cur < prev) {m += prev - cur;}
        else prev = cur;
    }
    cout << m;
}