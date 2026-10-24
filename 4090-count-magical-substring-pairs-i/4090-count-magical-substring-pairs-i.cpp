class Solution {
public:
    int countMagicalPairs(string s) {

        int n = s.size();
        vector<vector<int>>dp(27, vector<int>(2001, 0));
        vector<vector<int>>count(n + 1, vector<int>(n + 1, 0));
        for(int i = 0; i < n; i++) {
            unordered_map<int, int>m;
            for(int j = i; j < n; j++) {
                m[s[j] - 'a']++;
                int sz = m.size();
                int st = i;
                int en = j;
                dp[sz][st]++;
                count[i][j] = sz;
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                int e = j;
                int dis = count[i][j];

                ans += dp[dis][e + 1];
            }
        }
        return ans;
    }
};