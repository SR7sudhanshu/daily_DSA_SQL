class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int ans = 1;
        for(int i = 0; i < nums.size(); i++) nums[i] = nums[i] % k;

        int i = 0;
        int n  = nums.size();
        while(i < n) {
            int j = i;
            while(j < n && nums[j] == nums[i]) {
                int curr = nums[i];
                int len = j - i + 1;
                if(((len-1)* curr) % k == 0) {
                    ans = max(ans, len);
                }
                j++;
            }
            
            i = j;
        }

        return ans;
    }
};