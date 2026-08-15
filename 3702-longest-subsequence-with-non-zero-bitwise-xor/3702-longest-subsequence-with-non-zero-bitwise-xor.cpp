class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        
        int n = nums.size();
        int totalXOR = 0;
        bool hasNonZero = false;

        for (int x : nums) {
            totalXOR ^= x;

            if (x != 0) {
                hasNonZero = true;
            }
        }

        // Case 1: Whole array has non-zero XOR
        if (totalXOR != 0) {
            return n;
        }

        // Case 2: Whole array XOR is 0,
        // but there is at least one non-zero element
        if (hasNonZero) {
            return n - 1;
        }

        // Case 3: Every element is 0
        return 0;
    }
};