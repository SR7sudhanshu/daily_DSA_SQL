class Solution {
    public int minDays(int n) {
        int[] dp = new int[n + 1];

        dp[0] = 0;
        dp[1] = 1;

        for(int i = 2; i <= n; i++) {
            dp[i] = Integer.MAX_VALUE;
            for(int j = 1 ;j <= i; j++) {
                int t = i - ((j * (j + 1)) / 2);
                if(t < 0) break;
                
                if (t == 0) {
                    dp[i] = Math.min(dp[i], j);
                } else {
                    dp[i] = Math.min(dp[i], dp[t] + j + 1);
                }
            }
        }

        return dp[n];
    }
}