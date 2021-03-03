struct bit {
    int n;
    vt<ll> a;

    bit(int k) : n(k + 1), a(n) {}

    bit(vt<int> b) : n(sz(b) + 1), a(n) {
        for (int i = 1; i < n; i++) {
            a[i] += b[i - 1];
            if (int t = i + (i & -i); t < n) {
                a[t] += a[i];
            }
        }
    }

    // The functions below are all
    // 1-indexed internally and 0-indexed externally

    ll query0(int i) {
        ll r = 0;
        for (i++; i; i -= i & -i) r += a[i];
        return r;
    }

    // [l, r)
    ll query(int l, int r) {
        return query0(r - 1) - query0(l - 1);
    }

    void update(int i, ll d) {
        for (i++; i < n; i += i & -i) a[i] += d;
    }
};
