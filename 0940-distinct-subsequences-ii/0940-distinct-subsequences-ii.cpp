class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<long long>dp(26, 0);

        //dp[i] = number of dist subs ending at char i  i <= 25
        const int mod = 1e9 + 7;

        dp[s[0]-'a'] = 1;

        for(int i = 1; i < n; i++) {
            int idx = s[i] - 'a';
            vector<long long>ndp = dp;

            long long sum = 0;
            
            for(int k = 0; k < 26; k++) {
                if(k == idx) continue;
                sum = (sum + dp[k]) % mod;
            }

            ndp[idx] = (ndp[idx] + sum + 1) % mod;

            dp = ndp;
        } 

        long long ans = 0;

        for(int i = 0; i < 26; i++) {
            ans = (ans + dp[i]) % mod;
        }

        return ans;
    }
};