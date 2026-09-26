class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int len = 0;
        for(int i = 0; i < nums.size(); i++) {
            long long sum = 0;
            unordered_map<int, int>mp;
            for(int j = i; j < nums.size(); j++) {
                sum += nums[j];

                long long temp = ((sum % k)+k)%k;

                int c = ((2 * (nums[j]%k)%k) + k)%k ;
                mp[c % k]++;
                if(temp == 0) len = max(len, j - i + 1);
                if(mp[temp]) len = max(len, j - i + 1);
            }
        }
        return len;
    }
};