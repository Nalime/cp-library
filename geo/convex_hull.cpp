vector<pt> convex_hull(vector<pt> a) {
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    if (a.size() < 2) return a;

    vector<pt> hull;

    auto check = [&](int i) {
        int m = hull.size();
        return (hull[m - 1] - hull[m - 2]) % (a[i] - hull[m - 1]);
    };

    int n = a.size();
    for (int i = 0; i < n; i++) {
        while (hull.size() > 1 && check(i) <= 0) hull.pop_back();
        hull.push_back(a[i]);
    }
    for (int i = n - 2, k = hull.size(); i >= 0; i--) {
        while (int(hull.size()) > k && check(i) <= 0) hull.pop_back();
        hull.push_back(a[i]);
    }

    hull.pop_back();
    return hull;
}
