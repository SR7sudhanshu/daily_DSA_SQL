class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int m = words[0].size();
        int n = target.size();
        
        const int mod = 1e9 + 7;

        vector<vector<long long>> freq(26, vector<long long>(m, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < words.size(); j++) {
                freq[words[j][i] - 'a'][i]++;
            }
        }

        vector<vector<long long>> dp(n, vector<long long>(m, 0));
        int idx = target[0] - 'a';

        for (int j = 0; j < m; j++) {
            dp[0][j] = (j > 0 ? dp[0][j - 1] : 0) + freq[idx][j];
        }

        for(int i = 1; i < n; i++) {
            int idx = target[i] - 'a';

            for(int j = i; j < m; j++) {
                dp[i][j] = (dp[i][j-1] + (freq[idx][j]*dp[i-1][j-1]) % mod) % mod;
            }
        }

        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < m; j++) {
        //         cout<< dp[i][j] <<" ";
        //     }
        //     cout<<endl;
        // }

        return dp[n - 1][m - 1];
    }
};