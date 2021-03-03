// https://codeforces.com/blog/entry/23365
ll inv(ll a, ll b = mod) {
    return a > 1 ? b - inv(b % a, a) * b / a : 1;
}
