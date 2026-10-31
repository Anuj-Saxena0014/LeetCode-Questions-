class Solution {
public:
    int MOD = 1e9 + 7;
    int m, n;
    int solve(vector<vector<int>>& grid, int i, int j,
              int dir, vector<vector<vector<int>>>& dp){

        if(i >= m || j >= n)
            return 0;

        if(i == m-1 && j == n-1)
            return 1;

        if(dp[i][j][dir] != -1)
            return dp[i][j][dir];

        if(grid[i][j] == 1) {
            if(dir == 0)
                return dp[i][j][dir] = solve(grid, i+1, j, 1, dp);

            return dp[i][j][dir] = solve(grid, i, j+1, 0, dp);
        }

        int right = solve(grid, i, j+1, 0, dp);
        int down = solve(grid, i+1, j, 1, dp);

        return dp[i][j][dir] = (right + down) % MOD;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(2, -1))
        );

        return solve(grid, 0, 0, 0, dp);
    }
};