array<ll, 3> egcd(ll a, ll b) {
    ll s0 = 1, t0 = 0, s1 = 0, t1 = 1;
    while (b) {
        ll d = a / b;
        tie(a, b) = make_pair(b, a % b);
        tie(s0, s1) = make_pair(s1, s0 - d * s1);
        tie(t0, t1) = make_pair(t1, t0 - d * t1);
    }
    return {a, s0, t0};
}
