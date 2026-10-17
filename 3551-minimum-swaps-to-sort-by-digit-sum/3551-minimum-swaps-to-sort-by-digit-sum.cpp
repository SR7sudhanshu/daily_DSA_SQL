class Solution {
public:
int get(vector<int>&temp, vector<int>&nums) {
    unordered_map<int ,int>mp;

    for(int i = 0; i < nums.size(); i++) {
        mp[nums[i]] = i;
    }

    int n = nums.size();

    int swaps  = 0;

    vector<int>vis(n, 0);

    for(int i = 0; i < n; i++) {
        if(vis[i] || mp[temp[i]] == i) continue;

        int j = i;
        int count = 0;

        while(!vis[j]) {
            vis[j] = 1;
            j = mp[temp[j]];
            count++;
        }

        swaps += count - 1;
    }

    return swaps;
}
    int minSwaps(vector<int>& nums) {
        vector<pair<int, int>>v;
        for(int i = 0; i < nums.size(); i++) {
            int curr = nums[i];
            int sum = 0;
            while(curr > 0) {
                sum += curr % 10;
                curr /= 10;
            }
            v.push_back({sum, nums[i]});
        }

        sort(v.begin(), v.end());
        vector<int>temp;

        for(int i= 0; i < v.size(); i++) {
            temp.push_back(v[i].second);
        }
        
        int count = get(temp, nums);

        return count;
    }
};