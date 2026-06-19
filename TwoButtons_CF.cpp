#include <iostream>
#include <unordered_map>
using namespace std;

void smaller(int n, int m, int cur, int& global_min, unordered_map<int, int>& memo) {
    if (cur > global_min) return;
    if (memo.contains(n) && cur > memo[n]) return;
    if (n <= 0 || n > 1e4) return;
    memo[n] = cur;
    if (n==m) {
        if (cur < global_min) global_min = cur;
        return;
    }
    if (n > m) {
        smaller(n-1, m, cur + 1, global_min,memo);
        smaller(2*n, m, cur + 1, global_min, memo);
    }
    else {
        smaller(2*n, m, cur + 1, global_min,memo);
        smaller(n-1, m, cur + 1, global_min, memo);
    }
}

int main() {
    int n,m;
    cin >> n >> m;
    int global_min = 1e9;
    unordered_map<int, int> a;
    smaller(n, m, 0, global_min, a);
    cout << global_min;

}