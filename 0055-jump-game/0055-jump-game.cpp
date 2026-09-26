class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maximum = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++) {

            // I cannot even reach this index
            if(i > maximum) {
                return false;
            }

            // Extend my maximum reachable position
            maximum = max(maximum, i + nums[i]);

            // Last index is reachable
            if(maximum >= n - 1) {
                return true;
            }
        }

        return false;
    }
};