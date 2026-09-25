class Solution {
public:
    vector<int> maximumSubarrayXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<vector<int>>sub(n, vector<int>(n, 0));

        sub[0] = nums;
        int len = n;

        for(int j = 1; j < len; j++) {
            for(int i = 0; i < len - j; i++) {
                int a = sub[j - 1][i] ^ sub[j - 1][i + 1];
                sub[j][i] = a;
            }
        }

        vector<vector<int>>dp(n, vector<int>(n, 0));

        //base case
        for(int i = 0; i < n; i++) dp[i][i] = nums[i];

        for(int len = 2; len <= n; len ++) {
            for(int i = 0; i + len <= n; i++) {
                int j = i + len - 1;
                dp[i][j] = sub[len - 1][i];
                dp[i][j] = max({dp[i][j], dp[i+1][j], dp[i][j-1]});
            }
        }

        vector<int>res;

        for(auto q : queries) {
            int l  = q[0];
            int r =  q[1];

            res.push_back(dp[l][r]);
        }

        return res;
    }

};