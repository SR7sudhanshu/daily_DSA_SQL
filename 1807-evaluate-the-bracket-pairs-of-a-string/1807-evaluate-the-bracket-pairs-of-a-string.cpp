class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans = "";
        unordered_map<string, string> mp;
        for(auto i : knowledge) {
            mp[i[0]] = i[1];
        }

        int i = 0;
        while(i < s.size()) {
            if(s[i] == '(') {
                int j = i + 1;
                string q;
                while(j < s.size() && s[j] != ')') {
                    q.push_back(s[j]);
                    j++;
                }
                if(mp.find(q) == mp.end()) {
                    ans.push_back('?');
                }
                else {
                    ans += mp[q];
                }

                i = j+1;
            }
            else {
                ans.push_back(s[i]);
                i++;
            }
        }

        return ans;
    }
};