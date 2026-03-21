#include <vector>
#include <iostream>
#include <cmath>
#include <numeric>
#include <string>
using namespace std;

struct UF {
    vector<int> ar, sz;
    int size;
    int maximum;

    UF(int const N): ar(N), sz(N, 1), size(N){;
        iota(ar.begin(), ar.end(), 0);
    }


    void unon(int a, int b){
        int par_a = find(a); int par_b = find(b);
        if (par_a != par_b) {
            if (sz[par_a] < sz[par_b]) {swap(par_a, par_b);};
            ar[par_b] = par_a;
            sz[par_a] += sz[par_b];
            size--;
        }
    }

    int find(int a) {
        while (ar[a] != a) {
            ar[a] = ar[ar[a]];
            a = ar[a];
        }
        return a;
    }

    bool c_add_edge(const int a, const int b) {
        unon(a, b);
        if (size == 1) {
            return true;
        }
        return false;
    }

};

int main() {
    int N; int M;
    int n1; int n2;
    cin >> N >> M;
    UF u = UF(N);
    bool connected = false;
    if (u.size == 1) {
        connected = true;
        cout << 0;
    }
    for (int i{0}; i<M; i++) {
        cin >> n1 >> n2;
        --n1; --n2;
        if (!connected && u.c_add_edge(n1, n2)) {
            cout << i+1;
            connected = true;
        }
    }
    if (!connected) {
        cout << -1;
    }
}
