class Solution {
public:
    double minTime(int n, int k, int m, vector<int>& time, vector<double>& mul) {
        if(n > 1 && k == 1) return -1.0;

        int count = (1 << n) - 1;

        vector<vector<vector<double>>>dp(1<<n, vector<vector<double>>(m, vector<double>(2, 1e18)));

        dp[(1 << n)-1][0][1] = 0;

        priority_queue<vector<double>, vector<vector<double>>, greater<vector<double>>>pq;

        pq.push({0.0, (double)((1 << n) - 1), 0.0, 1.0});

        while(!pq.empty()) {
            auto v = pq.top(); pq.pop();

            double currtime = v[0];
            int currstate = v[1];
            int currj = v[2];
            int boat = v[3];

            if (currtime > dp[currstate][currj][boat]) continue;

            if(boat == 0) {
                for(int i = 0; i < n; i++) {
                    if(!(currstate & (1 << i))){
                        int nxtstate = currstate | (1 << i);
                        double returntime = time[n-1-i]*mul[currj];
                        double nxttime = currtime + returntime;
                        int nxtboat = 1 - boat;
                        int nxtj = (currj + (int)floor(returntime)) % m;

                        if(dp[nxtstate][nxtj][nxtboat] > nxttime) {
                            dp[nxtstate][nxtj][nxtboat] = nxttime;
                            pq.push({nxttime, (double)nxtstate,(double)nxtj, (double)nxtboat});
                        }
                    } 
                }
            }
            else {
                for(int submask=currstate;submask;submask=(submask-1)&currstate)
                {
                    int x = submask ^ currstate;
                    int c = __builtin_popcount(submask);

                    if(c > k) continue;

                    int nxtstate = currstate ^ submask;
                    
                    double maxitime = -1;
                    for(int i = 0; i < n; i++) {
                        if((submask & (1 << i))) {
                            maxitime = max(maxitime, (double)time[n-1-i]);
                        }
                    }

                    double gotime = maxitime*mul[currj];

                    int nxtj = (currj + (int)floor(gotime)) % m;

                    double nxttime = currtime + gotime;

                    int nxtboat = 1 - boat;

                    if(dp[nxtstate][nxtj][nxtboat] > nxttime) {
                        dp[nxtstate][nxtj][nxtboat] = nxttime;
                        pq.push({nxttime,(double)nxtstate,(double)nxtj,(double)nxtboat});
                    }
                }
            }
        }
        
        double ans = 1e18;

        for(int i = 0; i < m; i++) {
            ans = min(ans, dp[0][i][0]);
        }

        return ans == 1e18 ? -1.0 : ans;
    }
};