#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; char size; int slices;
    cin >> n;
    vector<int> counts = {0,0,0};
    vector<int> max_slices= {6, 8, 12};
    for (int i{0}; i<n; i++) {
        cin >> size >> slices;
        if (size == 'S') {
            counts[0] += slices;
        }
        else if (size == 'M') {
            counts[1] += slices;
        }
        else {
            counts[2] += slices;
        }
    }
    int total = 0;
    for (int i{0}; i<counts.size(); i++) {
        if (counts[i]%max_slices[i] == 0) {
            total += counts[i]/max_slices[i];
        }
        else {
            total += counts[i]/max_slices[i] + 1;
        }
    }
    cout << total;
}