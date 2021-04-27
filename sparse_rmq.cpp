// K should be a const somewhat bigger than lg N
struct sparse {
    int n;
    array<vector<int>, K> a;
    vector<int> lg;

    sparse(vector<int> &b) : n(b.size()), lg(n + 1) {
        a.fill(vector<int>(n));
        a[0] = b;
        for (int k = 0; k < K - 1; k++) {
            for (int i = 0; i <= n - (2 << k); i++) {
                a[k + 1][i] = min(a[k][i], a[k][i + (1 << k)]);
            }
        }

        // precalculate logarithms, optional
        for (int i = 2; i <= n; i++) {
            lg[i] = lg[i >> 1] + 1;
        }
    }

    // [l, r)
    int query(int l, int r) {
        // int k = __lg(r - l);
        int k = lg[r - l];
        return min(a[k][l], a[k][r - (1 << k)]);
    }
};
