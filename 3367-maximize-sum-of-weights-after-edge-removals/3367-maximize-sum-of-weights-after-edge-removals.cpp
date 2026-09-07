class Solution {
public:
int k;
    void dfs(int node, int parent, vector<vector<vector<int>>>&adj, vector<vector<long long>>&dp) {
        
        long long total = 0;
        
        priority_queue<long long>d;

        for(auto ch : adj[node]) {
            auto nxt = ch[0];
            if(nxt == parent) continue;
            int w = ch[1];

            dfs(nxt, node, adj, dp);
            total += dp[nxt][0];

            // dp[chidl][1] - dp[child][[0] diff  storing 
            d.push(w + dp[nxt][1] - dp[nxt][0]);
        }

        long long childsum = 0;
        long long count = 0;
        while(!d.empty() && count < k - 1) {
            auto t = d.top(); d.pop();
            if(t <= 0) break;

            childsum += t;
            count++; 
        }

        //chilsum best k - 1 nodes including edges from this node
        dp[node][1] = total + childsum;
        
        long long lastbest = 0;

        //dont include currents parent edge 
        if(!d.empty()) lastbest = max((long long)0, d.top());
        dp[node][0] = total + childsum + lastbest;
    }

    long long maximizeSumOfWeights(vector<vector<int>>& edges, int k) {
        //dp[i][0] = max sum of subtree without parent edge
        //dp[i][1] = max sum of subtree with parent edges

        int n = edges.size()   + 1;
        this->k = k;
        vector<vector<long long>>dp(n, vector<long long>(2, 0));

        vector<vector<vector<int>>>adj(n);
        for(int i = 0; i < n - 1; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        dfs(0, -1, adj, dp);

        return max(dp[0][0], dp[0][1]);
    }
};