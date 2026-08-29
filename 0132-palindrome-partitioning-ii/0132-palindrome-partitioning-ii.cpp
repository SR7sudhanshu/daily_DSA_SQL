class Solution {
public:
    int minCut(string s) {
        int n = s.size();

        if (n == 1) return 0;

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {

                if (s[i] == s[j]) {
                    if (j - i == 1)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = dp[i + 1][j - 1];
                }
            }
        }

        vector<int> count(n, INT_MAX);

        count[0] = 0;

        for (int i = 1; i < n; i++) {
            if (dp[0][i]) {
                count[i] = 0;
            }
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j + 1][i]) {
                    count[i] = min(count[i], count[j] + 1);
                }
            }
        }

        return count[n - 1];
    }
};