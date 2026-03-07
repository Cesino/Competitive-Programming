#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n; int num;
    cin >> n;
    int num_cards = 2*n;
    int min_score = 0; int max_score = 0;
    vector<int> alice_cards = {};
    for (int i{0}; i<n; i++) {
        cin >> num;
        alice_cards.push_back(num);
    }
    sort(alice_cards.begin(), alice_cards.end());
    int s = alice_cards.size() - 1;
    int count = 0;

    for (int i{s}; i>=0; i--) {
        if (num_cards - alice_cards[i] - count > 0) {
            count++;
        }
        else {
            min_score++;
        };
        count++;
    }
    count = 0;
    for (int i{0}; i<=s; i++) {
        if (alice_cards[i] - 1 - count > 0) {
            max_score++;
            count++;
        }
        count++;
    }
    cout <<  min_score << " " << max_score;
}