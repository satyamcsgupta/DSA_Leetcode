class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        int rows = mat.size();
        int cols = mat[0].size();

        int low = 0;
        int high = cols - 1;

        while (low <= high) {

            // Middle column
            int mid = low + (high - low) / 2;

            // Find maximum element in this column
            int maxRow = 0;

            for (int row = 1; row < rows; row++) {
                if (mat[row][mid] > mat[maxRow][mid]) {
                    maxRow = row;
                }
            }

            int current = mat[maxRow][mid];

            // Check left and right neighbors
            int left = (mid > 0) ? mat[maxRow][mid - 1] : -1;
            int right = (mid < cols - 1) ? mat[maxRow][mid + 1] : -1;

            // Current element is a peak
            if (current > left && current > right) {
                return {maxRow, mid};
            }

            // Bigger element is on the left
            if (left > current) {
                high = mid - 1;
            }
            // Bigger element is on the right
            else {
                low = mid + 1;
            }
        }

        return {-1, -1};
    }
};