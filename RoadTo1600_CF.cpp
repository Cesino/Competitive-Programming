#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n < 3) cout << -1;
    else if (n == 3) {
        vector<vector<int>> a = {{1,7,9},{3,2,5},{4,8,6}};
        for (auto& x: a) {
            for (auto& y: x) {
                cout << y << " ";
            }
            cout << "\n";
        }
    }
    else {
        vector<vector<int>> a(n+1, vector<int>(n+1, 0));
        if (n % 2 == 0) {
            a[1][n] = n*n - 4;
            a[n][1] = n*n - 2;
            a[n][n-1] = n*n - 3;
            a[n][n] = n*n - 1;
            a[n-1][1] = n*n;

            int counter = 1;

            int idx = n-2;
            while (idx != 1) {a[n][idx] = counter; ++counter; --idx;}

            idx = 2;
            while (idx <= n) {a[n-1][idx] = counter; ++counter; ++idx;}

            for (int i{n-2}; i > 0; --i) {
                if (i % 2 == 0) {
                    for (int j{n}; j > 0; --j) {
                        a[i][j] = counter; ++counter;
                    }
                }
                else {
                    for (int j{1}; j <= n; ++j) {
                        a[i][j] = counter; ++counter;
                    }
                }
            }
        }

        else {
            a[1][n] = n*n - 3;
            a[n][1] = n*n - 2;
            a[n-1][1] = n*n - 1;
            a[n][n] = n*n;

            int counter = 1;

            int idx = n-1;
            while (idx != 1) {a[n][idx] = counter; ++counter; --idx;}

            idx = 2;
            while (idx <= n) {a[n-1][idx] = counter; ++counter; ++idx;}

            for (int i{n}; i >= 1; --i) {
                if (i % 2 != 0) {
                    for (int j{n-2}; j > 1; --j) {
                        a[j][i] = counter;
                        ++counter;
                    }
                }

                else {
                    for (int j{2}; j <= n - 2; ++j) {
                        a[j][i] = counter;
                        ++counter;
                    }
                }
            }

            for (int i{1}; i < n; i++) {a[1][i] = counter; ++counter;}

        }

        int c = 0;
        for (auto& x: a) {
            for (auto& y: x) {
                if (y != 0) {cout << y << " "; ++c;}
            }
            if (c>0) cout << "\n";
        }
    }
}