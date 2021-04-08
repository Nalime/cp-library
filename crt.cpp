using ll = long long;

array<ll, 3> egcd(ll a, ll b) {
    ll s0 = 1, t0 = 0, s1 = 0, t1 = 1;
    while (b) {
        ll d = a / b;
        tie(a, b) = make_pair(b, a - d * b);
        tie(s0, s1) = make_pair(s1, s0 - d * s1);
        tie(t0, t1) = make_pair(t1, t0 - d * t1);
    }
    return {a, s0, t0};
}

// __int128_t in case of overflow
pair<ll, ll> crt(const vector<ll> &r, const vector<ll> &m) {
    ll r0 = 0, m0 = 1;
    for (int i = 0; i < int(r.size()); i++) {
        ll m1 = m[i];
        ll r1 = r[i] % m1;
        if (r1 < 0) r1 += m1;

        auto [g, x, _] = egcd(m0, m1);
        if ((r1 - r0) % g) return {0, 0};

        ll u1 = m1 / g;
        r0 += m0 * (x * (r1 - r0) / g % u1);
        m0 *= u1;
        if (r0 < 0) r0 += m0;
    }

    return {r0, m0};
}
