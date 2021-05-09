template <class T, class F = long double>
struct point {
    T x, y;

    point() : x(0), y(0) {}
    point(T s, T t) : x(s), y(t) {}

    explicit operator pair<T, T>() const { return {x, y}; }

    point operator+() const { return *this; }
    point operator-() const { return point(-x, -y); }

    // be careful of overflow
    T norm() { return x * x + y * y; }
    F abs() { return sqrtl(norm()); }

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

    // dot product
    friend T operator^(const point &s, const point &t) {
        return s.x * t.x + s.y * t.y;
    }

    // cross product
    friend T operator%(const point &s, const point &t) {
        return s.x * t.y - s.y * t.x;
    }

    // pair-like comparision

    friend bool operator==(const point &s, const point &t) {
        return pair<T, T>(s) == pair<T, T>(t);
    }

    friend bool operator!=(const point &s, const point &t) {
        return pair<T, T>(s) != pair<T, T>(t);
    }

    friend bool operator<(const point &s, const point &t) {
        return pair<T, T>(s) < pair<T, T>(t);
    }

    friend bool operator>(const point &s, const point &t) {
        return pair<T, T>(s) > pair<T, T>(t);
    }

    friend bool operator<=(const point &s, const point &t) {
        return pair<T, T>(s) <= pair<T, T>(t);
    }

    friend bool operator>=(const point &s, const point &t) {
        return pair<T, T>(s) >= pair<T, T>(t);
    }

    // streams

    friend istream& operator>>(istream &is, point &t) {
        T p, q;
        is >> p >> q;
        t = {p, q};
        return is;
    }

    friend ostream& operator<<(ostream &os, const point &t) {
        return os << '(' << t.x << ", " << t.y << ')';
    }
};
using pt = point<long long>;
