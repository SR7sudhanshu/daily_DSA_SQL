class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int n = nums.size();
        vector<int>d(n + 3, 0);

        for(int i = 0; i < n; i++) {
            if(nums[i] != i+1) {
                int req = nums[i]-1;
                int curr = i;
                d[min(curr, req)]++;
                d[max(curr, req) + 1]--;
            }
        }

        for(int i = 1; i < n; i++) d[i] += d[i - 1];
        for(auto i : d) cout<<i<<" ";
        int ans = 0;
        for(int i = 0; i < n; i++) {
            // if(nums[i] != i + 1) {
                int count = 0;
                for(int j = i + 1; j < n; j++) {
                    if(nums[j] < nums[i]) count++;
                }
                ans += count;
            // }
        }
        int lock = 0;
        for(int i = 0; i < n; i++) {
            if(d[i] && locked[i]) lock++;
        }
        if(lock > k) return -1;
        return ans + lock;
    }
};