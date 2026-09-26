class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int>> ans(n, vector<int>(n, 0));

        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = n - 1;

        int value = 1;

        while (top <= bottom && left <= right) {

            // 1. Top row → 
            for (int j = left; j <= right; j++) {
                ans[top][j] = value++;
            }
            top++;

            // 2. Right column ↓
            for (int i = top; i <= bottom; i++) {
                ans[i][right] = value++;
            }
            right--;

            // 3. Bottom row ←
            for (int j = right; j >= left; j--) {
                ans[bottom][j] = value++;
            }
            bottom--;

            // 4. Left column ↑
            for (int i = bottom; i >= top; i--) {
                ans[i][left] = value++;
            }
            left++;
        }

        return ans;
    }
};