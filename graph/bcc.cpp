// u -> (v, edge_idx)
// edge_idx is needed for non-simple undirected graphs
vector<pair<int, int>> adj[N];

vector<vector<int>> bcc(int n) {
    vector<int> tin(n), low(n);
    int t = 0;

    vector<vector<int>> ans;
    stack<int> st;
    
    auto dfs = [&](int u, int e, auto &&f) -> void {
        tin[u] = low[u] = ++t;
        st.push(u);

        for (auto [v, i] : adj[u]) if (i != e) {
            if (!tin[v]) f(v, i, f);

            low[u] = min(low[v], low[u]);
        }

        if (tin[u] == low[u]) {
            ans.emplace_back();

            int v;
            do {
                ans.back().push_back(v = st.top());
                st.pop();
            } while (v != u);
        }
    };

    for (int u = 0; u < n; u++) if (!tin[u]) {
        dfs(u, -1, dfs);
    }

    return ans;
}
