struct seg {
    struct node {
        ll inv, one, len;
        node() : inv(0), one(0), len(0) {}
    };

#define lc(i) (i) << 1
#define rc(i) (i) << 1 | 1

    int n;
    vt<node> a;
    vt<int> lz;

    seg(vt<int> &b) : n(sz(b)), a(n << 1), lz(n) {
        for (int i = 0; i < n; i++) {
            a[i + n].one = b[i];
            a[i + n].len = 1;
        }
        build(0, n);
    }

    void apply(int i, bool prop = true) {
        a[i].inv = a[i].one * (a[i].len - a[i].one) - a[i].inv;
        a[i].one = a[i].len - a[i].one;
        if (i < n && prop) lz[i] ^= 1;
    }

    node merge(node &x, node &y) {
        node r;
        r.inv = x.inv + y.inv + x.one * (y.len - y.one);
        r.one = x.one + y.one;
        r.len = x.len + y.len;
        return r;
    }

    void build(int l, int r) {
        for (l += n, r += n - 1; l >>= 1, r >>= 1;) {
            for (int i = r; i >= l; i--) {
                a[i] = merge(a[lc(i)], a[rc(i)]);
                if (lz[i]) apply(i, false);
            }
        }
    }

    void build(int i) { build(i, i + 1); }

    void push(int l, int r) {
        l += n, r += n - 1;
        for (int s = __lg(r); s; s--) {
            for (int i = l >> s; i <= r >> s; i++) {
                if (lz[i]) {
                    apply(lc(i));
                    apply(rc(i));
                    lz[i] = 0;
                }
            }
        }
    }

    void push(int i) { push(i, i + 1); }

    ll query(int l, int r) {
        push(l), push(r - 1);

        node x, y;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) x = merge(x, a[l++]);
            if (r & 1) y = merge(a[--r], y);
        }

        return merge(x, y).inv;
    }

    void update(int l, int r) {
        int l0 = l, r0 = r;

        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) apply(l++);
            if (r & 1) apply(--r);
        }

        build(l0), build(r0 - 1);
    }
};
