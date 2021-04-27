// TODO binary search on segment tree, array initialization
struct lazy_seg {
    int n;
    vector<ll> a, lz;
    vector<int> len;

    lazy_seg(int k) : n(k), a(n << 1), lz(n, -1), len(n << 1, 1) {
        for (int i = n - 1; i > 0; i--) {
            len[i] = len[lc(i)] + len[rc(i)];
        }
    }

    inline int lc(int i) { return i << 1; }
    inline int rc(int i) { return i << 1 | 1; }

    void apply(int i, ll x) {
        a[i] = x * len[i];
        if (i < n) lz[i] = x;
    }

    void up(int i) {
        while (i >>= 1) {
            // Invariant: each segment is "newer" than its children
            if (lz[i] == -1) a[i] = a[lc(i)] + a[rc(i)];
        }
    }

    void down(int i) {
        for (int s = __lg(i); s > 0; s--) {
            int p = i >> s;
            if (lz[p] != -1) {
                apply(lc(p), lz[p]);
                apply(rc(p), lz[p]);
                lz[p] = -1;
            }
        }
    }

    // [l, r)
    ll query(int l, int r) {
        l += n, r += n;
        down(l), down(r - 1);

        ll ans = 0;
        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ans += a[l++];
            if (r & 1) ans += a[--r];
        }

        return ans;
    }

    // [l, r)
    void update(int l, int r, ll x) {
        int l0 = l += n, r0 = r += n;
        down(l), down(r - 1);

        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) apply(l++, x);
            if (r & 1) apply(--r, x);
        }

        up(l0), up(r0 - 1);
    }
};
