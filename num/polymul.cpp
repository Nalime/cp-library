// Written for integers
template <class T>
vector<T> polymul(vector<T> &a, vector<T> &b) {
    vector<complex<double>> s(a.begin(), a.end());
    vector<complex<double>> t(b.begin(), b.end());

    int n = 1 << __lg(2 * (s.size() + t.size()) + 1);
    s.resize(n);
    t.resize(n);

    fft(s);
    fft(t);

    for (int i = 0; i < n; i++) {
        s[i] *= t[i];
    }

    fft(s, true);

    n = s.rend() - find_if(s.rbegin(), s.rend(), [](auto x) {
        return abs(x.real()) > 0.5;
    });

    vector<T> c(n);
    for (int i = 0; i < n; i++) {
        c[i] = llround(s[i].real());
    }

    return c;
}
