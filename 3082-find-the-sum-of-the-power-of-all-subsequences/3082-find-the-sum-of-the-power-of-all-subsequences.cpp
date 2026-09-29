class Solution {
public:
long long dp[101][101][101];
const int mod = 1e9 + 7;
long long power(long long b, long long e) {
    long long res = 1;
    while(e > 0) {
        if(e & 1 ) res = (res * b) % mod;
        b = (b * b) % mod;
        e >>= 1;
    }
    return res % mod;
}
long long solve(int i, vector<int>&nums, int k, int sum, int count) {
    if(i == nums.size()) {
        if(sum == k) {
            int n = nums.size();
            long long a = power(2, n - count);
            return a;
        }
        else return 0;
    }

    if(dp[i][sum][count] != -1) return dp[i][sum][count];

    long long ans = 0;

    if(sum + nums[i] <= k) ans =(ans+solve(i+1,nums,k,sum+nums[i],count+1))%mod;
    ans =(ans + solve(i + 1, nums, k, sum, count))%mod;

    return dp[i][sum][count] = ans;
}
    int sumOfPower(vector<int>& nums, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(0, nums, k, 0, 0) % mod;
    }
};