struct minq {
    const int e = 1 << 30;
    vt<pii> f{{e, e}}, b{{e, e}};

    void push(int x) {
        f.emplace_back(x, min(x, f.back().se));
    }

    void pop() {
        if (sz(b) == 1) {
            while (sz(f) > 1) {
                int x = f.back().fi;
                f.pop_back();
                b.emplace_back(x, min(x, b.back().se));
            }
        }

        b.pop_back();
    }

    int Min() {
        return min(b.back().se, f.back().se);
    }
};
