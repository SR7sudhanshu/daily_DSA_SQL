class Solution {
public:
    vector<long long> sub;
    string colors;
    vector<vector<vector<long long>>>dp;
    long long dfs(int node, int parent,unordered_map<int, vector<int>>& adj) {
        long long count = 0;

        for (auto ch : adj[node]) {
            if (ch == parent) continue;
            count += dfs(ch, node, adj);
        }

        sub[node] = count + 1;
        return sub[node];
    }

    void dpdfs(int node, int parent,unordered_map<int, vector<int>>& adj) {

        for (auto ch : adj[node]) {
            if (ch == parent) continue;
            dpdfs(ch, node, adj);
        }

        //dp[node][0][0]
        long long currentcost = (colors[node] == 'R' ? 0 : sub[node]);
        long long total = 0;

        for (auto ch : adj[node]) {
            if (ch == parent) continue;

            total += min(dp[ch][1][0], dp[ch][0][0]);
        }

        dp[node][0][0] = total + currentcost;

        total = 0;
        long long total1 = LLONG_MAX / 2;

        for (auto ch : adj[node]) {
            if (ch == parent) continue;

            total += dp[ch][1][0];
        }

        for (auto ch : adj[node]) {
            if (ch == parent) continue;

            long long keepRed = min(dp[ch][0][0], dp[ch][1][1]);

            total1 = min(total1, total - dp[ch][1][0] + keepRed);
        }

        currentcost = (colors[node] == 'B' ? 0 : sub[node]);

        dp[node][1][0] = total + currentcost;
        dp[node][1][1] = total1 + currentcost;
    }

    long long minCost(int n, string colors, vector<vector<int>>& edges) {
        this->colors = colors;
        sub.assign(n, 0);
        unordered_map<int, vector<int>> adj;
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0, -1, adj);
        const long long INF = LLONG_MAX / 2;
        dp = vector<vector<vector<long long>>> (
            n, vector<vector<long long>>(2, vector<long long>(2, INF))
        );
        dpdfs(0, -1, adj);
        return min(dp[0][0][0], min(dp[0][1][0], dp[0][1][1]));
    }
};