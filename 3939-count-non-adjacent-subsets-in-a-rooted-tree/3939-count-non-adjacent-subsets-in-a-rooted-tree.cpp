class Solution {
public:
    long long dp[1001][101][2];
    const int mod = 1e9 +7;
    void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& v, int k) {
        dp[node][v[node] % k][1] = 1; 
        dp[node][0][0] = 1;         

        for (auto ch : adj[node]) {
            if (ch == parent) continue;

            dfs(ch, node, adj, v, k);

            vector<long long> take(k, 0);
            vector<long long> nottake(k, 0);

            for (int j = 0; j < k; j++) {
                for (int g = 0; g < k; g++) {
                    int sum = (j + g) % k;
                    take[sum] =(take[sum]+ dp[node][j][1] * dp[ch][g][0]) % mod;
                    nottake[sum]=(nottake[sum]+ dp[node][j][0] * (dp[ch][g][1] + dp[ch][g][0])) % mod;
                }
            }

            for (int j = 0; j < k; j++) {
                dp[node][j][1] = take[j];
                dp[node][j][0] = nottake[j];
            }
        }
    }

    int countValidSubsets(vector<int>& parent, vector<int>& nums, int k) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i < n; i++) {
            nums[i] = nums[i] % k; 
            
            if (parent[i] == -1) continue;
            
            adj[parent[i]].push_back(i);
            adj[i].push_back(parent[i]);
        }

        dfs(0, -1, adj, nums, k);

        return (dp[0][0][1] + dp[0][0][0] - 1 + mod) % mod; 
    }
};