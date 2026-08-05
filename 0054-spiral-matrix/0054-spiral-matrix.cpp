class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& nums) {

        int m = nums.size();
        int n = nums[0].size();

        vector<int> ans;

        int top = 0;
        int bottom = m - 1;
        int left = 0;
        int right = n - 1;

        while (top <= bottom && left <= right) {

            // 1. Left -> Right
            for (int i = left; i <= right; i++) {
                ans.push_back(nums[top][i]);
            }
            top++;

            // 2. Top -> Bottom
            for (int i = top; i <= bottom; i++) {
                ans.push_back(nums[i][right]);
            }
            right--;

            // 3. Right -> Left
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    ans.push_back(nums[bottom][i]);
                }
                bottom--;
            }

            // 4. Bottom -> Top
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(nums[i][left]);
                }
                left++;
            }
        }

        return ans;
    }
};