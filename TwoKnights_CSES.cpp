#include <iostream>
using namespace std;
typedef long long ll;
int main() {
    ll n;
    cin >> n;
    for (ll i{1}; i <= n; i++) {
        ll count = i*i*(i*i-1)/2 - 4*(i-1)*(i-2);
        cout << count << "\n";
    }
}