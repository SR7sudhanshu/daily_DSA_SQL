
class Solution {
public:
    using ll = long long;

    class Fenwick {
    public:
        int n;
        vector<int> bit;

        Fenwick(int n) {
            this->n = n;
            bit.assign(n + 1, 0);
        }

        void update(int idx, int val) {
            while (idx <= n) {
                bit[idx] += val;
                idx += idx & -idx;
            }
        }

        int query(int idx) {
            int sum = 0;

            while (idx > 0) {
                sum += bit[idx];
                idx -= idx & -idx;
            }

            return sum;
        }
    };

    long long countOperationsToEmptyArray(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i + 1});
        }

        sort(arr.begin(), arr.end());

        Fenwick ft(n);
        for (int i = 1; i <= n; i++) {
            ft.update(i, 1);
        }

        long long ans = 0;
        int last = 0;

        for (auto [value, curr] : arr) {

            if (curr > last) {
                ans += ft.query(curr) - ft.query(last);
            }
            else {
                ans += ft.query(n) - ft.query(last);
                ans += ft.query(curr);
            }
            ft.update(curr, -1);
            last = curr;
        }

        return ans;
    }
};