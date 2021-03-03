vt<int> suffix_array(string &s) {
    s += '\0';
    int n = sz(s);

    vt<int> p(n), c(n);
    auto csort = [&]() {
        vt<int> f(max(256, n)), np(n);
        for (int i = 0; i < n; i++) f[c[i]]++;
        for (int i = 0, ps = 0; i < sz(f); i++) {
            ps += f[i];
            f[i] = ps - f[i];
        }
        for (int i = 0; i < n; i++) {
            np[f[c[p[i]]]++] = p[i];
        }
        swap(p, np);
    };

    iota(all(p), 0);
    for (int i = 0; i < n; i++) c[i] = s[i];
    csort();

    for (int k = 0; (1 << k) < n; k++) {
        for (int i = 0; i < n; i++) {
            p[i] -= 1 << k;
            if (p[i] < 0) p[i] += n;
        }

        csort();

        vt<int> nc(n);
        for (int i = 1; i < n; i++) {
            pii x = {c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n]},
                y = {c[p[i]], c[(p[i] + (1 << k)) % n]};
            nc[p[i]] = nc[p[i - 1]] + (x != y);
        }
        swap(c, nc);
    }

    return p;
}
