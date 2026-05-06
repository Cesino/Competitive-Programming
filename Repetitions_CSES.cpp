#include <iostream>
#include <string>

using namespace std;
int main() {
    string s; int cur = 1; int m = 1;
    cin >> s; char prev = s[0];
    for (int i{1}; i < s.size(); i++) {
        if (s[i] == prev) {
            cur++;
        }
        else {
            if (cur > m) m = cur;
            cur = 1; prev = s[i];
        }
    }
    if (cur > m) m = cur;
    cout << m;
}