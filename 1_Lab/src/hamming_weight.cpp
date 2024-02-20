#include <iostream>

int hamming_weight(int x) {
    int res = x & 1;
    while (x >>= 1) {
        res += (x & 1);
    }
    return res;
}

int hw_sum(int a, int b) {
    int res = 0;
    for (int i = a; i <= b; ++i) {
        res += hamming_weight(i);
    }
    return res;
}
