class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        int n = nums.size();
        const int inf = 1e9;

        unordered_map<int, vector<pair<int, int>>> m;
        for (int x : nums) {
            if (m.count(x)) continue;

            vector<int> c(target + 1, inf);

            long long u = x;
            int e = 0;  

            while (true) {

                int t = u;
                int d = 0; 

                while (t > 0) {

                    if (t <= target) {
                        c[t] = min(c[t], e + d);
                    }

                    t /= 2;
                    d++;
                }

                if(u > target) break;

                u *= 2;
                e++;
            }

            for (int j = 1; j <= target; j++) {
                if (c[j] != inf) {
                    m[x].push_back({j, c[j]});
                }
            }
        }
        vector<int> dp(target + 1, inf);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            vector<int> newdp = dp;
            
            for (auto& [v, k] : m[nums[i]]) {
                for (int s = target; s >= v; s--) {
                    if (dp[s - v] != inf) {
                        newdp[s] = min(newdp[s], dp[s - v] + k);
                    }
                }
            }
            dp = newdp;
        }
        
        return (dp[target] >= inf) ? -1 : dp[target];
    }
};