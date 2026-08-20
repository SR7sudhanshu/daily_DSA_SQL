using ll = long long;
class Solution {
    int LOG;
    vector<int> h;
    vector<ll> cost;
    vector<vector<pair<int, int>>> adj;
    vector<vector<int>> up;

    void dfs(int node, int p, int d, ll c) {
        h[node] = d;
        cost[node] = c;
        up[node][0] = p;
        for (int i = 1; i < LOG; i++) {
            if (up[node][i - 1] != -1) {
                up[node][i] = up[up[node][i - 1]][i - 1];
            } else {
                up[node][i] = -1;
            }
        }
        for (auto& edge : adj[node]) {
            int v = edge.first;
            int w = edge.second;
            if (v != p) {
                dfs(v, node, d + 1, c + w);
            }
        }
    }

    int getLCA(int u, int v) {
        if (h[u] < h[v]) swap(u, v);
        for (int i = LOG - 1; i >= 0; --i) {
            if (h[u] - (1 << i) >= h[v]) {
                u = up[u][i];
            }
        }
        if (u == v) return u;
        for (int i = LOG - 1; i >= 0; --i) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }

public:
    vector<int> findMedian(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        LOG = 20;
        adj.assign(n, vector<pair<int, int>>());
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        
        h.assign(n, 0);
        cost.assign(n, 0);
        up.assign(n, vector<int>(LOG, -1));
        
        dfs(0, -1, 0, 0);
        
        vector<int> ans;
        ans.reserve(queries.size());
        
        for (auto& q : queries) {
            int u = q[0], v = q[1];
            if (u == v) {
                ans.push_back(u);
                continue;
            }
            
            int lca = getLCA(u, v);
            ll totaldist = cost[u] + cost[v] - 2LL * cost[lca];
            ll reqdist = (totaldist + 1) / 2;
            
            ll updist = cost[u] - cost[lca];
            
            if (updist >= reqdist) {
                int curr = u;
                for (int i = LOG - 1; i >= 0; --i) {
                    int nxt = up[curr][i];
                    if (nxt != -1 && h[nxt] >= h[lca]) {
                        if (cost[u] - cost[nxt] < reqdist) {
                            curr = nxt;
                        }
                    }
                }
                ans.push_back(up[curr][0]);
            } else {
                ll targetdist = reqdist - cost[u] + cost[lca];
                int curr = v;
                for (int i = LOG - 1; i >= 0; --i) {
                    int nxt = up[curr][i];
                    if (nxt != -1 && h[nxt] >= h[lca]) {
                        if (cost[nxt] - cost[lca] >= targetdist) {
                            curr = nxt;
                        }
                    }
                }
                ans.push_back(curr);
            }
        }
        
        return ans;
    }
};