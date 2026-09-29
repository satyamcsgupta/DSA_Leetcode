class Solution {
public:
    int dp[100][100][201];

    bool path(vector<vector<char>>& grid, int i, int j, int count) {

        int m = grid.size();
        int n = grid[0].size();

        // Out of bounds
        if (i >= m || j >= n)
            return false;

        // Process current character
        if (grid[i][j] == '(')
            count++;
        else
            count--;

        // Invalid balance
        if (count < 0)
            return false;

        // Not enough cells remaining to close all '('
        int remaining = (m - 1 - i) + (n - 1 - j);

        if (count > remaining)
            return false;

        // Destination
        if (i == m - 1 && j == n - 1)
            return count == 0;

        // Memoization
        if (dp[i][j][count] != -1)
            return dp[i][j][count];

        // Down OR Right
        return dp[i][j][count] =
            path(grid, i + 1, j, count) ||
            path(grid, i, j + 1, count);
    }

    bool hasValidPath(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        // Path length must be even
        if ((m + n - 1) % 2 != 0)
            return false;

        // Must start with '('
        if (grid[0][0] == ')')
            return false;

        memset(dp, -1, sizeof(dp));

        return path(grid, 0, 0, 0);
    }
};