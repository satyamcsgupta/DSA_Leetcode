class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {

            vector<int> count(26, 0);
            int max_count = 0;

            for (int j = i; j < n; j++) {

                // Add current character
                count[s[j] - 'a']++;

                // Update maximum frequency
                max_count = max(max_count, count[s[j] - 'a']);

                // Find minimum NON-ZERO frequency
                int min_count = n + 1;

                for (int k = 0; k < 26; k++) {
                    if (count[k] > 0) {
                        min_count = min(min_count, count[k]);
                    }
                }

                // Add beauty of current substring
                ans += max_count - min_count;
            }
        }

        return ans;
    }
};