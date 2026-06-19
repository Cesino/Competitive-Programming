#include <string>
#include <iostream>
using namespace std;

int main() {
    int n; string s; string t; string output; bool f = true;
    int dis = -1;
    cin >> n;
    cin >> s >> t;
    for (int i{}; i < n; ++i) {
        int cur = s[i];
        int target = t[i];

        if (dis == -1) {
            if (cur > target) dis = (10 - cur) + target;
            else dis = target - cur;
        }
        else {
            if (cur > target) {
                if ((10 - cur) + target != dis) f = false;
            }

            else {
                if (cur + dis != target) f = false;
            }
        }
    }

    cout << (f ? "YA" : "TIDAK");

}