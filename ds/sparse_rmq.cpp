// consts: N (max array size), K (lg_floor(N))
struct sparse {
    int n;
    static int lg[N];
    array<vector<int>, K> a;

    sparse(vector<int> &b) : n(b.size()), lg(n + 1) {
        // precalculate binary logarithms
        if (!lg[2]) {
            for (int i = 2; i < N; i++) {
                lg[i] = lg[i >> 1] + 1;
            }
        }

        a.fill(vector<int>(n));
        a[0] = b;
        for (int k = 0; k < K - 1; k++) {
            for (int i = 0; i + (2 << k) <= n; i++) {
                a[k + 1][i] = min(a[k][i], a[k][i + (1 << k)]);
            }
        }
    }

    // [l, r)
    int query(int l, int r) {
        // int k = __lg(r - l);
        int k = lg[r - l];
        return min(a[k][l], a[k][r - (1 << k)]);
    }
};
