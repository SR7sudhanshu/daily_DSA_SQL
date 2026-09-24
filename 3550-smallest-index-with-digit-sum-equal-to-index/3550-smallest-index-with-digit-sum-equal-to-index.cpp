class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            int curr = nums[i];
            int sum = 0;
            while(curr > 0) {
                sum += curr % 10;
                curr /= 10;
            }
            if(sum == i) return i;
        }
        return -1;
    }
};