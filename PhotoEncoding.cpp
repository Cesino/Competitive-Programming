#include <vector>
#include <iostream>

using namespace std;

int main() {
    int inp; int num; int min_size = 0;
    cin >> inp;
    vector<int> md(201);

    for (int i{0}; i<inp; i++) {
        cin >> num;
        md[num]++;
    }

    int s = md.size();
    for (int i{s}; i>=0; i--) {
        if (md[i] > 0) {
            int min_cur = ((i+1)/2)+1;
            if (i%2 == 0 && md[i] != 1) {
                min_cur += md[i]/2;
            }
            if (i%2 != 0 && md[i] != 1) {
                min_cur += (md[i]/2 - 1) + (md[i]%2);
            }
            if (min_cur > min_size) {
                min_size = min_cur;
            }
        }
    }
    cout << min_size;
}