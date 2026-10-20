class Solution {
public:
    bool check(vector<int>& nums, int len) {
        int n = nums.size();
        int lastmax = INT_MIN;

        for (int i = 0; i < n; i += len) {
            int peakcount = 0;
            int currmin = INT_MAX;
            int currmax = INT_MIN;

            for (int j = i; j < i + len - 1; j++) {
                if (nums[j] > nums[j + 1]) peakcount++;
                if (peakcount > 1) return false;
            }

            for (int j = i; j < i + len; j++) {
                currmin = min(currmin, nums[j]);
                currmax = max(currmax, nums[j]);
            }

            if (currmin < lastmax) return false;
            int lastidx = min(i + len - 1, n - 1);
            if(peakcount && nums[i] < nums[lastidx]) return false;
            lastmax = currmax;
        }
        return true;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                if (check(nums, i)) ans += i;

                if (i != n / i) {
                    if (check(nums, n / i)) ans += (n / i);
                }
            }
        }

        return ans;
    }
};