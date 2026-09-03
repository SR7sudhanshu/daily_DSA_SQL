class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int>dp(n+1, 0);

        //dp[i] = length of maximum valid ending at i

        stack<int>st;

        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                st.push(i);
                continue;
            }
            else {
                if(st.empty()) {
                    dp[i+1] = 0;
                    continue;
                }

                int lastopenidx = st.top();
                st.pop();
                dp[i+1] = dp[lastopenidx]+dp[i]+2;
            }
        }
        // for(int i = 1; i <= n; i++) cout<<dp[i]<<" ";
        return *max_element(dp.begin(), dp.end());
    }
};