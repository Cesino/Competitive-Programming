#include <iostream>

using namespace std;
typedef long long ll;
int main() {
    ll n; ll sum = 0; ll cur;
    cin >> n;
    for (int i{0}; i < n-1; i++) {
        cin >> cur;
        sum += cur;
    }

    cout << n*(n+1)/2 - sum;
}