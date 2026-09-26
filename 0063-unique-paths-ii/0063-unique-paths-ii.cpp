class Solution {
public:

    int solve(int r, int c, vector<vector<int>>& grid,
              vector<vector<int>>& dp) {

        int m = grid.size();
        int n = grid[0].size();

        // Outside the grid
        if(r >= m || c >= n)
            return 0;

        // Obstacle
        if(grid[r][c] == 1)
            return 0;

        // Destination
        if(r == m - 1 && c == n - 1)
            return 1;

        // Already calculated
        if(dp[r][c] != -1)
            return dp[r][c];

        // Move right
        int right = solve(r, c + 1, grid, dp);

        // Move down
        int down = solve(r + 1, c, grid, dp);

        return dp[r][c] = right + down;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(0, 0, obstacleGrid, dp);
    }
};