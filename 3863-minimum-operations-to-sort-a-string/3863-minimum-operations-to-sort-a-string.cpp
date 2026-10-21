class Solution {
public:
    int minOperations(string s) {
        if(s.size() == 1) return 0;
        if(s.size() == 2) {
            return (s[0] <= s[1]) ? 0 : -1;
        }
        int n = s.size();
        char c = *min_element(s.begin(), s.end());
        char d = *max_element(s.begin(), s.end());
        unordered_map<int,int>m1;
        unordered_map<int,int>m2;
        for(auto i = 0; i < n; i++) {
            char a = s[i];
            int idx = a - 'a';
            if(m1.find(idx) == m1.end()) m1[idx] = i;
            m2[idx] = i;
        }
        int minidx = m1[c-'a'];
        int maxidx = m2[d-'a'];
        string t = s;
        sort(t.begin(), t.end());
        if(t == s) return 0;
        if(minidx == n - 1 && maxidx == 0) return 3;
        if(minidx == 0 && maxidx != n - 1) return 1;
        if(minidx != 0 && maxidx == n - 1) return 1;
        if(minidx == 0 && maxidx == n - 1) {
            string t = s;
            sort(t.begin(), t.end());
            if(t == s) return 0;
            else return 1;
        }
        else return 2;
    }
};