array<ll, 3> egcd(ll a, ll b) {
    ll as = 1, at = 0, bs = 0, bt = 1;
    while (b) {
        ll d = a / b;
        tie(a, b) = make_pair(b, a - d * b);
        tie(as, bs) = make_pair(bs, as - d * bs);
        tie(at, bt) = make_pair(bt, at - d * bt);
    }
    return {a, as, at};
}
