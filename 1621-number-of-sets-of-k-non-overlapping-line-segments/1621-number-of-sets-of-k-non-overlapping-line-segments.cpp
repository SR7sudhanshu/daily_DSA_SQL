class Solution {
public:
    int numberOfSets(int n, int k) {
        vector<vector<long long>>dp(n, vector<long long>(k + 1, 0));
        vector<vector<long long>>pre(n, vector<long long>(k +1, 0));

        dp[1][1] = 1;
        pre[1][1] = 1;
        const int mod = 1e9 + 7;
        for(int i = 1; i <n; i++) dp[i][1] = dp[i-1][1] + i;

        for(int i = 1; i < n; i++) pre[i][1] = (pre[i - 1][1] + dp[i][1]) % mod;
        // for(int i = 0; i < n; i++) cout<<dp[i][1]<<endl;
        // for(int i = 0; i < n; i++) cout<<pre[i][j]<<endl

        for(int i = 2; i < n; i++) {
            for(int j = 2; j <= k; j++) {
                //dont make line
                dp[i][j] = dp[i - 1][j];
                //make line of len .. 1. ... i
                dp[i][j] = (dp[i][j] + pre[i - 1][j - 1]) % mod;

                //update prefix array 
                pre[i][j] = (pre[i - 1][j] + dp[i][j]) % mod;
            }
        }

        return dp[n-1][k];
    }
};