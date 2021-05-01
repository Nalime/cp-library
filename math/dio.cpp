const ll inf = 1ll << 60;

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

    auto [g, x, y] = egcd(abs(a), abs(b));
    if (c % g) return 0;
    a /= g, b /= g, c /= g;

    int sign_a = (a > 0) - (a < 0);
    int sign_b = (b > 0) - (b < 0);
    x *= sign_a * c, y *= sign_b * c;

    auto shift = [&](int s) {
        x += s * b;
        y -= s * a;
    };

    shift((x1 - x) / b);
    if (x < x1) shift(sign_b);
    ll min_x = x;

    shift((x2 - x) / b);
    if (x > x2) shift(-sign_b);
    ll max_x = x;

    shift((y - y1) / a);
    if (y < y1) shift(-sign_a);
    if (sign_a != sign_b) min_x = max(x, min_x);
    else max_x = min(x, max_x);

    shift((y - y2) / a);
    if (y > y2) shift(sign_a);
    if (sign_a == sign_b) min_x = max(x, min_x);
    else max_x = min(x, max_x);

    return max((max_x - min_x) / abs(b) + 1, 0ll);
}
