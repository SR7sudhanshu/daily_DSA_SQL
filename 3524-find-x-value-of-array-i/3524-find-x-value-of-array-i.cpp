using ll = long long;

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> ans(k, 0);
        
        unordered_map<int, ll> prev;
        
        for(int i = 0; i < n; i++) {
            unordered_map<int, ll> curr;

            ll val = nums[i] % k;
            // if (val < 0) val += k; 
            curr[val]++;

            for(auto j : prev) {
                ll p = (j.first * val) % k;
                curr[p] += j.second;
            }

            for(auto j : curr) {
                ans[j.first] += j.second;
            }
            
            prev = curr;
        }

        return ans;
    }
};