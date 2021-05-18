vector<int> linear_sieve(int n) {
    vector<int> s(n + 1), p;

    for (int i = 2; i <= n; i++) {
        if (!s[i]) {
            s[i] = i;
            p.push_back(i);
        }

        for (int j : p) {
            if (j > s[i] || i * j > n) break;
            s[i * j] = j;
        }
    }

    return s;
}
