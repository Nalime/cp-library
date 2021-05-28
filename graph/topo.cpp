vector<int> adj[N];

vector<int> topo(int n) {
    vector<int> ans, vis(n);
    bool bad = false;

    auto dfs = [&](int u, auto &&f) -> void {
        vis[u] = 1;

        for (int v : adj[u]) {
            if (!vis[v]) f(v, f);
            else if (vis[v] == 1) bad = true;
        }

        vis[u] = 2;
        ans.push_back(u);
    };

    for (int s = 0; s < n; s++) if (!vis[s]) {
        dfs(s, dfs);
    }

    if (bad) return {};

    reverse(ans.begin(), ans.end());
    return ans;
}
