class Solution {
public:
    long long maxEarnings(vector<vector<int>>& m) {
        int n = m.size();
        
        vector<pair<long long, long long>> dp(n, {0, 0});

        vector<int> temp;

        sort(m.begin(), m.end(), [](const vector<int>&a, vector<int>&b){
            return a[1] < b[1];
        });

        for(auto i : m) temp.push_back(i[1]);

        temp.erase(unique(temp.begin(), temp.end()), temp.end());

        unordered_map<int, int> lastidx;
        lastidx[m[0][1]] = 0;

        dp[0].first = m[0][2];
        dp[0].second = (long long)m[0][2] - m[0][1]; 

        for(int i = 1; i < n; i++) {
            long long currs = m[i][0];
            long long curre = m[i][1];
            long long p = m[i][2];

            auto it = upper_bound(temp.begin(), temp.end(), currs) - temp.begin();
            it--;
            long long takep = p;

            if(it >= 0) {
                if(temp[it] <= currs) {
                    int idx = lastidx[temp[it]];
                    takep = dp[idx].second + p + currs;
                }
            }
            dp[i].first = max(dp[i - 1].first, takep);
            
            dp[i].second = max(dp[i - 1].second, takep - curre);

            lastidx[curre] = i;
        }

        return dp[n - 1].first;
    }
};