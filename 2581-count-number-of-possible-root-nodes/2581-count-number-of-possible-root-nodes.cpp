class Solution {
public:
vector<int>up;
vector<int>down;
vector<int>dp;
map<pair<int,int>,int>mp;
void dfsdown(int node,int parent, vector<int>&vis, unordered_map<int, vector<int>>&adj) {
    vis[node] = 1;

    for(auto ch : adj[node]) {
        if(!vis[ch]) {
            dfsdown(ch, node, vis, adj);
            down[node] += down[ch] + mp.count({node, ch});
        }
    } 

    // down[node] += mp.count({parent, node});

}
void dfsup(int node, int parent, vector<int>&vis, unordered_map<int, vector<int>>&adj) {
    vis[node] = 1;

    dp[node] = up[node] + down[node];

    for(auto ch : adj[node]) {
            if(!vis[ch]) {
                up[ch] = dp[node]- down[ch] - mp.count({node, ch});
                if(mp.count({ch, node})) {
                    up[ch]++;
                }
                dfsup(ch, node, vis, adj);
            }
        }
}

    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        unordered_map<int, vector<int>>adj;
        for(int i = 0; i < edges.size(); i++ ) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(auto i : guesses) {
            mp[{i[0], i[1]}]++;
        }

        int n = edges.size() + 1;

        up = vector<int>(n, 0);
        down = vector<int>(n, 0);
        dp = vector<int>(n, 0);

        vector<int>vis(n, 0);
        
        dfsdown(0, -1, vis, adj);

        vector<int>vis2(n, 0);
        dfsup(0, -1, vis2, adj);

        int count = 0;

        for(int i = 0; i < n; i++) {
            if(dp[i] >= k) count++;
        }

        return count;

    }
};