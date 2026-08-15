class Solution {
public:
int getans(string &s) {
    int count = 0;
        int n = s.size();
        int i = 0;
        int j = n - 1;
        while(i < j) {
            if(s[i] != s[j]) {
                int diff = abs((s[i] - 'a') - (s[j] - 'a'));
                count += min(diff, 26 - diff);
            }
            i++;
            j--;
        }
        return count;
}
    int minOperations(string s) {
        string temp = s + s;
        int n = s.size();
        int len = temp.size();
        temp.pop_back();
        int ans = INT_MAX;
        for(int i = 0; i + n < len; i++) {
            string t = temp.substr(i, n);
            int d = getans(t);
            ans = min(ans, i + d);
        }
        return ans;
    }
};