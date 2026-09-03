class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        vector<int>o;
        vector<int>e;
        for(auto i : nums) {
            if(i & 1) o.push_back(i);
            else e.push_back(i);
        }
        //for odd even - odd
        //for even even - even, odd - odd
        if(o.size() == 0  || e.size() == 0) return true;


        sort(o.begin(), o.end());
        sort(e.begin(), e.end());
        
        
        //for odd parity
        bool oddp = true;
        for(int i = 0; i < nums.size(); i++) {
                if(nums[i] % 2 == 0) {
                    if( (nums[i] - o[0]) < 1) oddp = false;
                }
        }    

        //for even parity
        bool evenp = true;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] & 1) {
                if( (nums[i] - o[0]) < 1) evenp = false;
            }
        }

        return oddp || evenp;
    }
};