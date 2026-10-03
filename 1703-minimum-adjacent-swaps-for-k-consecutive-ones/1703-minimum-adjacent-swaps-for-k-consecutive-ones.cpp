class Solution {
public:
    vector<long long> solve(vector<int>& p, int len) {
        int m = p.size();
        vector<long long> res(m, 0);
        if (len == 0) return res;

        long long req = 0;
        long long currsum = 0;
        
        for(int i = 0; i < m; i++) {
            if (i < len) {
                req += 1LL * (i + 1) * p[i];
                currsum += p[i];
            } else {
                req += 1LL * len * p[i] - currsum;
                currsum += p[i] - p[i - len];
            }
            res[i] = req;
        }
        return res;
    }

    long long minMoves(vector<int>& nums, int k) {
        if (k == 1) return 0;
        
        vector<int> idx;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) {
                idx.push_back(i);
            }
        }

        vector<int> g;
        for(int i = 1; i < idx.size(); i++) {
            g.push_back(idx[i] - idx[i - 1] - 1);
        }

        int left = k / 2;
        int right = k / 2;
        if (!(k & 1)) right = left - 1;
        
        int m = g.size();

        vector<long long> l = solve(g, left);
        
        reverse(g.begin(), g.end());
        vector<long long> r = solve(g, right);
        reverse(r.begin(), r.end());

        long long ans = LLONG_MAX;
        
        for(int i = left - 1; i <= m - 1 - right; i++) {
            long long currc = l[i];
            if (right > 0) {
                currc += r[i + 1];
            }
            ans = min(ans, currc);
        }

        // long long offset = (1LL * left * (left + 1) / 2) + (1LL * right * (right + 1) / 2);
        
        return ans;
    }
};