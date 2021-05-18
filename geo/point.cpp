#warning not checked
template <class T, class I = long long, class F = double>
struct point {
    T x, y;

    point() : x(), y() {}
    point(const T &s, const T &t) : x(s), y(t) {}
    point(const pair<T, T> &s) : x(s.first), y(s.second) {}

    explicit operator pair<T, T>() const { return {x, y}; }
    explicit operator complex<T>() const { return {x, y}; }

    point operator+() const { return *this; }
    point operator-() const { return point(-x, -y); }

    I norm() { return I(x) * x + I(y) * y; }
    F abs() { return sqrtl(norm()); }

    template <class F2>
    F2 unit() {
        auto p = point<F2>(*this);
        return p / abs(p);
    }

    // pi/2 anti-clockwise
    point perp() {
        return point(-y, x);
    }

    point& operator+=(const point &o) {
        x += o.x;
        y += o.y;
        return *this;
    }

    friend point operator+(const point &s, const point &t) {
        return point(s) += t;
    }

    point& operator-=(const point &o) {
        x -= o.x;
        y -= o.y;
        return *this;
    }

    friend point operator-(const point &s, const point &t) {
        return point(s) -= t;
    }

    // scalar product

    point& operator*=(T s) {
        x *= s;
        y *= s;
        return *this;
    }

    friend point operator*(T s, const point &t) {
        return point(t) *= s;
    }

    point operator*(T s) const {
        return point(*this) *= s;
    }

    point& operator/=(T s) {
        x /= s;
        y /= s;
        return *this;
    }

    point operator/(T s) const {
        return point(*this) /= s;
    }

    // dot product
    friend I operator*(const point &s, const point &t) {
        return I(s.x) * t.x + I(s.y) * t.y;
    }

    // cross product
    friend I operator^(const point &s, const point &t) {
        return I(s.x) * t.y - I(s.y) * t.x;
    }

    // pair-like comparision

    friend bool operator==(const point &s, const point &t) {
        return s.x == t.x && s.y == t.y;
    }

    friend bool operator!=(const point &s, const point &t) {
        return s.x != t.x || s.y != t.y;
    }

    friend bool operator<(const point &s, const point &t) {
        return s.x < t.x || (s.x == t.x && s.y < t.y);
    }

    friend bool operator>(const point &s, const point &t) {
        return s.x > t.x || (s.x == t.x && s.y > t.y);
    }

    friend bool operator<=(const point &s, const point &t) {
        return s.x <= t.x || (s.x == t.x && s.y <= t.y);
    }

    friend bool operator>=(const point &s, const point &t) {
        return s.x >= t.x || (s.x == t.x && s.y >= t.y);
    }

    // streams

    friend istream& operator>>(istream &is, point &t) {
        return is >> t.x >> t.y;
    }

    friend ostream& operator<<(ostream &os, const point &t) {
        return os << t.x << ' ' << t.y;
    }
};
using pt = point<int>;
