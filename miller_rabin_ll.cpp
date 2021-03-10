using u64 = unsigned long long;
using u128 = __uint128_t;

const u64 p[] = {
    2, 3, 5, 7,
    11, 13, 17, 19,
    23, 29,
    31, 37
};

u64 mod_pow(u64 b, u64 e, u64 m) {
    u64 r = 1;
    for (b %= m; e; e >>= 1, b = u128(b) * b % m) {
        if (e & 1) r = u128(r) * b % m;
    }
    return r;
}

bool miller_rabin(u64 n) {
    if (n < 2) return false;

    int s = 0;
    u64 d = n - 1;
    for (; ~d & 1; s++, d >>= 1);

    for (u64 a : p) {
        if (n == a) return true;
        if (n < a) continue;

        if (u64 x = mod_pow(a, d, n); x != 1 && x != n - 1) {
            bool pp = false;
            for (int r = 1; r < s && !pp; r++) {
                x = u128(x) * x % n;
                if (x == n - 1) pp = true;
            }

            if (!pp) return false;
        }
    }

    return true;
}
