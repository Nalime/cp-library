struct imp_seg {
    const static int E = 1e9;

    struct node {
        int val, seg_l, seg_r;
        node *chi_l, *chi_r;

        node(int x, int l, int r) : val(x), seg_l(l), seg_r(r),
                chi_l(nullptr), chi_r(nullptr) {}

        void extend() {
            int seg_m = (seg_l + seg_r) / 2;
            if (chi_l == nullptr) chi_l = new node(E, seg_l, seg_m);
            if (chi_r == nullptr) chi_r = new node(E, seg_m, seg_r);
        }
    };

    node root;

    imp_seg(int n) : root(E, 0, n) {}

    int query(int l, int r, node *u = nullptr) {
        if (!u) u = &root;
        if (l <= u->seg_l && u->seg_r <= r) return u->val;
        if (r <= u->seg_l || u->seg_r <= l) return E;

        u->extend();
        return min(query(l, r, u->chi_l), query(l, r, u->chi_r));
    }

    void update(int p, int d, node *u = nullptr) {
        if (!u) u = &root;
        if (u->seg_l + 1 == u->seg_r) u->val = d;
        else {
            u->extend();
            if (p < u->chi_l->seg_r) update(p, d, u->chi_l);
            else update(p, d, u->chi_r);

            u->val = min(u->chi_l->val, u->chi_r->val);
        }
    }
};
