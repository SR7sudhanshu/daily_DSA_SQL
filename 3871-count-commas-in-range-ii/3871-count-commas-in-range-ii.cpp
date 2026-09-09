class Solution {
public:
    long long countCommas(long long n) {

        int len = to_string(n).size();
        long long ans = 0;

        for(int i = 4; i <= len; i++) {

            long long nums = 9LL * pow(10, i - 1);

            if(i == len)
                nums = n - pow(10, i - 1) + 1;

            long long commas = (i - 1) / 3;

            ans += nums * commas;
        }

        return ans;
    }
};