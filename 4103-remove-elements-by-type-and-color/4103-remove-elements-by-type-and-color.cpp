class Solution {
public:
    bool canRemoveAll(vector<int>& t, vector<int>& c, vector<int>& g) {
        stack<vector<int>>st;
        for(int i = 0; i < t.size(); i++) {
            if(st.empty()) {
                st.push({t[i], c[i], 0});
            }

            auto tp = st.top();
            int ct = t[i];
            int cc = c[i];
            int gr = tp[2];

            if(tp[0] == ct && tp[1] == cc) {
                st.pop();
                st.push({t[i], c[i], ++gr});
            }
            else {
                st.push({t[i], c[i], 1});
            }

            auto tt = st.top();
            st.pop();
            int ctask = tt[0];
            int ccolor = tt[1];
            int ccount = tt[2];
            int rcount = g[ctask];
            int ncount = ccount % rcount;
            if(ncount > 0) {
                st.push({ctask, ccolor, ncount});
            }
        }

        return st.empty();
    }
};