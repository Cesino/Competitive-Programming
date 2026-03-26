#include <set>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    set<int> songs; int n; int song; vector<int> playlist;
    cin >> n;
    int count_max = 0;
    int l = 0;

    for (int i{0}; i < n; i++) {
        cin >> song;
        playlist.push_back(song);
    }

    for (int r{0}; r < n; r++){
        if (songs.count(playlist[r]) == 0) {
            songs.insert(playlist[r]);
        }

        else {
            while (songs.count(playlist[r]) > 0) {
                songs.erase(playlist[l]);
                l++;
            }
            songs.insert(playlist[r]);
        }

        if (songs.size() > count_max) {
            count_max = songs.size();
        }

    }

    cout << count_max;
}