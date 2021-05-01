// Reference: CKHS CP PDFs

vector<int> adj[N];

// returns in topological order
vector<vector<int>> scc(int n) {
    int t = 0;
    vector<int> tin(n), low(n);
    vector<bool> in_scc(n);

    stack<int> st;
    vector<vector<int>> ans;

    auto dfs = [&](int u, auto &&f) -> void {
        tin[u] = low[u] = ++t;
        st.push(u);

        for (int v : adj[u]) if (!in_scc[v]) {
            if (!tin[v]) f(v, f);

            low[u] = min(low[v], low[u]);
        }

        if (low[u] == tin[u]) {
            ans.emplace_back();

            int v;
            do {
                v = st.top();
                st.pop();

                in_scc[v] = true;
                ans.back().push_back(v);
            } while (v != u);
        }
    };

    for (int u = 0; u < n; u++) if (!tin[u]) {
        dfs(u, dfs);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}
