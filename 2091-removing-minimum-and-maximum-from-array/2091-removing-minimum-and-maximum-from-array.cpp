class Solution {
public:
    int minimumDeletions(vector<int>& nums) {

        auto maxi = max_element(nums.begin(), nums.end());
        auto mini = min_element(nums.begin(), nums.end());

        int maxid= distance(nums.begin(),maxi);
        int minid= distance(nums.begin(),mini);

        int l = min(maxid, minid);
        int r = max(maxid, minid);

        int n = nums.size();
        int ans = n;

        ans = min(ans, r+1);
        ans = min(ans, n-l);
        ans = min(ans, n - (r-l-1));

        return ans;
    }
};