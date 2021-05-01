// References:
// AtCoder Library
// https://codeforces.com/blog/entry/61290

// consider changing ll to i128
pair<ll, ll> crt(const vector<ll> &r, const vector<ll> &m) {
    ll r0 = 0, m0 = 1;
    for (int i = 0; i < int(r.size()); i++) {
        ll m1 = m[i];
        ll r1 = r[i] % m1;
        if (r1 < 0) r1 += m1;

        auto [g, x, _] = egcd(m0, m1);
        if ((r1 - r0) % g) return {0, 0};

        ll u1 = m1 / g;
        r0 += m0 * ((r1 - r0) / g * x % u1);
        m0 *= u1;
        if (r0 < 0) r0 += m0;
    }

    return {r0, m0};
}
