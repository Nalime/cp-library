struct seg {
    const int E = 0;
    int n, N;
    vt<int> a;

#define lc(i) (i) << 1
#define rc(i) (i) << 1 | 1

    seg(int k) : n(k), N(1 << __lg(n * 2 - 1)), a(N << 1, E) {}

    seg(vt<int> &b) : n(sz(b)), N(1 << __lg(n * 2 - 1)), a(N << 1, E) {
        copy(all(b), a.begin() + N);
        for (int i = N - 1; i; i--) {
            a[i] = max(a[lc(i)], a[rc(i)]);
        }
    }

    int query(int l, int r) {
        int ret = E;
        for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ret = max(ret, a[l++]);
            if (r & 1) ret = max(ret, a[--r]);
        }

        return ret;
    }

    void update(int i, int v) {
        for (a[i += N] = v; i >>= 1;) {
            a[i] = max(a[lc(i)], a[rc(i)]);
        }
    }

    int bin_search(int i, int k) {
        i += N;
        do {
            while (~i & 1) i >>= 1;

            if (k <= a[i]) {
                while (i < N) {
                    if (k <= a[lc(i)]) i = lc(i);
                    else i = rc(i);
                }

                return i - N;
            }

            i++;
        } while (i & (i - 1));

        return n;
    }
};
