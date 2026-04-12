#include <vector>
#include <iostream>
#include <utility>
using namespace std;

int bin_search(int n, vector<int> seq) {
    int s = 0;
    int e = seq.size();
    while (e > s) {
        int mid = (e+s)/2;
        if (seq[mid] >= n) {
            e = mid;
        } else {
            s = mid + 1;
        }
    }
    return s;
}

int main() {
    vector<int> tail; int n; int x;
    vector<int> seq;
    cin >> n;
    for (int i{0}; i < n; i++) {
        cin >> x;
        seq.push_back(x);
    }
    tail.push_back(seq[0]);
    for (int i{1}; i < seq.size(); i++) {
        if (seq[i] <= tail[tail.size()-1]) {
            n = bin_search(seq[i], tail);
            tail[n] = seq[i];
        } else {
            tail.push_back(seq[i]);
        }
    }
    cout << tail.size();
}