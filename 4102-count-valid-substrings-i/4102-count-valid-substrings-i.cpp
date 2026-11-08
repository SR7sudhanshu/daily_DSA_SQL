class Solution {
public:
    long long countValidSubstrings(string s) {
        int n = s.size();
        vector<int>st;
        vector<int>en;

        st.push_back(-1);
        for(int i = 0; i + 3 <= s.size();i ++) {
            if(s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c') {
                st.push_back(i);
                en.push_back(i + 2);
            }
        }
        en.push_back(n);

        long long ans = 0;
        // for(auto i : st) cout<<i<<" ";
        // cout<<endl;
        // for(auto i : en) cout<<i<<" ";

        for(int i = 0; i < st.size(); i++) {
            int vs = st[i] + 1;
            int ve = en[i] - 1;

            long long len = ve - vs + 1;
            ans += (len * (len + 1)) / 2;
            if (i > 0) ans -= 1; 
        }
        return ans;
    }
};