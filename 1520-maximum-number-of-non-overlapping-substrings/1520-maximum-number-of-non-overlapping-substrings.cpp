class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int>f(26, 0);
        vector<int>first(26, INT_MAX);
        vector<int>last(26, -1);      

        for(auto i = 0; i < s.size(); i++) {
            f[s[i]-'a']++;
            first[s[i] - 'a'] = min(first[s[i] - 'a'], i);
            last[s[i] - 'a'] = max(last[s[i] - 'a'], i);
        }

        vector<vector<int>> intervals;
        for(int i = 0; i < 26; i++) {
            int st = first[i];
            if (st == INT_MAX) continue;

            for(int j = 0; j < 26; j++) {
                int en = last[j];
                if (en == -1 || st > en) continue; 

                vector<int> t(26, 0);

                for(int k = st; k <= en; k++) {
                    t[s[k] - 'a']++;
                }

                bool p = true;

                for(int k = 0; k < 26; k++) {
                    if(t[k] > 0) { 
                        if(t[k] != f[k]) {
                            p = false;
                            break;
                        }
                    }
                }

                if(p) intervals.push_back({st, en});
            }
        }

        sort(intervals.begin(), intervals.end(), [](const vector<int>&a, const vector<int>&b) {
            if(a[1] == b[1]) return a[0] > b[0]; 
            else return a[1] < b[1];
        });
        vector<string> result;
        int lastend = -1;

        for(auto& interval : intervals) {
            int st = interval[0];
            int en = interval[1];
            if(st > lastend) {
                result.push_back(s.substr(st, en - st + 1));
                lastend = en;
            }
        }

        return result;
    }
};