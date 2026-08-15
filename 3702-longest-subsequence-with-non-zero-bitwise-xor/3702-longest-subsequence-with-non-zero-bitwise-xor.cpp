class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int j = 0; j < 32; j++) {
            int o = 0, z = 0;

            for(int i  = 0; i < n; i++) {
                if((1 << j ) & nums[i]) {
                    o++;
                }
                else z++;
            }
            if(o % 2 == 0 && o > 0) o--; 
            if(o == 0) {
                continue;
            }
            else {
                ans = max(ans, z + o);
            }
        }
        return ans;
    }
};