ll inv[N], fact[N], finv[N];

void comb_init() {
    inv[1] = fact[0] = finv[0] = 1;
    for (int i = 2; i < N; i++) {
        inv[i] = mod - mod / i * inv[mod % i] % mod;
    }
    for (int i = 1; i < N; i++) {
        fact[i] = fact[i - 1] * i % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
}

ll P(int n, int r) {
    return 0 <= r && r <= n ? fact[n] * finv[n - r] % mod : 0;
}

ll C(int n, int r) {
    return 0 <= r && r <= n ? P(n, r) * finv[r] % mod : 0;
}

ll H(int n, int r) {
    return C(n + r - 1, r);
}
