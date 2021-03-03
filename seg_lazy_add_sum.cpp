struct seg {
    int n;
    vt<ll> a, len;
    vt<ll> lz;

#define lc(i) (i) << 1
#define rc(i) (i) << 1 | 1

    seg(int k) : n(k), a(n << 1), len(n << 1), lz(n) {
        for (int i = 0; i < n; i++) {
            len[i + n] = 1;
        }
        build(0, n);
    }

    seg(vt<int> &b) : n(sz(b)), a(n << 1), lz(n) {
        copy(all(b), a.begin() + n);
        for (int i = 0; i < n; i++) {
            len[i + n] = 1;
        }
        build(0, n);
    }

    void apply(int i, ll d) {
        a[i] += d * len[i];
        if (i < n) lz[i] += d;
    }

    void build(int l, int r) {
        for (l += n, r += n - 1; l >>= 1, r >>= 1;) {
            for (int i = l; i <= r; i++) {
                len[i] = len[lc(i)] + len[rc(i)];
                a[i] = a[lc(i)] + a[rc(i)] + lz[i] * len[i];
            }
        }
    }

    void build(int i) { return build(i, i + 1); }

    void push(int i) {
        i += n;
        for (int s = __lg(i); s; s--) {
            int p = i >> s;
            apply(lc(p), lz[p]);
            apply(rc(p), lz[p]);
            lz[p] = 0;
        }
    }

    ll query(int l, int r) {
        push(l), push(r - 1);

        ll ret = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ret += a[l++];
            if (r & 1) ret += a[--r];
        }

        return ret;
    }

    void update(int l, int r, ll d) {
        int l0 = l, r0 = r;

        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) apply(l++, d);
            if (r & 1) apply(--r, d);
        }

        build(l0);
        build(r0 - 1);
    }
};
