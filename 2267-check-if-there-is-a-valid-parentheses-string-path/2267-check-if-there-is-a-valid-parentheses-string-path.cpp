class Solution {
public:
    int n, m;
    vector<vector<vector<int>>> dp;

    bool solve(vector<vector<char>>& grid, int i, int j, int count) {
        if (i >= n || j >= m) return false;

        if (i == n - 1 && j == m - 1) {
            if (grid[i][j] == '(') return false;
            return count == 1; 
        }
        
        if (dp[i][j][count] != -1) return dp[i][j][count];
        int next_count = count;
        if (grid[i][j] == '(') {
            next_count++;
        } else {
            if (next_count > 0) next_count--;
            else return false;
        }

        bool ans1 = solve(grid, i + 1, j, next_count);
        bool ans2 = solve(grid, i, j + 1, next_count);

        return dp[i][j][count] = ans1 || ans2;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(n + m, -1)));
        
        return solve(grid, 0, 0, 0);
    }
};