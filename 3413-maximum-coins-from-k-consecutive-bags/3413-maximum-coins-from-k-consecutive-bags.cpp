class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        int n = coins.size();
        sort(coins.begin(), coins.end());
        
        long long maxans = 0;
        long long current_sum = 0;
        int j = 0;
        for (int i = 0; i < n; i++) {
            long long window_end = coins[i][0] + k - 1;
            
            while (j < n && coins[j][1] <= window_end) {
                current_sum += 1LL * (coins[j][1] - coins[j][0] + 1) * coins[j][2];
                j++;
            }
            
            long long total = current_sum;
            if (j < n && coins[j][0] <= window_end) {
                total += 1LL * (window_end - coins[j][0] + 1) * coins[j][2];
            }
            
            maxans = max(maxans, total);
            
            current_sum -= 1LL * (coins[i][1] - coins[i][0] + 1) * coins[i][2];
        }
        
        current_sum = 0;
        j = 0;
        for (int i = 0; i < n; i++) {
            current_sum += 1LL * (coins[i][1] - coins[i][0] + 1) * coins[i][2];
            long long window_start = coins[i][1] - k + 1;
            while (j < i && coins[j][1] < window_start) {
                current_sum -= 1LL * (coins[j][1] - coins[j][0] + 1) * coins[j][2];
                j++;
            }
            
            long long total = current_sum;
            if (coins[j][0] < window_start) {
                total -= 1LL * (window_start - coins[j][0]) * coins[j][2];
            }
            
            maxans = max(maxans, total);
        }
        
        return maxans;
    }
};