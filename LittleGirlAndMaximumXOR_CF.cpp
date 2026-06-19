#include <bit>
#include <cstdint>
#include <iostream>

using namespace std;

int main() {
    uint64_t a, b; long long total;
    int msb_b, msb_a;
    cin >> a >> b;
    msb_b = (b == 0 ? -1 : 63 - countl_zero(b));
    msb_a = (a == 0 ? -1 : 63 - countl_zero(a));

    while (msb_a == msb_b && msb_a != -1) {
        a = a & ~(1ULL << msb_a);
        b = b & ~(1ULL << msb_b);

        if (b == 0) msb_b = -1;
        else msb_b = 63 - countl_zero(b);
        if (a == 0) msb_a = -1;
        else msb_a = 63 - countl_zero(a);
    }

    if (msb_b == -1) cout << 0;
    else cout << (1ULL << (1 + msb_b)) - 1;

}