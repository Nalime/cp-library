pii operator-(pii a, pii b) { return {b.fi - a.fi, b.se - a.se}; }
int operator^(pii a, pii b) { return a.fi * b.se - a.se * b.fi; }

vt<pii> convex_hull(vt<pii> &a) {
    vt<pii> ch;
    sort(all(a));
    a.erase(unique(all(a)), a.end());
    if (sz(a) == 1) return a;
    for (int i = 0; i < sz(a); i++) {
        while (sz(ch) > 1 && ((ch.back() - ch[sz(ch) - 2]) ^
                    (a[i] - ch.back())) <= 0) ch.pop_back();
        ch.push_back(a[i]);
    }
    for (int i = sz(a) - 2, t = sz(ch); i >= 0; i--) {
        while (sz(ch) > t && ((ch.back() - ch[sz(ch) - 2]) ^
                    (a[i] - ch.back())) <= 0) ch.pop_back();
        ch.push_back(a[i]);
    }
    ch.pop_back();
    return ch;
}
