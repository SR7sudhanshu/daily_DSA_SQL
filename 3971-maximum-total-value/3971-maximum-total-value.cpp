class Solution {
    long long count(vector<int>& value, vector<int>& decay, int mid){
        long long cnt = 0;
        for(int i = 0; i < value.size(); i++){
            if(value[i] < mid) continue;
            cnt += ((value[i] - mid) / decay[i]) + 1;
        }
        return cnt;
    }

public:
    int maxTotalValue(vector<int>& value, vector<int>& decay, int m) {
        int low = 1, high = 1e9;
        int mod = 1e9 + 7;

        while(low <= high){
            int mid = low + (high - low) / 2;
            long long cnt = count(value, decay, mid);

            if(cnt >= m) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        int threshold = high;

        long long ans = 0;
        long long cnt = 0;

        for(int i = 0; i < value.size(); i++){
            if(value[i] < threshold + 1) continue;

            long long t = (value[i] - (threshold + 1)) / decay[i] + 1;
            cnt += t;
            long long sum = t * (2LL * value[i] - (t - 1) * decay[i]) / 2LL;
            ans = (ans + (sum % mod)) % mod;
        }

        int req = m - cnt;
        ans = (ans + (1LL * threshold * req) % mod) % mod;
        
        return ans;
    }
};