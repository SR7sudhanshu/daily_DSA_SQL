class Solution {
private:
    int n;
    int minsum = INT_MAX;
    vector<int> result;

    void solve(const vector<int>& nums, vector<bool>& visited, vector<int>& temp, int idx, int sum) {
        if (sum >= minsum) return;

        if (idx == n) {
            int total_sum = sum + abs(temp[n - 1] - nums[temp[0]]); 
            if (total_sum < minsum) {
                minsum = total_sum;
                result = temp; 
            }
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                temp[idx] = i;

                int cost = abs(temp[idx - 1] - nums[temp[idx]]);
                solve(nums, visited, temp, idx + 1, sum + cost);

                visited[i] = false;
            }
        }
    }

public:
    vector<int> findPermutation(vector<int>& nums) {
        n = nums.size();
        vector<bool> visited(n, false);
        vector<int> temp(n, 0);

        temp[0] = 0;     
        visited[0] = true;

        solve(nums, visited, temp, 1, 0);
        return result;       
    }
};