class Solution {
public:
bool check(char a, char b) {
    return a-'a'== ((b-'a'+1)%26) || (a-'a'+1)%26==(b-'a');
}
    string lexicographicallySmallestString(string s) {
        int n = s.length();
        if (n == 0) return "";
        vector<vector<bool>> emtysub(n, vector<bool>(n, false));

        for (int len = 2; len <= n; len += 2) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                if (check(s[i],s[j])) {
                    if (len == 2 || emtysub[i + 1][j - 1]) {
                        emtysub[i][j] = true;
                        continue; 
                    }
                }
                
                for (int k = i + 1; k < j; k += 2) {
                    if (emtysub[i][k] && emtysub[k + 1][j]) {
                        emtysub[i][j] = true;
                        break;
                    }
                }
            }
        }

        vector<string> dp(n + 1, "");
        
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = s[i] + dp[i + 1];
            
            for (int k = i + 1; k < n; k += 2) { 
                if (check(s[i],s[k])) {
                    bool insideempty = (k == i + 1) || emtysub[i + 1][k - 1];
                    
                    if (insideempty) {
                        if (dp[k + 1] < dp[i]) {
                            dp[i] = dp[k + 1];
                        }
                    }
                }
            }
        }

        return dp[0];
    }
};