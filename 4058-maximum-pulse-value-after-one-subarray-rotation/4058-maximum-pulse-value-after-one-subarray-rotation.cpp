using ll = long long;
class Solution {
public:
    long long maxValue(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<long long>rev;
        long long ori = (ll)nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(i & 1) ori -= nums[i];
            else ori += nums[i];

            if(i & 1) {
                rev.push_back((ll)(nums[i] - nums[i - 1])-(ll)(-nums[i] + nums[i - 1]));
            }
            else {
                rev.push_back((ll)(-nums[i]+nums[i-1])-(ll)(nums[i]-nums[i-1]));
            }
        }

        int n = rev.size();
        vector<long long>dp(n, 0);

        dp[0] = max(1LL*0, rev[0]);
        if(1 < n) dp[1] = max(1LL*0, rev[1]);

        for(int i = 2; i < n; i++) {
            dp[i] = max(1LL*0, rev[i]);
            //extend
            dp[i] = max(dp[i], rev[i] + dp[i - 2]);
        }

        long long ans = ori;
        // for(auto i : rev) cout<<i <<" ";
        for(int i = 0; i < n; i++) ans = max(ans, ori + dp[i]);

        return ans;
    }
};