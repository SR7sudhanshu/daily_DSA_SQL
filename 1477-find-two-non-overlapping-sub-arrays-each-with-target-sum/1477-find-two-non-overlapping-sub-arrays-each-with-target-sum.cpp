class Solution {
public:

    void solve(vector<int>& arr, int target, vector<int>& pre) {

        unordered_map<long long, int> m;
        m[0] = -1;

        long long sum = 0;

        for(int i = 0; i < arr.size(); i++) {

            sum += arr[i];
            if(i > 0) {
                pre[i] = pre[i - 1];
            }

            long long req = sum - target;
            if(m.find(req) != m.end()) {

                int len = i - m[req];

                pre[i] = min(pre[i], len);
            }
            m[sum] = i;
        }
    }

    int minSumOfLengths(vector<int>& arr, int target) {

        int n = arr.size();

        vector<int> pre(n, 1e9);
        vector<int> suff(n, 1e9);
        solve(arr, target, pre);

        reverse(arr.begin(), arr.end());

        solve(arr, target, suff);

        reverse(suff.begin(), suff.end());

        int ans = 1e9;
        for(int i = 0; i < n - 1; i++) {
            if(pre[i] != 1e9 && suff[i + 1] != 1e9) {
                ans = min(ans, pre[i] + suff[i + 1]);
            }
        }

        return ans == 1e9 ? -1 : ans;
    }
};