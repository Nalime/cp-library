// Everything is 1-indexed internally and 0-indexed externally
struct bit {
    int n;
    vector<ll> a;

    bit(int k) : n(k + 1), a(n) {}

    bit(vector<int> &b) : n(b.size() + 1), a(n) {
        for (int i = 0; i < n - 1; i++) update(i, i + 1, b[i]);
    }

    ll query(int i) {
        ll r = 0;
        for (i++; i < n; i += i & -i) r += a[i];
        return r;
    }

    void update0(int i, ll d) {
        for (i++; i; i -= i & -i) a[i] += d;
    }

    // [l, r)
    void update(int l, int r, ll d) {
        update0(l - 1, -d), update0(r - 1, d);
    }
};
