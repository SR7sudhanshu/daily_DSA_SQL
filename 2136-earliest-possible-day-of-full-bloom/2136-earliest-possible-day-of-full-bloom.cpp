class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int, int>>v;
        for(int i = 0; i < plantTime.size(); i++) {
            v.push_back({plantTime[i], growTime[i]});
        }

            sort(v.begin(), v.end(), [](const pair<int,int>&a, const pair<int,int>&b) {
                return max(a.first + a.second, a.first + b.first + b.second) <
                    max(b.first + b.second, b.first + a.first + a.second);
            });

            int ans = 0;
            int count = 0;

            for(int i = 0; i < v.size(); i++) {
                count += v[i].first;
                ans = max(ans, count + v[i].second);
            }

        return ans;
    }
};