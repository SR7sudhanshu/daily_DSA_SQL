
class Solution {
public:
    long long maxSum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> bitc(32, 0);
        const int mod = 1e9 + 7;
        for (int num : nums) {
            for (int j = 0; j < 32; j++) {
                if (num & (1LL << j)) {
                    bitc[j]++;
                }
            }
        }

        long long finalans = 0;
        for (int i = 0; i < k; i++) {
            long long ans = 0;

            for (int j = 0; j < 32; j++) {
                if (bitc[j] > 0) {
                    ans |= (1LL << j);
                    bitc[j]--;
                }
            }

            finalans = (finalans + (ans * ans) % mod) % mod;
        }

        return finalans;
    }
};
