#include <vector>
#include <iostream>
using namespace std;

int main() {
    int t, n;
    cin >> t;
    for (int i{}; i < t; i++) {
        cin >> n;
        if (n <= 3) cout << -1 << "\n";
        else {
            vector<int> a(n+1);
            int rem = n%4;
            int max = n - n%4;
            for (int j{1}; j < max - 1; j+=4) {
                a[j] = j + 1; a[j + 1] = j + 3; a[j + 2] = j; a[j + 3] = j + 2;
            }

            if (rem == 1) {
                a[max + 1] = n;
            }
            else if (rem == 2) {
                int idx = max - 3;
                a[idx] = idx+1;
                a[idx+1] = idx+5;
                a[idx+2] = idx+3;
                a[idx+3] = idx;
                a[idx+4] = idx+2;
                a[idx+5] = idx+4;
            }

            else if (rem == 3) {
                int idx = max - 3;
                a[idx] = idx+2;
                a[idx+1] = idx+5;
                a[idx+2] = idx+1;
                a[idx+3] = idx+4;
                a[idx+4] = idx;
                a[idx+5] = idx+3;
                a[idx+6] = idx+6;
            }

            else {
                int idx = max - 3;
                a[idx] = idx + 1; a[idx + 1] = idx + 3; a[idx + 2] = idx; a[idx + 3] = idx + 2;
            }

            for (int j{1}; j < n+1; j++) {
                cout << a[j] << " ";
            }
            cout << "\n";
        }
    }
}