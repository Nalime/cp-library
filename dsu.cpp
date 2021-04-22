struct dsu {
    vector<int> p;

    dsu(int n) : p(n + 1, -1) {}

    bool same(int u, int v) { return root(u) == root(v); }

    int root(int u) { return p[u] < 0 ? u : p[u] = root(p[u]); }

    void merge(int u, int v) {
        if ((u = root(u)) == (v = root(v))) return;
        if (p[u] > p[v]) swap(u, v);

        p[u] += p[v];
        p[v] = u;
    }
};
