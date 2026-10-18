class Solution {
public:
    int minSelection(vector<vector<int>>& ai, vector<vector<int>>& ti) {
        if(ti.empty()) return 0;
        sort(ai.begin(), ai.end());
        sort(ti.begin(), ti.end());

        vector<vector<int>>tii;
        int s = ti[0][0];
        int e = ti[0][1];
        for(int i = 1; i < ti.size(); i++) {
            if(ti[i][0] <= e) {
                s = min(s, ti[i][0]);
                e = max(e, ti[i][1]);
            }
            else {
                tii.push_back({s, e});
                s = ti[i][0];
                e = ti[i][1];
            }
        }
        tii.push_back({s, e});

        int count = 0;
        int j = 0;
        int l = 0;
        int r = 0;
        int lastend = tii[tii.size() - 1][1];
        
        for(int i = 0; i < tii.size(); i++) {
            int s = tii[i][0];
            int e = tii[i][1];

            if(l <= s && r >= e) continue;

            int currs = max(s, r);

            while(r < e || (r < s && s == e)) {
                int maxr = -1;
                
                while(j < ai.size() && ai[j][0] <= currs) {
                    maxr = max(maxr, ai[j][1]);
                    j++;
                }
                if(maxr < currs || (maxr == currs && currs < e)) {
                    return -1;
                }
                count++;
                l = currs; 
                r = maxr;   
                currs = r; 
            }
        }
        return (r < lastend) ? -1 : count;
    }
};