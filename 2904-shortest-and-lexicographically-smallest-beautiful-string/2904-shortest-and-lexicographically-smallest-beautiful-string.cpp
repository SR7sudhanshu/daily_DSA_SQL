class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int i = 0;
        int j = 0;
        int count = 0;
        int len = n + 1;
        string ans = "";
        while(i < n) {
            count += s[i]-'0';
            while(k < count && j <= i) {
                if(s[j] == '1') count--;
                j++;
            }
            while(s[j] == '0' && j < i) {
                j++;
            } 
            if(count == k) {
                int curr = i - j + 1;
                if(curr < len) {
                    len = curr;
                    ans = s.substr(j, curr);
                }
                else if(curr == len) {
                    string t = s.substr(j, curr);
                    if(t < ans) ans = t;
                }
            }
            i++;
        }
        return ans;
    }
};