class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        unordered_map<int, int> req_count;
        priority_queue<vector<int>, vector<vector<int>>, 
            greater<vector<int>>> busy;

        set<int> free;
        for(int i = 0; i < k; i++) {
            free.insert(i);
        }
        int maxi = 0;
        for(int i = 0; i < arrival.size(); i++) {
            while(!busy.empty() && busy.top()[0] <= arrival[i]) {
                auto t = busy.top();
                busy.pop();

                int idx = t[1];
                free.insert(idx);
            }

            if(free.empty()) continue;

            auto it = free.lower_bound(i % k);

            if(it == free.end()) {
                it = free.begin();
            }

            int server = *it;
            req_count[server]++;
            maxi = max(maxi, req_count[server]);

            int nxttime = arrival[i] + load[i];

            free.erase(it);

            busy.push({nxttime, server});
        }

        vector<int> ans;

        for(auto i : req_count) {
            if(i.second == maxi) {
                ans.push_back(i.first);
            }
        }

        return ans;
    }
};