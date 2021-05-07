vector<int> z_algo(const string &s) {
    int n = s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 1; i < n; i++) {
        int &j = z[i];
        if (i < r) j = min(z[i - l], r - i);
        while (i + j < n && s[j] == s[i + j]) j++;
        if (i + j > r) l = i, r = i + j;
    }
    return z;
}
