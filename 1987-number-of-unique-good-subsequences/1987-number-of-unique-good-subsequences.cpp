class Solution {
public:
    int numberOfUniqueGoodSubsequences(string b) {
        int n = b.size();
        vector<vector<long long>>dp(n, vector<long long>(2, 0));
        const int mod = 1e9 + 7;
        dp[0][0] = 0;
        dp[0][1] = b[0] == '1';
        int z = b[0] == '0';
        bool flag = (b[0] == '1') ? false : true;
        for(int i = 1; i < n; i++) {
            if(b[i] == '1') {
                dp[i][0] = dp[i-1][0];
                dp[i][1] = ((dp[i - 1][1]+dp[i-1][0]) % mod + 1) % mod; 
                flag = false;
            }
            else {
                z++;
                if(flag) continue;

                dp[i][1] = dp[i - 1][1];
                dp[i][0] = (dp[i - 1][1] + dp[i - 1][0]) % mod;
            }
        }

        // for(int i = 0; i < n; i++) cout<<dp[i][0]<<" ";
        // cout<<"\n";
        // for(int i = 0; i < n; i++) cout<<dp[i][1]<<" ";

        
        return (dp[n-1][0] + dp[n-1][1]) % mod + (z > 0);
    }
};