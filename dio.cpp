using pll = pair<ll, ll>;

const ll inf = 1ll << 60;

vt<ll> egcd(ll a, ll b) {
    ll s0 = 1, t0 = 0, s1 = 0, t1 = 1;
    while (b) {
        ll d = a / b;
        tie(a, b) = pll(b, a % b);
        tie(s0, s1) = pll(s1, s0 - d * s1);
        tie(t0, t1) = pll(t1, t0 - d * t1);
    }
    return {a, s0, t0};
}

ll dio(ll a, ll b, ll c, ll x1, ll x2, ll y1, ll y2) {
    if (x1 > x2 || y1 > y2) return 0;
    if (!a || !b) {
        ll x = x2 - x1 + 1;
        ll y = y2 - y1 + 1;

        if (!a && !b && c) return 0;
        if (a) x = c % a == 0 && x1 <= c / a && c / a <= x2;
        if (b) y = c % b == 0 && y1 <= c / b && c / b <= y2;

        return x * y;
    }

    vt<ll> eg = egcd(abs(a), abs(b));
    ll g = eg[0], x = eg[1], y = eg[2];
    if (c % g) return 0;

    int sign_a = a > 0 ? 1 : -1;
    int sign_b = b > 0 ? 1 : -1;
    a /= g, b /= g, c /= g;

    x *= c * sign_a, y *= c * sign_b;

    auto shift = [&](ll s) {
        x += b * s;
        y -= a * s;
    };

    ll l = -inf, r = inf;

    shift((x1 - x) / b);
    if (x < x1) shift(sign_b);
    l = max(x, l);

    shift((x2 - x) / b);
    if (x > x2) shift(-sign_b);
    r = min(x, r);

    shift(-(y1 - y) / a);
    if (y < y1) shift(-sign_a);
    if (sign_a != sign_b) l = max(x, l);
    else r = min(x, r);

    shift(-(y2 - y) / a);
    if (y > y2) shift(sign_a);
    if (sign_a != sign_b) r = min(x, r);
    else l = max(x, l);

    return max((r - l) / abs(b) + 1, 0ll);
}
