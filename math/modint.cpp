#warning not checked
template <class T, T M = 1'000'000'007, class I = long long>
struct modint {
    T x;

    modint() : x() {}

    template <class U>
    modint(U s) {
        x = s % M;
        if (x < 0) x += M;
    }

    explicit operator T() const { return x; }

    modint operator+() const { return *this; }
    modint operator-() const { return modint() - *this; }

    modint inv() const {
        T a = x, b = M, as = 1, bs = 0;
        while (b) {
            T d = a / b;

            T t = a;
            a = b;
            b = t - b * d;

            t = as;
            as = bs;
            bs = t - bs * d;
        }
        assert(a == 1);
        return as;
    }

    modint& operator+=(const modint &o) {
        x += o.x;
        if (x >= M) x -= M;
        return *this;
    }

    friend modint operator+(const modint &s, const modint &t) {
        return modint(s) += t;
    }

    modint& operator-=(const modint &o) {
        x -= o.x;
        if (x < 0) x += M;
        return *this;
    }

    friend modint operator-(const modint &s, const modint &t) {
        return modint(s) -= t;
    }

    modint& operator*=(const modint &o) {
        x = I(x) * o.x % M;
        return *this;
    }

    friend modint operator*(const modint &s, const modint &t) {
        return modint(s) *= t;
    }

    modint& operator/=(const modint &o) {
        return *this = *this * o.inv();
    }

    friend modint operator/(const modint &s, const modint &t) { return modint(s) /= t; }

    modint& operator^=(I e) {
        T b = x;
        for (x = 1; e; e >>= 1, b = I(b) * b % M) {
            if (e & 1) x = I(x) * b % M;
        }
        return *this;
    }

    modint operator^(I e) {
        return modint(*this) ^= e;
    }

    modint& operator++() {
        x++;
        if (x == M) x = 0;
        return *this;
    }

    modint& operator--() {
        if (x == 0) x = M;
        x--;
        return *this;
    }

    modint operator++(int) {
        modint r = *this;
        ++*this;
        return r;
    }

    modint operator--(int) {
        modint r = *this;
        --*this;
        return r;
    }

    friend bool operator==(const modint &s, const modint &t) { return s.x == t.x; }
    friend bool operator!=(const modint &s, const modint &t) { return s.x != t.x; }

    // streams

    friend istream& operator>>(istream &is, modint &t) {
        T p;
        is >> p;
        t = p;
        return is;
    }

    friend ostream& operator<<(ostream &os, const modint &t) {
        return os << t.x;
    }
};
using mint = modint<int>;
