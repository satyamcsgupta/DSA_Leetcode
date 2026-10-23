class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();

        // If already sorted, answer is 0
        bool sorted = true;
        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                sorted = false;
                break;
            }
        }

        if (sorted) return 0;

        // AND of all misplaced elements
        int ans = -1;

        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                if (ans == -1)
                    ans = nums[i];
                else
                    ans &= nums[i];
            }
        }

        return ans;
    }
};