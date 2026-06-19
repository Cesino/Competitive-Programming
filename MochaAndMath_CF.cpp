#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n, t, x, cur;
    cin >> n;
    for (int i{0}; i < n; i++) {
        cin >> t;
        cin >> cur;
        for (int j{1}; j < t; j++) {
            cin >> x;
            cur &= x;
        }
        cout << cur << "\n";
    }
}