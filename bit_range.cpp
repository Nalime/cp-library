// Everything is 1-indexed internally and 0-indexed externally

struct bit {
    int n;
    vector<ll> a;

    bit(int k) : n(k + 1), a(n) {}

    bit(vector<int> &b) : n(b.size() + 1), a(n) {
        for (int i = 1; i < n; i++) {
            a[i] += b[i - 1];
            if (int t = i + (i & -i); t < n) {
                a[t] += a[i];
            }
        }
    }

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

struct range_bit {
    int n;
    bit a, b;

    range_bit(int k) : a(k), b(k) {}

    range_bit(vector<int> &c) : n(c.size()), a(n), b(n) {
        for (int i = 0; i < n; i++) update(i, i + 1, c[i]);
    }

    // [l, r)
    ll query(int l, int r) {
        return a.query0(r - 1) * r - a.query0(l - 1) * l + b.query(l, r);
    }

    // [l, r)
    void update(int l, int r, ll d) {
        a.update(l, d);
        a.update(r, -d);
        b.update(l, -l * d);
        b.update(r, r * d);
    }
};
