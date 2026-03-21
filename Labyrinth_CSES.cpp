#include <vector>
#include <utility>
#include <set>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

constexpr int INF = 10000000;

void dijkstra(pair<int, int> s,  vector<vector<int>> &d, vector<vector<char>> &p, vector<vector<int>> &m) {
    pair<int, int> cur;
    int R = d.size();
    int C = d[0].size();
    set<pair<int, int>> q;

    d[s.first][s.second] = 0;
    int oned = s.first * C + s.second;
    q.insert({0, oned});

    while (!q.empty()) {
        cur = *q.begin();
        int cur_r = cur.second / C;
        int cur_c = cur.second % C;
        q.erase(q.begin());


        if (cur_c+1 < C && m[cur_r][cur_c+1] == 1) {
            if (d[cur_r][cur_c] + 1 < d[cur_r][cur_c+1]) {
                d[cur_r][cur_c+1] = d[cur_r][cur_c] + 1;
                p[cur_r][cur_c+1] = 'R';
                oned = cur_r * C + (cur_c + 1);
                q.insert({d[cur_r][cur_c+1], oned});
            }
        }

        if (cur_c-1 >= 0 && m[cur_r][cur_c-1] == 1) {
            if (d[cur_r][cur_c] + 1 < d[cur_r][cur_c-1]) {
                d[cur_r][cur_c-1] = d[cur_r][cur_c] + 1;
                p[cur_r][cur_c-1] = 'L';
                oned = cur_r * C + (cur_c - 1);
                q.insert({d[cur_r][cur_c-1], oned});
            }
        }

        if (cur_r+1 < R && m[cur_r+1][cur_c] == 1) {
            if (d[cur_r][cur_c] + 1 < d[cur_r+1][cur_c]) {
                d[cur_r+1][cur_c] = d[cur_r][cur_c] + 1;
                p[cur_r+1][cur_c] = 'D';
                oned = (cur_r+1) * C + (cur_c);
                q.insert({d[cur_r+1][cur_c], oned});
            }
        }

        if (cur_r-1 >= 0 && m[cur_r-1][cur_c] == 1) {
            if (d[cur_r][cur_c] + 1 < d[cur_r-1][cur_c]) {
                d[cur_r-1][cur_c] = d[cur_r][cur_c] + 1;
                p[cur_r-1][cur_c] = 'U';
                oned = (cur_r-1) * C + cur_c;
                q.insert({d[cur_r-1][cur_c], oned});
            }
        }

    }
}

int main() {
    int r; int c; string row; pair<int, int> s; pair<int, int> e;
    cin >> r >> c;
    vector<vector<int>> m(r, vector<int>(c, 0));
    vector<vector<int>> d(r, vector<int>(c, INF));
    vector<vector<char>> p(r, vector<char>(c, '?'));
    for (int i{0}; i<r; i++) {
        cin >> row;
        for (int j{0}; j<c; j++) {
            if (row[j] == 'A') {
                s = {i, j};
                m[i][j] = 1;
                p[i][j] = 'S';
            }
            else if (row[j] == 'B') {
                e = {i, j};
                m[i][j] = 1;
            }
            else if (row[j] == '.') {
                m[i][j] = 1;
            }
        }
    }
    dijkstra(s, d, p, m);
    int fin_r = e.first;
    int fin_c = e.second;
    string fin = "";
    if (d[fin_r][fin_c] < INF) {
        cout << "YES" << "\n";
        cout << d[fin_r][fin_c] << "\n";
        string fin;
        while (p[fin_r][fin_c] != 'S') {
            char c = p[fin_r][fin_c];
            fin += c;

            if (c == 'D') fin_r--;
            else if (c == 'U') fin_r++;
            else if (c == 'L') fin_c++;
            else if (c == 'R') fin_c--;

        }
        reverse(fin.begin(), fin.end());
        cout << fin;
    }
    else {
        cout << "NO";
    }
}