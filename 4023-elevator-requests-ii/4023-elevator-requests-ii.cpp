using ll = long long;
class Solution {
public:
    long long elevatorRequests(int n, int start, vector<int>& r) {
        int m = r.size();
        ll inf = 2e18;
        sort(r.begin() ,r.end());

        vector<vector<array<ll, 2>>> dp(m, vector<array<ll, 2>>(m, {inf,inf}));
        //dp[i][j][0] = minimum total penalty of i..j ending at i

        for(int i = 0; i < m; i++) {
            dp[i][i][0] = 1LL * m* abs(r[i]-start);
            dp[i][i][1] = dp[i][i][0];
        }

        for(int len = 2; len <= m; len++) {
            for(int i = 0; i+len <= m; i++) {
                int j = i + len - 1;
                int left = m - len + 1;
                //i as last dest
                dp[i][j][0] = dp[i+1][j][0] + 1LL*left*abs(r[i+1] - r[i]);
                dp[i][j][0] = min(dp[i][j][0], dp[i+1][j][1] + 1LL*left*abs(r[i]-r[j]));

                //j as last
                dp[i][j][1] = dp[i][j-1][0] + 1LL*left*abs(r[i]-r[j]);
                dp[i][j][1] = min(dp[i][j][1], dp[i][j-1][1]+1LL*left*abs(r[j-1]-r[j]));
            }
        }

        return min(dp[0][m-1][0], dp[0][m-1][1]);
    }
};