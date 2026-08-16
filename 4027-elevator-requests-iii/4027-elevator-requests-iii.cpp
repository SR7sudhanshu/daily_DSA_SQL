class Solution {
public:
    long long elevatorRequests(int n_floors, int start, vector<vector<int>>& req) {
        int n = req.size();
        const long long inf = 1e18;
        vector<vector<long long>> dp(n, vector<long long>(1 << n, inf));

        for (int i = 0; i < n; i++) {
            long long t = abs(start - req[i][1]);
            dp[i][1 << i] = max(t, (long long)req[i][0]);
        }

        for (int m = 1; m < (1 << n); m++) {
            for (int j = 0; j < n; j++) {
                if ((1 << j) & m) {
                    int s = m ^ (1 << j);

                    for (int k = 0; k < n; k++) {
                        if ((1 << k) & s) {
                            long long t = abs(req[k][1] - req[j][1]);
                            long long a = dp[k][s] + t;
                            long long c = max(a, (long long)req[j][0]);
                            dp[j][m] = min(dp[j][m], c);
                        }
                    }
                }
            }
        }

        long long ans = inf;
        int full = (1 << n) - 1;

        for (int i = 0; i < n; i++) {
            ans = min(ans, dp[i][full]);
        }

        return ans;
    }
};