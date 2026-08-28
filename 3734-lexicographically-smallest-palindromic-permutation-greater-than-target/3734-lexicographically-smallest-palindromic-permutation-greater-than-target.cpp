class Solution {
public:

    string ans;

bool solve(string &half,string &target,int i,int mid,vector<int>&m,bool tight,string &middle,bool& specialcase) {
        if(i == mid) {
            if (!tight)
                return true;
            else {
                return specialcase;
            }
        }
        int start = (tight && i < target.size()) ? target[i] - 'a' : 0;
        start = max(0, start);
        for(int c = start; c < 26; c++) {
            if(m[c] == 0) continue;
            bool newTight = tight && (c == target[i] - 'a');
            half.push_back(char(c + 'a'));
            m[c]--;
            if(solve(half, target, i + 1, mid,m, newTight, middle, specialcase)) {
                return true;
            }
            half.pop_back();
            m[c]++;
        }
        return false;
    }

    string lexPalindromicPermutation(string s, string t) {
        int n = s.size();
        vector<int> m(26, 0);
        for(char c : s) m[c - 'a']++;

        string middle = "";
        int oddcount = 0;
        
        for(int i = 0; i < 26; i++) {
            if(m[i] % 2 != 0) {
                oddcount++;
                middle.push_back(char(i + 'a'));
            }
            m[i] /= 2;
        }
        if (oddcount > (n % 2)) return "";

        int mid = n / 2;

        string total = "";
        if (t.size() >= mid) {
            string tfirsthalf = t.substr(0, mid);
            string rev = tfirsthalf;
            reverse(rev.begin(), rev.end());
            total = tfirsthalf + middle + rev;
        }
        bool specialcase = total > t; 

        string half = "";
        bool found = solve(half, t, 0, mid, m, true, middle, specialcase);
        
        if (!found) return "";
        
        string secondhalf = string(half.rbegin(), half.rend()); 
        string ans = half + middle + secondhalf; 
        
        return ans;
    }
};