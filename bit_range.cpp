// Everything is 1-indexed internally and 0-indexed externally
struct range_bit {
    int n;
    // Needs normal bit
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
