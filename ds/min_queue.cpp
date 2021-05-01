struct min_queue {
    const int e = 1 << 30;
    vector<pair<int, int>> f{{e, e}}, b{{e, e}};

    int Min() {
        return min(f.back().second, b.back().second);
    }

    void push(int x) {
        b.emplace_back(x, min(x, b.back().second));
    }

    void pop() {
        if (f.size() == 1) {
            while (b.size() > 1) {
                int x = b.back().first;
                b.pop_back();
                f.emplace_back(x, min(x, f.back().second));
            }
        }

        b.pop_back();
    }
};
