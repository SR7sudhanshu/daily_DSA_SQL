class Solution {
public:

bool check(vector<int>&c, long long mid, long long k) {
    int n = c.size();
    long long total = 0;
    for(int i = 1; i < (1 << n); i++) {
        int count = 0;
        long long p = 1;
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                count++;
                p = p / __gcd(p, (long long)c[j]) * c[j];
            }
        }
        if(p > mid) continue;

        long long currp = mid / p;
        if(count & 1) {
            total += currp;
        }
        else total -= currp;
    }
    return total >= k;
}

    long long findKthSmallest(vector<int>& coins, int k) {
        long long s = 1;
        long long e = 2e18;
        long long ans = -1;
        while(s <=  e) {
            long long mid = (s + e) / 2;
            if(check(coins, mid, (long long)k)) {
                bool div = false;
                for(int i = 0; i < coins.size(); i++) {
                    if(mid % coins[i] == 0) div = true;
                }
                if(div) ans = mid; 
                e = mid - 1;
            }
            else s=  mid + 1;
        }
        return ans;
    }
};