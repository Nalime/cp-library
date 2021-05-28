template <class D = double>
void fft(vector<complex<D>> &a, bool inv = false) {
    const D pi = acos(-1);

    int n = a.size();
    if (n == 1) return;

    vector<complex<D>> a_e(n / 2), a_o(n / 2);
    for (int i = 0; i < n / 2; i++) {
        a_e[i] = a[i * 2];
        a_o[i] = a[i * 2 + 1];
    }

    fft(a_e, inv);
    fft(a_o, inv);

    complex<D> wn = polar(1.0, (inv ? -2 : 2) * pi / n);
    complex<D> w = 1;
    for (int i = 0; i < n / 2; i++) {
        a[i] = a_e[i] + w * a_o[i];
        a[i + n / 2] = a_e[i] - w * a_o[i];
        if (inv) {
            a[i] /= 2;
            a[i + n / 2] /= 2;
        }
        w *= wn;
    }
}
