class Solution {
public:
const int mod = 1e9+ 7;
vector<vector<long long>> multiply(vector<vector<long long>>&a, vector<vector<long long>>&b) {
    int n = a.size();
    vector<vector<long long>>c(n, vector<long long>(n ,0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                c[i][j] = (c[i][j] + (a[i][k] * b[k][j]) % mod) % mod;
            }
        }
    }

    return c;
}

vector<vector<long long>>power(vector<vector<long long>>&base, int e) {
    int n = base.size();
    int m = base[0].size();
    vector<vector<long long>>res(n, vector<long long>(m, 0));

    for(int i = 0; i < n && i < m; i++) {
        res[i][i] = 1;
    }

    while(e > 0) {
        if(e & 1) res = multiply(res, base);
        e = e >> 1;
        base = multiply(base, base);
    }

    return res;
}

    int countVowelPermutation(int n) {
        
        vector<vector<long long>>T = {{0, 1, 0, 0, 0},
                       {1, 0, 1, 0, 0},
                       {1, 1, 0, 1, 1},
                       {0, 0, 1, 0, 1},
                       {1, 0, 0, 0, 0}};

        
        vector<vector<long long>>res = power(T, n - 1);

        long long ans = 0;
        for(int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                ans = (ans + res[i][j]) % mod;
            }
        }

        return ans;
    }
};