// Everything is 1-indexed internally and 0-indexed externally
// Needs point add / range sum BIT
struct range_bit {
    int n;
    bit a, b;

    range_bit(int k) : a(k), b(k) {}

    range_bit(vector<int> &c) : n(c.size()), a(n), b(n) {
        for (int i = 0; i < n; i++) update(i, i + 1, c[i]);
    }

    ll query0(int i) {
        return a.query0(i) * i + b.query0(i);
    }

    // [l, r)
    ll query(int l, int r) {
        return query0(r - 1) - query0(l - 1);
    }

    // [l, r)
    void update(int l, int r, ll d) {
        a.update(l, d);
        a.update(r, -d);
        b.update(l, d * (1 - l));
        b.update(r, d * (r - 1));
    }
};
