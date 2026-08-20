class Solution {
public:
    int countStableSubsequences(vector<int>& nums) {
        vector<vector<int>>dp(2, vector<int>(2, 0));
        
        if(nums[0] & 1) {
            dp[0][1] = 1;
        }
        else {
            dp[1][0] = 1;
        }
        
        const int mod = 1e9 + 7;

        for(int i = 1; i < nums.size(); i++) {
            vector<vector<int>>dpnew = dp;
            if(nums[i] & 1) { 
                dpnew[0][1] = (dpnew[0][1] + (dp[0][0] + dp[1][0]) % mod + 1) % mod;
                dpnew[1][1] = (dpnew[1][1] + dp[0][1]) % mod;
            }
            else { 
                dpnew[1][0] = (dpnew[1][0] + (dp[0][1] + dp[1][1]) % mod + 1) % mod;
                
                dpnew[0][0] = (dpnew[0][0] + dp[1][0]) % mod; 
            }
            dp = dpnew;
        }
        
        long long ans = 0; 
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                ans = (ans + dp[i][j]) % mod;
            }
        }    
        
        return ans;
    }
};