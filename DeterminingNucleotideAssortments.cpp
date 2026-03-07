#include <vector>
#include <string>
#include <iostream>
#include <numeric>

using namespace std;

int main() {
    string seq; vector<int> A_count={0}; vector<int> T_count={0}; vector<int> G_count={0}; vector<int> C_count={0};
    int A_last=0; int T_last=0; int G_last=0; int C_last=0;
    int inp; int s; int e;
    cin >> seq;
    if (seq[0] == 'A') {
        A_count[0] = 1;
        A_last = 1;
    }
    if (seq[0] == 'T') {
        T_count[0] = 1;
        T_last = 1;
    }
    if (seq[0] == 'G') {
        G_count[0] = 1;
        G_last = 1;
    }
    if (seq[0] == 'C') {
        C_count[0] = 1;
        C_last = 1;
    }
    for (int i{1}; i<seq.length(); i++) {
        if (seq[i] == 'A') {
            A_last += 1;
        }
        else if (seq[i] == 'T') {
            T_last += 1;
        }
        else if (seq[i] == 'G') {
            G_last += 1;
        }
        else {
            C_last += 1;
        }
        A_count.push_back(A_last);
        T_count.push_back(T_last);
        G_count.push_back(G_last);
        C_count.push_back(C_last);
    }

    cin >> inp;
    for (int i{0}; i<inp; i++) {
        int A_finalcounts = 0; int T_finalcounts = 0; int G_finalcounts = 0; int C_finalcounts = 0;
        cin >> s >> e;
        vector<char> output = {'A', 'T', 'G', 'C'};
        vector<int> indices(output.size());
        iota(indices.begin(), indices.end(), 0);
        vector<int> count = {};
        if (seq[s-1] == 'A') A_finalcounts++;
        else if (seq[s-1] == 'T') T_finalcounts++;
        else if (seq[s-1] == 'G') G_finalcounts++;
        else C_finalcounts++;
        A_finalcounts += A_count[e-1] - A_count[s-1]; count.push_back(A_finalcounts);
        T_finalcounts += T_count[e-1] - T_count[s-1]; count.push_back(T_finalcounts);
        G_finalcounts += G_count[e-1] - G_count[s-1]; count.push_back(G_finalcounts);
        C_finalcounts += C_count[e-1] - C_count[s-1]; count.push_back(C_finalcounts);

        sort(indices.begin(), indices.end(), [&](int a, int b) {
            if (count[a] == count[b]) {
                return a < b;
            }
            return count[a] > count[b];
        });
        string test = "AAAA";
        for (int i{0}; i<4; i++) {
            test[i] = output[indices[i]];
        }
        cout << test << "\n";
    }
}