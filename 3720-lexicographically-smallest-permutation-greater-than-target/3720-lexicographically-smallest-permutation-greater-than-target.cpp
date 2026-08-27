class Solution {
public:
string ans;
    bool solve(string &s,int i, string &t, unordered_map<int,int>&mp, bool tight) {
        if(i == t.size()) {
            if(s > t) {
                ans = s;                
                return true;
            }
            return false;
        }

        int st = (tight) ? t[i] - 'a' : 0;

        for(; st < 26; st++) {
            bool newtight;
            if(tight) {
                if(st == t[i]-'a') newtight = true;
                else newtight = false;
            }
            else {
                newtight = false;
            }
            if(mp[st]) {
                string temp = s;
                char c = char('a'+st);
                s.push_back(c);
                mp[st]--;
                if(solve(s,i+1,t,mp,newtight)) 
                    return true;
                s.pop_back();
                mp[st]++;
            }
        }
        return false;
    }    
    string lexGreaterPermutation(string s, string target) {
        unordered_map<int,int>mp;
        for(auto c : s) mp[c-'a']++;

        bool tight = true;
        string temp = "";
        int n = s.size();
        bool t = solve(temp,0, target, mp, tight); 
        return ans;
    }
};