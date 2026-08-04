class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;

        // Store all numbers in the set
        for (int num : nums) {
            st.insert(num);
        }

        int longest = 0;

        // Check every number
        for (int num : st) {

            // Start counting only if this is the beginning of a sequence
            if (st.find(num - 1) == st.end()) {

                int currentNum = num;
                int currentLength = 1;

                // Count the consecutive numbers
                while (st.find(currentNum + 1) != st.end()) {
                    currentNum++;
                    currentLength++;
                }

                longest = max(longest, currentLength);
            }
        }

        return longest;
    }
};