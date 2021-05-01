vt<int> prefix_fun(string s) {
    int n = sz(s);
    vt<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j && s[j] != s[i]) j = pi[j - 1];
        if (s[j] == s[i]) j++;
        pi[i] = j;
    }
    return pi;
}

vt<int> kmp(string str, string pat) {
    vt<int> pi(prefix_fun(pat + '\0' + str)), match;
    for (int i = 1; i < sz(pi); i++) {
        if (pi[i] == sz(pat))
            match.push_back(i - sz(pat) * 2);
    }
    return match;
}
