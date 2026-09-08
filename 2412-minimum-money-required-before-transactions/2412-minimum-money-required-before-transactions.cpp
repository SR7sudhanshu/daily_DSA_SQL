class Solution {
public:
    long long minimumMoney(vector<vector<int>>& t) {
        vector<vector<int>>pos, neg;
        long long totalloss = 0;
        long long maxgain = 0;
        long long maxst = 0;
        for(int i = 0; i < t.size(); i++) {
            int diff = t[i][0] - t[i][1];
            if(diff > 0) {
                totalloss += diff;
                pos.push_back(t[i]);
            }   
            else {
                maxgain += -diff;
                neg.push_back(t[i]);
                maxst = max(maxst, (long long)t[i][0]);
            }
        }

        //process pos
        long long maxi = 0;
        for(int i = 0; i < pos.size(); i++) {
            long long currloss = totalloss - (pos[i][0] - pos[i][1]);
            maxi = max(maxi, pos[i][0] + currloss);
        }

        //process neg
        long long g = 0;
        long long y = maxi - totalloss;
        // for(int i = 0; i < neg.size(); i++) {
        //     long long currgain = maxgain - (neg[i][1] - neg[i][0]);
        //     long long b = max((long long)0, neg[i][0] - y - currgain);
        //     g = max(g, b);
        // }
        cout<<maxi;
        return max(1LL*0,(maxst - y)) + maxi;

    }
};