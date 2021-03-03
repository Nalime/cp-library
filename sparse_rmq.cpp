struct sparse {
    int n;
    vt<vt<int>> a;

    sparse(vt<int> &b) : n(sz(b)), a(__lg(n) + 1, vt<int>(n)) {
        copy(all(b), a[0].begin());
        for (int i = 0; i < __lg(n); i++) {
            for (int j = 0; j <= n - (2 << i); j++) {
                a[i + 1][j] = min(a[i][j], a[i][j + (1 << i)]);
            }
        }
    }

    // [l, r)
    int query(int l, int r) {
        int i = __lg(r - l);
        return min(a[i][l], a[i][r - (1 << i)]);
    }
};
