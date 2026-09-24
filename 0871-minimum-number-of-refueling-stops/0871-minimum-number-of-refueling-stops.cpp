class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int curr = 0;
        int currfuel = startFuel;
        int j = 0;
        
        sort(stations.begin(), stations.end(), [](const vector<int>&a, const vector<int>&b) {
            return a[0] < b[0];
        });

        priority_queue<vector<int>>pq;

        int count = 0;

        while(curr < target && startFuel != 0) {

            curr += currfuel;
            currfuel = 0;
            
            while(j < stations.size()) {
                if(stations[j][0] <= curr) {
                    pq.push({stations[j][1], stations[j][0]});
                    j++;
                }
                else break;
            }
            
            if(curr >= target) return count;

            if(!pq.empty()) {
                currfuel += pq.top()[0];
                pq.pop();
                count++;
            }
            else return -1;
        }

        return count;
    }
};