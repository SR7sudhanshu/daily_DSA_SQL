class Solution {
    int MOD = 1e9 + 7;
    int dp[105][11][2][2];

    long long solve(string &s, bool tight, bool started, int last, int i) {
        if(i == s.size()) return (started) ? 1 : 0;
        
        if (dp[i][last + 1][started][tight] != -1) {
            return dp[i][last + 1][started][tight];
        }

        int end = (tight) ? s[i] - '0' : 9;
        long long ans = 0;

        for(int st = 0; st <= end; st++) {
            bool newtight = (tight) ? (st == end) : false;
            bool newstarted = started || (st != 0);

            if (!started) {
                ans = (ans + solve(s, newtight, newstarted, st, i + 1)) % MOD;
            } else {
                if (abs(last - st) == 1) {
                    ans = (ans + solve(s, newtight, newstarted, st, i + 1)) % MOD;
                }
            }
        }

        return dp[i][last + 1][started][tight] = ans;
    }

public:
    int countSteppingNumbers(string low, string high) {
        memset(dp, -1, sizeof(dp));
        long long a2 = solve(high, true, false, -1, 0);
        
        memset(dp, -1, sizeof(dp));
        long long a1 = solve(low, true, false, -1, 0);
        bool t = true;
        for(int i = 1; i < low.size(); i++) {
            if(abs(low[i] - low[i - 1]) != 1) {
                t = false;
                break;
            }
        }
        
        long long finalAns = (a2 - a1 + t + MOD) % MOD;

        return finalAns;
    }
};