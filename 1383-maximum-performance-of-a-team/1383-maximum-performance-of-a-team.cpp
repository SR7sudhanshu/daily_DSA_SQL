class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>>v;
        for(int i = 0; i < speed.size(); i++ ) {
            v.push_back({efficiency[i], speed[i]});
        }

        sort(v.rbegin(), v.rend());

        long long ans = 0;

        long long totalspeed = 0;
        const int mod = 1e9 + 7;
        priority_queue<long long, vector<long long>,greater<long long>>pq;
        for(int i = 0; i < n; i++) {
            pq.push(v[i].second);
            totalspeed += v[i].second;
            if(pq.size() > k) {
                totalspeed -= pq.top();
                pq.pop();
            }
            ans = max(ans, totalspeed * 1LL * v[i].first);
        }
        return ans % mod;
    }
};