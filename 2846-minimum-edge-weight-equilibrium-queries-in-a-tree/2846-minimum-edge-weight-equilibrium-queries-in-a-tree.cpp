class Solution {
public:
    void dfs(int u, int p, int d, vector<vector<pair<int, int>>>& adj,
             vector<vector<int>>& count, vector<vector<int>>& up, vector<int>& depth) {
        depth[u] = d;
        up[u][0] = (p == -1) ? u : p;

        for (int i = 1; i < 20; i++) {
            up[u][i] = up[up[u][i - 1]][i - 1];
        }

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            if (v != p) {
                count[v] = count[u]; 
                count[v][w]++;       
                dfs(v, u, d + 1, adj, count, up, depth);
            }
        }
    }

    int get_lca(int u, int v, const vector<vector<int>>& up, const vector<int>& depth) {
        if (depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];

        for (int i = 0; i < 20; i++) {
            if ((diff >> i) & 1) {
                u = up[u][i];
            }
        }

        if (u == v) return u;

        for (int i = 19; i >= 0; i--) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }

    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }

        vector<vector<int>> count(n, vector<int>(27, 0));
        vector<vector<int>> up(n, vector<int>(20, 0));
        vector<int> depth(n, 0);

        dfs(0, -1, 0, adj, count, up, depth);

        vector<int> ans;
        for (auto& q : queries) {
            int u = q[0];
            int v = q[1];
            int lca_node = get_lca(u, v, up, depth);

            int max_freq = 0;
            int total_edges = depth[u] + depth[v] - 2 * depth[lca_node];

            for (int w = 1; w <= 26; w++) {
                int freq = count[u][w] + count[v][w] - 2 * count[lca_node][w];
                max_freq = max(max_freq, freq);
            }
            ans.push_back(total_edges - max_freq);
        }

        return ans;
    }
};