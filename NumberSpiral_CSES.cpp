#include <iostream>
typedef long long ll;
using namespace std;

int main() {
    ll x, y, t; cin >> t;
    for (int i{0}; i<t; i++) {
        cin >> y >> x;
        ll n = max(x, y);
        if (n == x) {
            if (x%2 == 0) cout << x*x - 2*x + 1 + y;
            else cout << x*x - y + 1;
        }
        else {
            if (y%2 == 0) cout << y*y - 2*y + 1 + x;
            else cout << y*y - x + 1;
        }
        cout << "\n";
    }
}