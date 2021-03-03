vt<int> z_algo(string s) {
    int n = sz(s);
    vt<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        int j = 0;
        if (i <= r) j = min(z[i - l], r - i + 1);
        while (i + j < n && s[j] == s[i + j]) j++;
        if (i + j - 1 > r) l = i, r = i + j - 1;
        z[i] = j;
    }
    return z;
}
