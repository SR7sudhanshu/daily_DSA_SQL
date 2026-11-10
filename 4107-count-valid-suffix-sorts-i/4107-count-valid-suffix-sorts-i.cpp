class Solution {
public:
    int countSuffix(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        int j = n - 2;
        while(j >= 0 && target[j] >= target[j + 1]) {
            j--;
        }
        bool a = true;
        for(int i = 0; i <= j; i++) {
            if(target[i] != nums[i]) {
                a = false;
                break;
            }
        }
        int k = j + 1;
        while(k < n && target[k] == nums[k]) {
            k++;
        }

        bool d = true;
        unordered_map<int, int>mp;
        for(int i = k; i < n; i++) {
            mp[nums[i]]++;
        }
        for(int i = k; i < n; i++) {
            mp[target[i]]--;
        }
        for(auto i : mp) {
            if(i.second > 0) {
                d = false;
                break;
            } 
        }

        if(!a || !d) return 0;

        return k-j-(k >= n);
    }
};