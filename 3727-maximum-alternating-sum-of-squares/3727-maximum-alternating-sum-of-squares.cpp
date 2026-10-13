class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        priority_queue<int>pq;
        for(auto i : nums) {
            if(i < 0) pq.push(-i);
            else pq.push(i);
        }

        int n = nums.size();
        int req;
        if(n & 1) req = (n + 1) / 2;
        else req = n / 2;
        long long ans = 0;
        while(!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            if(req > 0) {
                ans += t * t *1LL;
                req--;
            }
            else {
                ans -= t * t * 1LL;
            }
        }

        return ans;
    }
};