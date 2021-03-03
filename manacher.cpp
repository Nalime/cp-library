// Returns a vector of length of longest palindromes
// with its center at i' = (i - 1) / 2
// (i + 1/2 means between i and i + 1)
// Use this formula to find the bounds: (closed interval)
// l = (i - d[i] + 1) / 2, r = (i + d[i]) / 2
vt<int> manacher(string s) {
    string t{'\0'};
    for (char c : s) {
        t += c;
        t += '\0';
    }
    int n = sz(t);
    vt<int> d(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = i > r ? 1 : min(d[l + r - i], r - i + 1);
        while (i - k >= 0 && i + k < n && t[i - k] == t[i + k]) k++;
        d[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
    return d;
}
