class Solution {
public:
    vector<vector<int>> adj, up;
    vector<int> tin, tout, depth, pref, bit;
    string s;
    int timer, LOG, n;

    void dfs(int u, int p, int d) {
        tin[u] = timer++;
        depth[u] = d;
        up[u][0] = p;

        pref[u] = (p == -1 ? 0 : pref[p]) ^ (1 << (s[u] - 'a'));

        for (int v : adj[u]) {
            if (v == p) continue;
            dfs(v, u, d + 1);
        }

        tout[u] = timer;
    }

    void add(int i, int val) {
        for (++i; i <= n; i += i & -i)
            bit[i] ^= val;
    }

    void updateRange(int l, int r, int val) {
        add(l, val);
        if (r < n) add(r, val);
    }

    int getPrefix(int i) {
        int res = 0;
        for (++i; i > 0; i -= i & -i)
            res ^= bit[i];
        return res;
    }

    int getMask(int u) {
        return pref[u] ^ getPrefix(tin[u]);
    }

    void buildLCA() {
        for (int j = 1; j < LOG; j++) {
            for (int u = 0; u < n; u++) {
                int p = up[u][j - 1];
                up[u][j] = (p == -1 ? -1 : up[p][j - 1]);
            }
        }
    }

    int getLCA(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        int diff = depth[u] - depth[v];

        for (int j = 0; j < LOG; j++) {
            if (diff & (1 << j))
                u = up[u][j];
        }

        if (u == v) return u;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }

        return up[u][0];
    }

    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        this->n = n;
        this->s = s;

        adj.assign(n, {});
        tin.assign(n, 0);
        tout.assign(n, 0);
        depth.assign(n, 0);
        pref.assign(n, 0);
        bit.assign(n + 1, 0);

        LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        up.assign(n, vector<int>(LOG, -1));

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        timer = 0;
        dfs(0, -1, 0);
        buildLCA();

        vector<bool> ans;

        for (string& q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;

            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;

                int oldMask = 1 << (s[u] - 'a');
                int newMask = 1 << (c - 'a');
                int delta = oldMask ^ newMask;

                updateRange(tin[u], tout[u], delta);
                s[u] = c;
            } else {
                int u, v;
                ss >> u >> v;

                int lca = getLCA(u, v);

                int mask = getMask(u) ^ getMask(v)
                         ^ (1 << (s[lca] - 'a'));

                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};