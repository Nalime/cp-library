int egcd(int a, int b, int& s, int& t) {
    if (!b) return s = 1, t = 0, a;
    int s1, t1, g = egcd(b, a % b, s1, t1);
    return s = t1, t = s1 - a / b * t1, g;
}
